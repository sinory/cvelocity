%{
#include<stdio.h>
/**
 实现了set，ref
 */
extern int yylex();
int i = 0;
%}
%option noyywrap yylineno

%x REF DIRECTIVE
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
<REF,DIRECTIVE>"$"|"$!"/"{"?{VAR_NAME} {printf("$:%s\n",yytext);}
<REF,DIRECTIVE>"{" {printf("{:%s\n",yytext);}
<DIRECTIVE>"}" {printf("}:%s\n",yytext);}
<REF,DIRECTIVE>{VAR_NAME}/[ /t}] {printf("ref name:%s\n",yytext);}
<REF>[ /t"=""}"\n] {BEGIN INITIAL; printf("ref end:%s\n",yytext);}

    /**他会尽可能长的去匹配，这个地方不去除$会匹配REF状态,后面添加了一个[^#]是防止匹配注释*/
[^$]*?/"#" {
                 BEGIN DIRECTIVE;
                 printf("begin directive text:%hhd,length:%zd\n",yytext[yyleng-1],yyleng);
        }
<DIRECTIVE>"#" {printf("#:%s\n",yytext);}
<DIRECTIVE>"set"/[ /t]*"(" {printf("set:%s\n",yytext);}
<DIRECTIVE>"(" {printf("(:%s\n",yytext);}
<DIRECTIVE>"=" {printf("=:%s\n",yytext);}
<DIRECTIVE>"+" {printf("add:%s\n",yytext);}
<DIRECTIVE>"-" {printf("sub:%s\n",yytext);}
<DIRECTIVE>"*" {printf("mul:%s\n",yytext);}
<DIRECTIVE>"/" {printf("div:%s\n",yytext);}
<DIRECTIVE>{INTEGER} {printf("integer:%s\n",yytext);}
<DIRECTIVE>")"[ /t]*[/n]? {BEGIN INITIAL; printf("):%s\n",yytext);}
<DIRECTIVE>{STRING} {printf("string:%s\n",yytext);}

<DIRECTIVE>"if"/[ /t]*"(" {printf("if:%s\n",yytext);}


<<EOF>> {printf("lex end %d:%s\n",i++,yytext);yyterminate();}

%%
int main(){
    FILE *src;
    src = fopen("test.vm","r");
    yyin = src;
    int result = yylex();
    fclose(src);
    return result;
}