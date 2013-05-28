%{
/**老版本，问题比较多，留作纪念*/
#include<stdio.h>
#include "context.h"
#include "bool.h"
#include "vtl4.tab.h"
%}
%option noyywrap nodefault yylineno

/*
    REF the begin of a reference
    DIRECTIVE the begin of a directive 
*/
%x REF DIRECTIVE
VAR_NAME ([_a-zA-Z]+[a-zA-Z0-9_\-]*)
WHITESPACE ([ \t]*)
INTEGER ([1-9]+[0-9]*)
STRING (\"[0-9.]*?\")
DOUBLE ([0-9]+"."[0-9]*([Ee][-+]?[0-9]+)?)
ESC (\\)+?
SINGLE_COMMENT ("##".*?\n)
MUL_COMMENT ("#*"[.\n]*?"*#")
%%

<*>{SINGLE_COMMENT} {yylval.string = yytext; return SINGLE_LINE_COMMENT;}
<*>{MUL_COMMENT} {yylval.string = yytext; return MULTI_LINE_COMMENT;}

[\n]* {printf("TTTTTTTTTTTText!");yylval.string = yytext; return CONTENT;}

[.]*?/"$" {printf("begin ref\n"); BEGIN REF;yylval.string = yytext; return CONTENT;}
<REF,DIRECTIVE>("$"|("!$"))/[{a-zA-Z_] {printf("$:%s\n",yytext); return DOLLAR;}
<REF>{VAR_NAME} {printf("ref name:%s\n",yytext);yylval.sym = find_symbol(yytext); return ID;}
<REF>[} \t\n] {printf("end ref\n");BEGIN INITIAL;}

[^\$]*?/"#" {BEGIN DIRECTIVE;yylval.string = yytext; return CONTENT;}
<DIRECTIVE>"#" {printf("#:%s",yytext);return HASH;}
<DIRECTIVE>set {return SET;}
<DIRECTIVE>[(] {return PARENTHESIS;}
<DIRECTIVE>{VAR_NAME}/[ /t}=] {printf("ref name:%s\n",yytext);yylval.sym = find_symbol(yytext); return ID;}
<DIRECTIVE>[=] {return EQUAL;}
<DIRECTIVE>[+] {return ADD;}
<DIRECTIVE>[-] {return SUB;}
<DIRECTIVE>[*] {return MUL;}
<DIRECTIVE>[/] {return DIV;}
<DIRECTIVE>"||" {return OR;}
<DIRECTIVE>"&&" {return AND;}
<DIRECTIVE>[%] {return MOD;}
<DIRECTIVE>{INTEGER} {return INTEGER_LITERAL;}
<DIRECTIVE>{DOUBLE} {yylval.d = atof(yytext); return DOUBLE_LITERAL;}
<DIRECTIVE>{STRING} {yylval.string = yytext; return STRING_LITERAL;}
<DIRECTIVE>(true)|(false) {yylval.d = get_bool_value(yytext) ;return BOOL;}
<DIRECTIVE>[ /t] {}
<DIRECTIVE>([)][ /t]*\n) {BEGIN INITIAL; return CLOSE_PARENTHESIS;}

<<EOF>> {printf("EOF\n");return LEX_EOF;}
%%