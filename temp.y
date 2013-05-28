%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "bool.h"
    #include "parser.h"
    #include "context.h"
    #include "vtl4.tab.h"

    extern FILE * yyin;
    extern FILE * yyout;
    extern int yylex();
    extern int yywrap();
    %}

%union {
    struct simpleNode *ast;
    double d;
    int i;
    bool b;
    char* string;
    struct symbol *sym;
}

%token <string> CONTENT NAME

%token IF ELSEIF ELSE END HASH DOLLAR PARENTHESIS PARENTHESIS_CLOSE LOGIC_EQUAL NEWLINE

%type <ast> stmts stmt

%%
stmts
: stmt{printf("stmt\n");}
| stmts stmt{printf("stmts stmt\n");}
;

stmt:CONTENT {printf("content\n");}
|NEWLINE {printf("NEWLINE\n");}
|directive {printf("directive\n");}
;

directive:foreach {printf("foreach\n");}
;

foreach: FOREACH '(' cond ')' stmts END {printf("foreach\n");}
;

cond:INTEGER '>' INTEGER {printf("cond\n");}
;


%%
int main(){
    FILE *src;
    src = fopen("test.vm","r");
    yyin = src;
    yyparse();
    fclose(src);
    return 1;
}

int yywrap(){
    return 1;
}










<DIRECTIVE>[ \t] {}