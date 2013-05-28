%{
    #include<stdio.h>
    #include<string.h>
    #include "context.h"
    #include "bool.h"
    #include "vtl4.tab.h"
%}
INT ([0-9]*)
%%
{INT} {return INTEGER;}
">" {return yytext[0];}
"(" {return yytext[0];}
")" {return yytext[0];}
"in" {return IN;}
"#foreach" {return FOREACH;}
"#end" {return END;}
"#if" {return IF;}
"#else" {return ELSE;}
"#elseif" {return ELSEIF;}
[^ \t] {yylval.string = yytext;return CONTENT;}
[ \t] {}
%%
