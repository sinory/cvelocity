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
int yylex();
extern int yywrap();
#define YYDEBUG 1
%}
    /*priority level*/
%union {
    struct simpleNode *ast;
    double d;
    int i;
    bool b;
    char* string;
    struct symbol *sym;
}

/*token list
    CMP
    ADD +
    SUB -
    MUL *
    DIV /
    MOD %
    OR  |
    AND &&
    UNARY_UMINUS -
    EQUAL =
    PARENTHESIS (
    CLOSE_PARENTHESIS ）
    EOF <<EOF>>
    CONTENT
    STRING_LITERAL
    INTEGER_LITERAL
    DOUBLE_LITERAL
    SINGLE_LINE_COMMENT
    MULTI_LINE_COMMENT
    DOLLAR $
    ID
    SET PARSE IF ELSE ELSEIF FOREACH IN(#foreach($a in $as))
    BRACE {
    BRACE_CLOSE }
    LOGIC_EQUAL ==
    LOGICAL_LT <
    LOGICAL_LE <=
    LOGICAL_GT >
    LOGICAL_GE >=
    LOGICAL_NOT_EQUALS !=
*/

%token ADD SUB MUL DIV MOD EQUAL PARENTHESIS CLOSE_PARENTHESIS BRACE BRACE_CLOSE LOGICAL_AND LOGICAL_OR LOGIC_EQUAL LOGICAL_LT LOGICAL_LE LOGICAL_GT LOGICAL_GE LOGICAL_NOT_EQUALS

%token  LEX_EOF

%token <string> CONTENT STRING_LITERAL SINGLE_LINE_COMMENT MULTI_LINE_COMMENT
%token <b> BOOL

%token INTEGER_LITERAL

%token <d> DOUBLE_LITERAL

%token DOLLAR

%token <sym> ID

%token HASH SET PARSE IF ELSE ELSEIF FOREACH IN END

%type <ast> root statements statement reference directive content comment set expression math literal number word foreach parse

%left LOGICAL_AND LOGICAL_OR LOGIC_EQUAL LOGICAL_LT LOGICAL_LE LOGICAL_GT LOGICAL_GE LOGICAL_NOT_EQUALS
%left ADD SUB
%left MUL DIV MOD
%nonassoc UMINUS

%nonassoc IF
%nonassoc ELSEIF
%nonassoc ELSE

%start root

%%
    /*JJTPROCESS*/
root:statements LEX_EOF {printf("yacc root\n");$$ = process($1);}
    ;

statements
    : statement {printf("yacc statements:statement\n"); $$ = $1; }
    | statements statement {printf("yacc statements:statements statement\n"); $$ = add_ybrother($1,$2);}
    ;
    
statement
    : reference {printf("yacc statement:ref\n"); $$ = $1;}
    | directive {printf("yacc statement:directive\n"); $$ = $1;}
    | content {printf("yacc statement:content\n"); $$ = $1;}
    | comment {printf("yacc statement:comment\n"); $$ = $1;}
    ;
  
directive
    : set { $$ = $1; }
    | foreach {$$ = $1;}
    | parse {$$ = $1;}
    ;
  
set
    : HASH SET PARENTHESIS reference EQUAL expression CLOSE_PARENTHESIS { $$ = set_directive($4,$6); }
    ;

foreach
    : HASH FOREACH PARENTHESIS reference word reference CLOSE_PARENTHESIS statements HASH END {printf("yacc statement:foreach\n");$$ = foreach_directive($4, $5, $6, $8);}
    ;

parse
    : HASH PARSE PARENTHESIS STRING_LITERAL CLOSE_PARENTHESIS {$$ = parse_directive(NULL);}
    ;

expression
    : math {$$ = expression($1);}
    ;

word
    : IN {printf("yacc statement:word\n");$$ = word();}
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
    | literal {$$ =$1;}
    | reference {$$ = $1;}
    ;

reference
    : DOLLAR ID {printf("yacc ref\n");$$ = reference($2);}
  ;

literal
    : number {printf("number\n");$$ = $1;}
    | STRING_LITERAL {printf("string\n");$$ = string_literal(NULL);}
    | BOOL {$$ = bool_literal($1);}
    ;

number
    : INTEGER_LITERAL {$$ = integer_literal(NULL);}
    | DOUBLE_LITERAL {$$ = double_literal();}
    ;
    
content
    : CONTENT {$$ = text(NULL);}
    ;
    
comment
    : SINGLE_LINE_COMMENT {printf("sigin_comment");$$ = comment(NULL);}
    ;
    
%%
int main(){
    printf("BEGIN:\n");
    FILE *src;
    src = fopen("test.vm","r");
    yyin = src;
    int result = yyparse();
    fclose(src);
    return result;
}
int yywrap(void) {
	yyin = NULL;
    yyout = NULL;
	return 1;
}