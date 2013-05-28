%{
    /**支持了所有的token,不支持转义和多行注释*/
#include<stdio.h>
#include<string.h>
#include "context.h"
#include "bool.h"
#include "vtl4.tab.h"
    
extern int yylex();
    /**bracket标志*/
int bracket_flag = 0;
    /**引用标志*/
int ref_flag = 0;
    /**多行注释标记*/
int mul_comment_flag = 0;
%}
%option stack
%option noyywrap yylineno

%x REF DIRECTIVE
VAR_NAME ([_a-zA-Z]+[a-zA-Z0-9_\-]*)
INTEGER ([0-9]*)
DOUBLE ([0-9]+"."[0-9]*([Ee][-+]?[0-9]+)?)
STRING (\"[^"]*?\")|(\'[^']*?\')
WHITESPACE ([ \t]*)
OPERATOR ([+-*\%])
SINGLE_COMMENT ("##".*?\n)
%%
    /**处理单行注释*/
<DIRECTIVE>{SINGLE_COMMENT} {
    BEGIN INITIAL;
    printf("single comment for directive end:%s\n",yytext);
    yylval.string = yytext;
    return SINGLE_LINE_COMMENT;
}

    /**这里去除$#\n防止覆盖状态REF和DIRECTIVE*/
[^$\n#]*? {printf("text:%s\n",yytext);yylval.string = yytext; return CONTENT;}
    /**换行单独取出来，还没清楚为什么*/
\n {printf("newLine:%s\n",yytext);yylval.string = yytext; return CONTENT;}

    /**添加^$防止只匹配最后一个变量
     例如：<p class="$b">$a $b</p> 只匹配了最后一个$b
     添加^#优先进入DIRECTIVE状态
     */
[^#$]*?/"$" {BEGIN REF;printf("begin ref text:%s\n",yytext);yylval.string = yytext; return CONTENT;}

<REF,DIRECTIVE>"$"|"$!"/"{"?{VAR_NAME} {ref_flag++;printf("$:%s\n",yytext);return DOLLAR;}
<REF,DIRECTIVE>"{" {printf("{:%s\n",yytext);return BRACE;}
<DIRECTIVE>"}" {printf("}:%s\n",yytext);return BRACE_CLOSE;}
<REF,DIRECTIVE>{VAR_NAME}/[^0-9A-Za-z_\-] {
    if(ref_flag==1){
        printf("ref name:%s\n",yytext);
        ref_flag--;
        yylval.sym = find_symbol(yytext);
        return ID;
    }else {
        printf("======from var_name:%s====",yytext);
        if(strcmp(yytext,"set")==0){
            printf("set:%s\n",yytext);
            return SET;
        }
        else if(strcmp(yytext,"parse")==0){
            printf("parse:%s\n",yytext);
            return PARSE;
        }else if(strcmp(yytext,"if")==0){
            printf("if:%s\n",yytext);
            return IF;
        }else if(strcmp(yytext,"else")==0){
            printf("Link directive end else:%s\n",yytext);
            BEGIN INITIAL;
            return ELSE;
        }else if(strcmp(yytext,"elseif")==0){
            printf("elseif:%s\n",yytext);
            return ELSEIF;
        }else if(strcmp(yytext,"foreach")==0){
            printf("foreach:%s\n",yytext);
            return FOREACH;
        }else if(strcmp(yytext,"end")==0){
            printf("Link directive end end:%s\n",yytext);
            BEGIN INITIAL;
            return END;
        }else if(strcmp(yytext,"in")==0){
            printf("in:%s\n",yytext);
            return IN;
        }else {
            printf("text:%s\n",yytext);
            yylval.string = yytext; return CONTENT;
        }
    }
}
<REF>[ /t"="\n] {BEGIN INITIAL; printf("ref end:%s\n",yytext);}
<REF>[}] {printf("}:%s\n",yytext);return BRACE_CLOSE;}

    /**他会尽可能长的去匹配，这个地方不去除$会匹配REF状态,去除#和匹配变量的开始部分是一个道理*/
[^$#]*?/"#"[^"*" \t\n] {
    BEGIN DIRECTIVE;
    printf("begin directive text:%s\n",yytext);
    yylval.string = yytext; return CONTENT;
}

<DIRECTIVE>"#" {printf("#:%s\n",yytext);}
<DIRECTIVE>"(" {bracket_flag++;printf("(:%s\n",yytext);return PARENTHESIS;}
<DIRECTIVE>"=" {printf("=:%s\n",yytext);return EQUAL;}
<DIRECTIVE>"+" {printf("add:%s\n",yytext);return ADD;}
<DIRECTIVE>"-" {printf("sub:%s\n",yytext);return SUB;}
<DIRECTIVE>"*" {printf("mul:%s\n",yytext);return MUL;}
<DIRECTIVE>"/" {printf("div:%s\n",yytext);return DIV;}
<DIRECTIVE>"%" {return MOD;}

<DIRECTIVE>"||" {return LOGICAL_OR;}
<DIRECTIVE>"&&" {return LOGICAL_AND;}
<DIRECTIVE>"==" {return LOGIC_EQUAL;}
<DIRECTIVE>"<" {return LOGICAL_LT;}
<DIRECTIVE>"<=" {return LOGICAL_LE;}
<DIRECTIVE>">" {return LOGICAL_GT;}
<DIRECTIVE>">=" {return LOGICAL_GE;}

<DIRECTIVE>{INTEGER} {printf("integer:%s\n",yytext);return INTEGER_LITERAL;}
<DIRECTIVE>{DOUBLE} {printf("string:%s\n",yytext);yylval.d = atof(yytext); return DOUBLE_LITERAL;}
<DIRECTIVE>{STRING} {yylval.string = yytext; return STRING_LITERAL;}
<DIRECTIVE>(true)|(false) {yylval.d = get_bool_value(yytext);return BOOL;}
<DIRECTIVE>")" {
    if(--bracket_flag==0){
        BEGIN INITIAL;
        printf("Link directive end ):%s\n",yytext);
        return CLOSE_PARENTHESIS;
    }
}

<<EOF>> {printf("lex end:%s\n",yytext);return LEX_EOF;}
%%