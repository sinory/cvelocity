%{
    /**支持了所有的token,不支持转义和多行注释*/
#include<stdio.h>
#include<string.h>
    extern int yylex();
    int i = 0;
    /**bracket标志*/
    int bracket_flag = 0;
    /**引用标志*/
    int ref_flag = 0;
    /**多行注释标记*/
    int mul_comment_flag = 0;
%}
%option noyywrap yylineno
%option stack

%x REF DIRECTIVE BLOCK
VAR_NAME ([_a-zA-Z]+[a-zA-Z0-9_\-]*)
INTEGER ([0-9]*)
STRING (\"[^"]*?\")|(\'[^']*?\')
WHITESPACE ([ \t]*)
OPERATOR ([+-*\%])
SINGLE_COMMENT ("##".*?\n)
%%
    /**处理单行注释*/
<DIRECTIVE>{SINGLE_COMMENT} {yy_pop_state();printf("single comment for directive end:%s\n",yytext);}

    /**这里去除$#\n防止覆盖状态REF和DIRECTIVE*/
[^$\n#]*? {printf("text:%s\n",yytext);}
    /**换行单独取出来，还没清楚为什么*/
\n {printf("newLine:%s\n",yytext);}

    /**添加^$防止只匹配最后一个变量
 例如：<p class="$b">$a $b</p> 只匹配了最后一个$b
 */
[^#$]*?/"$" {yy_push_state(REF);printf("begin ref text:%s\n",yytext);printf("===================%d=============\n",yy_top_state());}

<REF,DIRECTIVE>"$"|"$!"/"{"?{VAR_NAME} {printf("===================%d=============\n",yy_top_state());ref_flag++;printf("$:%s\n",yytext);}
<REF,DIRECTIVE>"{" {printf("{:%s\n",yytext);}
<DIRECTIVE>"}" {printf("}:%s\n",yytext);}
<REF,DIRECTIVE>{VAR_NAME}/[^0-9A-Za-z_\-] {
    printf("===================%d=============\n",yy_top_state());
//    if(yy_top_state()==REF){
//        printf("===================top:ref======================");
//    }else if(yy_top_state()==DIRECTIVE){
//        printf("===================top:DIRECTIVE======================");
//    }else {
//        printf("===================top:0======================");
//    }
    if(ref_flag==1){
        printf("ref name:%s\n",yytext);
        ref_flag--;
    }else {
        printf("======from var_name:%s====",yytext);
        if(strcmp(yytext,"set")==0){
            printf("set:%s\n",yytext);
        }
        else if(strcmp(yytext,"parse")==0){
            printf("parse:%s\n",yytext);
        }else if(strcmp(yytext,"if")==0){
            printf("if:%s\n",yytext);
        }else if(strcmp(yytext,"else")==0){
            printf("Link directive end else:%s\n",yytext);
            yy_pop_state();
        }else if(strcmp(yytext,"elseif")==0){
            printf("elseif:%s\n",yytext);
        }else if(strcmp(yytext,"foreach")==0){
            printf("foreach:%s\n",yytext);
        }else if(strcmp(yytext,"end")==0){
            printf("Link directive end end:%s\n",yytext);
            yy_pop_state();
        }else if(strcmp(yytext,"in")==0){
            printf("in:%s\n",yytext);
        }else {
            printf("text:%s\n",yytext);
        }
    }
}
<REF>[ /t"=""}"\n] {yy_pop_state(); printf("ref end:%s\n",yytext);}

    /**他会尽可能长的去匹配，这个地方不去除$会匹配REF状态,去除#和匹配变量的开始部分是一个道理*/
[^$#]*?/"#"[^"*" \t\n] {
yy_push_state(DIRECTIVE);
printf("begin directive text:%s\n",yytext);
}

<DIRECTIVE>"#" {printf("#:%s\n",yytext);}
<DIRECTIVE>"(" {bracket_flag++;printf("(:%s\n",yytext);}
<DIRECTIVE>"=" {printf("=:%s\n",yytext);}
<DIRECTIVE>"==" {printf("==:%s\n",yytext);}
<DIRECTIVE>"+" {printf("add:%s\n",yytext);}
<DIRECTIVE>"-" {printf("sub:%s\n",yytext);}
<DIRECTIVE>"*" {printf("mul:%s\n",yytext);}
<DIRECTIVE>"/" {printf("div:%s\n",yytext);}
<DIRECTIVE>{INTEGER} {printf("integer:%s\n",yytext);}
<DIRECTIVE>{STRING} {printf("string:%s\n",yytext);}
<DIRECTIVE>")" {if(--bracket_flag==0){yy_pop_state(); printf("Link directive end ):%s\n",yytext);}}

<<EOF>> {printf("lex end:%s\n",yytext);yyterminate();}

%%
int main(){
    printf("===============================================================\n");
    FILE *src;
    src = fopen("test.vm","r");
    yyin = src;
    int result = yylex();
    fclose(src);
    return result;
}