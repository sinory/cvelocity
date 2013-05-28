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

%token <string> CONTENT

%token IF ELSEIF ELSE END HASH DOLLAR PARENTHESIS PARENTHESIS_CLOSE LOGIC_EQUAL NEWLINE GL
%token FOREACH
%type <ast> root stmts stmt directive reference word expression if elseif else
%token <string> ID IN INTEGER
%nonassoc IF
%nonassoc ELSEIF
%nonassoc ELSE

%left '>'

%%
root:stmts {
    //$$=process($1);
}
;

stmts:stmt {$$ = $1;}
| stmts stmt{$$ = add_ybrother($1,$2);}
;

stmt:CONTENT {$$ = text($1);}
|directive {printf("stmt ---directive\n");$$ = $1;}
|reference {printf("stmt ---reference\n");$$ = $1;}
;

directive:FOREACH '(' reference word reference ')' stmts END {printf("directive ---foreach\n");$$ = foreach_directive($3,$4,$5,$7);}
|if {printf("directive ---if\n");$$=$1;}
;

reference: ID {printf("reference ---Id\n");reference($1);}

word:IN {$$ = word($1);}

if:IF '(' expression ')' stmts END {printf("if\n");$$ = if_directive($3, $5, NULL,NULL);}
|IF '(' expression ')' stmts else END {printf("if else end\n");$$ = if_directive($3, $5,$6,NULL);}
|IF '(' expression ')' stmts elseif END {printf("if elseif end\n");$$ = if_directive($3, $5, $6, NULL);}
|IF '(' expression ')' stmts elseif else END {printf("if elseif ... else end\n");$$ = if_directive($3, $5, $6, $7);}
;

elseif:ELSEIF '(' expression ')' stmts {printf("one elseif\n");$$=elseif_directive($3,$5);}
|elseif elseif {printf("Mul elseif\n");$$ = add_ybrother($1,$2);}
;

else: ELSE stmts {$$ = else_directive($2);}

expression:expression '>' expression {printf("cond\n");$$ = math_logical_lt($1,$3);}
|INTEGER {printf("cond\n");integer_literal($1);}
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