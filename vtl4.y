%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include "bool.h"
    #include "parser.h"
    #include "context.h"
    #include "render.h"
    #include "vtl4.tab.h"
    #include "util.h"

    extern FILE * yyin;
    extern FILE * yyout;
    extern int yylex();
    extern int yywrap();
    extern int yy_scan_string(char* s);
    extern void yylex_destroy();
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

%token PARENTHESIS CLOSE_PARENTHESIS BRACKET CLOSE_BRACKET COMMA RANGE BRACE CLOSE_BRACE COLON IN
%token FOREACH SET PARSE IF ELSEIF ELSE END
%type <ast> root stmts stmt directive reference expression math if elseifs elseif else set parse literal simpleliteral stringliteral integerliteral array range param params map map_item map_items attributes attribute method index indexBody identifier foreach
%token <string> DOLLARID DOTID STRING_LITERAL COMMENT MUL_COMMENT CONSTANT

%token <d> INTEGER_LITERAL

    /**operator token*/
%token LOGICAL_AND LOGICAL_OR LOGIC_EQUAL LOGICAL_LT LOGICAL_LE LOGICAL_GT LOGICAL_GE LOGICAL_NOT_EQUALS ADD SUB MUL DIV MOD EQUAL

%nonassoc IF
%nonassoc ELSEIF
%nonassoc ELSE

%left LOGICAL_AND LOGICAL_OR LOGIC_EQUAL LOGICAL_LT LOGICAL_LE LOGICAL_GT LOGICAL_GE LOGICAL_NOT_EQUALS
%left ADD SUB
%left MUL DIV MOD
%nonassoc UMINUS

%%
root:stmts {
    $$=process($1);
    printf("----------------------- Begin to render1!-------------------------\n");
    traverse($$);
    free_tree($$);
    //printf("----------------------- Begin to render2!-------------------------\n");
    //traverse($$);
    //render($$,NULL);
    //printf("----------------------- End to render!-------------------------\n");
    }
;

stmts:stmt {$$ = $1;}
| stmts stmt {
    $$ = add_ybrother($1,$2);
    }
;

stmt:CONTENT {$$ = text($1);}
|directive {$$ = $1;}
|reference {printf("stmt ---reference\n");$$ = $1;}
|COMMENT {printf("stmt ---common\n");$$ = comment($1);}
|MUL_COMMENT {printf("stmt ---mul common\n");$$ = comment($1);}
;

directive:foreach {$$ = $1;}
|if {$$=$1;}
|set {$$=$1;}
|parse {$$=$1;}
;

foreach:FOREACH PARENTHESIS reference IN reference CLOSE_PARENTHESIS stmts END {$$ = foreach_directive($3,$5,$7);}
|FOREACH PARENTHESIS reference IN array CLOSE_PARENTHESIS stmts END {$$ = foreach_directive($3,$5,$7);}
;

reference: DOLLARID {$$ = reference($1, NULL);}
|DOLLARID attributes {$$ = reference($1, $2);}
|DOLLARID indexBody {$$ = reference_start_with_index($1,$2,NULL);}
|DOLLARID indexBody attributes {$$ = reference_start_with_index($1,$2,$3);}
;

attributes:attribute { $$ = $1; }
| attributes attribute { $$ = add_ybrother($1, $2);}
;

attribute:method {$$ = $1;}
|index {$$ = $1;}
|identifier {$$ = $1;}
;

method
:identifier PARENTHESIS params CLOSE_PARENTHESIS {$$ = method($1,$3);}
|identifier PARENTHESIS CLOSE_PARENTHESIS {$$ = method($1,NULL);}
;

index
:identifier indexBody { $$ = reference_index($1,$2); }
;

indexBody:BRACKET simpleliteral CLOSE_BRACKET {$$ = $2;}
|BRACKET reference CLOSE_BRACKET {$$ = $2;}
;

identifier:DOTID {$$ = identifier($1);}
;

if:IF PARENTHESIS expression CLOSE_PARENTHESIS stmts END {$$ = if_directive($3,$5,NULL,NULL);}
|IF PARENTHESIS expression CLOSE_PARENTHESIS stmts else END {$$ = if_directive($3,$5,NULL,$6);}
|IF PARENTHESIS expression CLOSE_PARENTHESIS stmts elseifs END {$$ = if_directive($3,$5,$6,NULL);}
|IF PARENTHESIS expression CLOSE_PARENTHESIS stmts elseifs else END {$$ = if_directive($3,$5,$6,$7);}
;

elseifs : elseif | elseifs elseif {$$ = add_ybrother($1,$2);}
;

elseif:ELSEIF PARENTHESIS expression CLOSE_PARENTHESIS stmts {$$ = elseif_directive($3,$5);}
;

else: ELSE stmts {$$ = else_directive($2);}
;

set:SET PARENTHESIS reference EQUAL expression CLOSE_PARENTHESIS {$$ = set_directive($3,$5); }
;

parse:PARSE PARENTHESIS stringliteral CLOSE_PARENTHESIS {$$ = parse_directive($3);}
;

expression:math {$$ = expression($1);}
|array {$$ = expression($1);}
|map {$$ = expression($1);}
;

stringliteral:STRING_LITERAL {$$ = string_literal($1);}
;


integerliteral: INTEGER_LITERAL {$$ =integer_literal($1);}
;

simpleliteral:stringliteral {$$ = $1;}
|integerliteral {printf("simpleliteral--integerliteral\n");$$ = $1;}
;

literal:simpleliteral {$$ = $1;}
|array {$$ = $1;}
|map {$$ = $1;}
;

math
: math ADD math {$$ = math_add($1,$3);}
| math SUB math {$$ = math_sub($1,$3);}
| math MUL math {$$ = math_mul($1,$3);}
| math DIV math {$$ = math_div($1,$3);}
| math MOD math {$$ = math_mod($1,$3);}
| SUB math %prec UMINUS {$$ = math_unary_uminus($2);}
| PARENTHESIS math CLOSE_PARENTHESIS {$$ = $2;}
| math LOGICAL_OR math {$$ = math_logical_or($1,$3);}
| math LOGICAL_AND math {$$ = math_logical_and($1,$3);}
| math LOGIC_EQUAL math {$$ = math_logical_equals($1,$3);}
| math LOGICAL_LT math {$$ = math_logical_lt($1,$3);}
| math LOGICAL_LE math {$$ = math_logical_le($1,$3);}
| math LOGICAL_GT math {$$ = math_logical_gt($1,$3);}
| math LOGICAL_GE math {$$ = math_logical_ge($1,$3);}
| math LOGICAL_NOT_EQUALS math {$$ = math_logical_not_equals($1,$3);}
| integerliteral {$$ =$1;}
| reference {printf("math:---reference\n");$$ = $1;}
| stringliteral {$$ = $1;}
;

array
: BRACKET params CLOSE_BRACKET { $$ = array($2); }
| range { $$ = array($1); }
| BRACKET CLOSE_BRACKET { $$ = array(NULL); }
;

range
: BRACKET integerliteral RANGE integerliteral CLOSE_BRACKET {$$ = range($2, $4);}
;

params:param {$$ = $1;}
|params COMMA param {$$ = add_ybrother($1, $3);}
;

param:literal {$$ = $1;}
|reference {$$ = $1;}
|CONSTANT {$$ = constant($1);}
;

map:BRACE map_items CLOSE_BRACE {$$ = map($2);}
|BRACE CLOSE_BRACE {$$ = map(NULL);}
;

map_items:map_item {$$ = $1;}
|map_items COMMA map_item {$$ = add_ybrother($1, $3);}
;

map_item:stringliteral COLON literal {$$ = map_item($1, $3);}
|stringliteral COLON reference {$$ = map_item($1, $3);}
;

%%
int main(){
    long start = clock();
    printf("================================================\n");
    FILE *src;

    src = fopen("test.vm","r");
   yyin = src;
    yyparse();
    fclose(src);
//    char* srcStr = fgets(src);
//     yy_scan_string("#set($a='')");
//    yyparse();
//    /* to avoid leakage */
//    yylex_destroy();

    printf("=====================cost %ld nanosecond========================\n",cost(start));
    return 1;
}

int yywrap(){
    return 1;
}