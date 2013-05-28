%{
    #include<stdio.h>
    #include<string.h>
    #include "context.h"
    #include "bool.h"
    #include "vtl4.tab.h"

    int bracket_flag = 0;
    
    int blank_close_flag = 0;
%}

INT ([0-9]*)
DOUBLE ([0-9]+"."[0-9]*([Ee][-+]?[0-9]+)?)
STRING (\"[^\'"\n#]*?\")|(\'[^\"'\n#]*?\')

ID  ([_a-zA-Z]+[a-zA-Z0-9_\-]*)
DOLLAR ("$"|("$!"))

DOLLAR_WITH_BRACE ((\$\{[ \t]*)|(\$\!\{[ \t]*))
ID_WITH_BRACE ([_a-zA-Z]+[a-zA-Z0-9_\-]*[ \t]*\})

DOT "."

SINGLE_COMMENT ("##".*?\n)
MUL_COMMENT    ("#*"([*]*[^*#]|[#])*"*#")

NULL ("null"|"NULL")

%x DIRECTIVE REFERENCE
%%
    
[^$#]*?/"#" {printf("==========begin directive flex content===content:%s=====\n",yytext);BEGIN DIRECTIVE;yylval.string = strdup(yytext); return CONTENT;}
<REFERENCE,DIRECTIVE>{INT} {yylval.d = atof(yytext);return INTEGER_LITERAL;}

<DIRECTIVE>"(" {printf("====== directive!bracket_flag=%d======",bracket_flag);bracket_flag++;return PARENTHESIS;}
<DIRECTIVE>")" {printf("======close directive!bracket_flag=%d======",bracket_flag);  if(--bracket_flag==0){BEGIN INITIAL; printf("======close directive!======");};return CLOSE_PARENTHESIS;}

<REFERENCE>"(" {blank_close_flag++;return PARENTHESIS;}
<REFERENCE>")" {blank_close_flag--;return CLOSE_PARENTHESIS;}

<REFERENCE,DIRECTIVE>"," {return COMMA;}
<REFERENCE,DIRECTIVE>"[" {blank_close_flag++;return BRACKET;}
<REFERENCE,DIRECTIVE>"]" {blank_close_flag--;return CLOSE_BRACKET;}

<DIRECTIVE>{SINGLE_COMMENT} {BEGIN INITIAL;
        printf("single comment for directive end:%s\n",yytext);yylval.string = strdup(yytext); return COMMENT;}
<DIRECTIVE>{MUL_COMMENT} {BEGIN INITIAL;yylval.string = strdup(yytext);return MUL_COMMENT;}
     /**<M_COMMENT>{MUL_COMMENT_CLOSE} {BEGIN INITIAL;yylval.string = strdup(yytext);return MUL_COMMENT;}*/
     /**<M_COMMENT>(.|\n)*?/"*#" {yylval.string = strdup(yytext);return MUL_COMMENT;}*/

<DIRECTIVE>".." {return RANGE;}
<DIRECTIVE>"{" {return BRACE;}
<DIRECTIVE>"}" {return CLOSE_BRACE;}
<DIRECTIVE>":" {return COLON;}
<DIRECTIVE>"in" {return IN;}
<DIRECTIVE>"#foreach" {return FOREACH;}
<DIRECTIVE>"#end" {BEGIN INITIAL;return END;}
<DIRECTIVE>"#if" {return IF;}
<DIRECTIVE>"#else" {BEGIN INITIAL;return ELSE;}
<DIRECTIVE>"#elseif" {return ELSEIF;}
<DIRECTIVE>"#set" {return SET;}
<DIRECTIVE>"#parse" {return PARSE;}

<DIRECTIVE>"=" {return EQUAL;}
<DIRECTIVE>"+" {return ADD;}
<DIRECTIVE>"-" {return SUB;}
<DIRECTIVE>"*" {return MUL;}
<DIRECTIVE>"/" {return DIV;}
<DIRECTIVE>"%" {return MOD;}
<DIRECTIVE>"||" {return LOGICAL_OR;}
<DIRECTIVE>"&&" {return LOGICAL_AND;}
<DIRECTIVE>"==" {return LOGIC_EQUAL;}
<DIRECTIVE>"!=" {return LOGICAL_NOT_EQUALS;}
<DIRECTIVE>"<" {return LOGICAL_LT;}
<DIRECTIVE>"<=" {return LOGICAL_LE;}
<DIRECTIVE>">" {return LOGICAL_GT;}
<DIRECTIVE>">=" {return LOGICAL_GE;}

[^#$]*?/"$" {BEGIN REFERENCE;yylval.string = strdup(yytext);printf("==========begin reference flex content===content:%s=====\n",yytext);return CONTENT;}

<REFERENCE,DIRECTIVE>{DOLLAR}{ID} {yylval.string = strdup(yytext);printf("==========flex content===ID:%s=====\n",yytext);return DOLLARID;}
<REFERENCE,DIRECTIVE>{DOT}{ID} {yylval.string = strdup(yytext);printf("==========flex content===DOTID:%s=====\n",yytext);return DOTID;}

<DIRECTIVE>{DOLLAR_WITH_BRACE}{ID_WITH_BRACE} {yylval.string = strdup(yytext);printf("==========flex content===ID:%s=====\n",yytext);return DOLLARID;}
<DIRECTIVE>{DOT}{ID_WITH_BRACE} {yylval.string = strdup(yytext);printf("==========flex content===DOTID:%s=====\n",yytext);return DOTID;}

<REFERENCE>{DOLLAR_WITH_BRACE}{ID_WITH_BRACE} {BEGIN INITIAL;yylval.string = strdup(yytext);printf("==========flex content===ID:%s=====\n",yytext);return DOLLARID;}
<REFERENCE>{DOT}{ID_WITH_BRACE} {BEGIN INITIAL;yylval.string = strdup(yytext);printf("==========flex content===DOTID:%s=====\n",yytext);return DOTID;}

<REFERENCE,DIRECTIVE>{STRING} {yylval.string = strdup(yytext); return STRING_LITERAL;}

<REFERENCE,DIRECTIVE>{NULL} {yylval.string = strdup(yytext);return CONSTANT;}

<REFERENCE>[ \t] {if(blank_close_flag==0){BEGIN INITIAL;printf("close reference content kongge:%s\n",yytext);yylval.string = strdup(yytext);return CONTENT;} }

<REFERENCE>[^_a-zA-Z ] {BEGIN INITIAL;printf("close reference content:%s\n",yytext);yylval.string = strdup(yytext);return CONTENT;}


[^#$]*? {yylval.string = strdup(yytext);printf("==========flex content===content:%s=====\n",yytext);return CONTENT;}

%%
