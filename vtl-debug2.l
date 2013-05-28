%{
/**基本的指令都可以识别了，但是无法区分文本等号和表达式=号（之类的记号）*/
#include<stdio.h>

extern int yylex();
int i = 0;
    /**bracket标志*/
int bracket_flag = 0;
    /**引用标志*/
int ref_flag = 0;
%}
%option noyywrap yylineno

%x REF DIRECTIVE_LINK DIRECTIVE_BLOCK
VAR_NAME ([_a-zA-Z]+[a-zA-Z0-9_\-]*)
INTEGER ([1-9]+[0-9]*)
STRING (\"[^"]*?\")|(\'[^']*?\')
WHITESPACE ([ \t]*)
OPERATOR ([+-*\%])
SINGLE_COMMENT ("##".*?\n)
MUL_COMMENT ("#*"[.\n]*?"*#")
%%

    /**这里去除$#\n防止覆盖状态REF和DIRECTIVE*/
[^$\n#]*? {printf("text:%s\n",yytext);}
    /**换行单独取出来，还没清楚为什么*/
\n {printf("newLine:%s\n",yytext);}


.*?/"$" {BEGIN REF;printf("begin ref text:%s\n",yytext);}
<REF,DIRECTIVE_LINK,DIRECTIVE_BLOCK>"$"|"$!"/"{"?{VAR_NAME} {ref_flag++;printf("$:%s\n",yytext);}
<REF,DIRECTIVE_LINK,DIRECTIVE_BLOCK>"{" {printf("{:%s\n",yytext);}
<DIRECTIVE_LINK,DIRECTIVE_BLOCK>"}" {printf("}:%s\n",yytext);}
<REF,DIRECTIVE_LINK,DIRECTIVE_BLOCK>{VAR_NAME}/[^0-9A-Za-z_\-] {if(ref_flag==1){printf("ref name:%s\n",yytext);ref_flag--;}else {printf("text:%s\n",yytext);}}
<REF>[ /t"=""}"\n] {BEGIN INITIAL; printf("ref end:%s\n",yytext);}

    /**他会尽可能长的去匹配，这个地方不去除$会匹配REF状态,后面添加了一个[^#]是防止匹配注释*/
[^$]*?/"#set" {
    BEGIN DIRECTIVE_LINK;
    printf("begin directive #set text:%s\n",yytext);
}
[^$]*?/"#parse" {
    BEGIN DIRECTIVE_LINK;
    printf("begin directive #parse text:%s\n",yytext);
}


    /**块状指令的开始*/
[^$]*?/"#if" {
    BEGIN DIRECTIVE_BLOCK;
    printf("begin directive #if text:%s\n",yytext);
}
[^$]*?/"#foreach" {
    BEGIN DIRECTIVE_BLOCK;
    printf("begin directive #foreach text:%s\n",yytext);
}



<DIRECTIVE_LINK,DIRECTIVE_BLOCK>"#" {printf("#:%s\n",yytext);}
    /**加这个[ /t]*"("防止被当做ref*/
<DIRECTIVE_LINK,DIRECTIVE_BLOCK>"set"/[ /t]*"(" {printf("set:%s\n",yytext);}

<DIRECTIVE_LINK,DIRECTIVE_BLOCK>"parse"/[ /t]*"(" {printf("parse:%s\n",yytext);}


<DIRECTIVE_LINK,DIRECTIVE_BLOCK>"(" {bracket_flag++;printf("(:%s\n",yytext);}
<DIRECTIVE_LINK,DIRECTIVE_BLOCK>"=" {printf("=:%s\n",yytext);}
<DIRECTIVE_LINK,DIRECTIVE_BLOCK>"==" {printf("==:%s\n",yytext);}
<DIRECTIVE_LINK,DIRECTIVE_BLOCK>"+" {printf("add:%s\n",yytext);}
<DIRECTIVE_LINK,DIRECTIVE_BLOCK>"-" {printf("sub:%s\n",yytext);}
<DIRECTIVE_LINK,DIRECTIVE_BLOCK>"*" {printf("mul:%s\n",yytext);}
<DIRECTIVE_LINK,DIRECTIVE_BLOCK>"/" {printf("div:%s\n",yytext);}
<DIRECTIVE_LINK,DIRECTIVE_BLOCK>{INTEGER} {printf("integer:%s\n",yytext);}
<DIRECTIVE_LINK,DIRECTIVE_BLOCK>{STRING} {printf("string:%s\n",yytext);}
<DIRECTIVE_LINK>")" {if(--bracket_flag==0){BEGIN INITIAL; printf("Link directive end ):%s\n",yytext);}}

    /**if/else/elseif*/
<DIRECTIVE_BLOCK>"if" {printf("if:%s\n",yytext);}
<DIRECTIVE_BLOCK>"elseif" {printf("elseif:%s\n",yytext);}
<DIRECTIVE_BLOCK>"else" {printf("else:%s\n",yytext);}

    /**foreach end*/
<DIRECTIVE_BLOCK>"foreach" {printf("foreach:%s\n",yytext);}
<DIRECTIVE_BLOCK>"in" {printf("foreach in:%s\n",yytext);}

    /**块状指令结束*/
<DIRECTIVE_BLOCK>"end"[ \t]*[\n]? {BEGIN INITIAL; printf("Block directive end:%s\n",yytext);}


<<EOF>> {printf("lex end:%s\n",yytext);yyterminate();}

%%
int main(){
    FILE *src;
    src = fopen("test.vm","r");
    yyin = src;
    int result = yylex();
    fclose(src);
    return result;
}