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

%token IF ELSEIF ELSE END HASH DOLLAR PARENTHESIS PARENTHESIS_CLOSE LOGIC_EQUAL NEWLINE INTEGER GL
%token FOREACH IN
%type <ast> stmts stmt

%nonassoc IF
%nonassoc ELSEIF
%nonassoc ELSE

%%
stmts
: stmt{}
| stmts stmt{}
;

stmt:CONTENT {}
|directive {printf("stmt ---directive\n");}
|INTEGER {}
;

directive:FOREACH '(' exp ')' stmts END {printf("directive ---foreach\n");}
|if {printf("directive ---if\n");}
;

if:IF '(' cond ')' stmts END {printf("if\n");}
|IF '(' cond ')' stmts ELSE stmts END {printf("if else end\n");}
|IF '(' cond ')' stmts elseif END {printf("if elseif end\n");}
|IF '(' cond ')' stmts elseif ELSE stmts END {printf("if elseif ... else end\n");}
;

elseif:ELSEIF '(' cond ')' stmts {printf("one elseif\n");}
|elseif elseif {printf("Mul elseif\n");}
;

cond:INTEGER '>' INTEGER {printf("cond\n");}

exp:INTEGER IN INTEGER {printf("exp\n");}


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