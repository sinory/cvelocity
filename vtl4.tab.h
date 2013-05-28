/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CONTENT = 258,
     PARENTHESIS = 259,
     CLOSE_PARENTHESIS = 260,
     BRACKET = 261,
     CLOSE_BRACKET = 262,
     COMMA = 263,
     RANGE = 264,
     BRACE = 265,
     CLOSE_BRACE = 266,
     COLON = 267,
     IN = 268,
     FOREACH = 269,
     SET = 270,
     PARSE = 271,
     IF = 272,
     ELSEIF = 273,
     ELSE = 274,
     END = 275,
     DOLLARID = 276,
     DOTID = 277,
     STRING_LITERAL = 278,
     COMMENT = 279,
     MUL_COMMENT = 280,
     CONSTANT = 281,
     INTEGER_LITERAL = 282,
     LOGICAL_AND = 283,
     LOGICAL_OR = 284,
     LOGIC_EQUAL = 285,
     LOGICAL_LT = 286,
     LOGICAL_LE = 287,
     LOGICAL_GT = 288,
     LOGICAL_GE = 289,
     LOGICAL_NOT_EQUALS = 290,
     ADD = 291,
     SUB = 292,
     MUL = 293,
     DIV = 294,
     MOD = 295,
     EQUAL = 296,
     UMINUS = 297
   };
#endif
/* Tokens.  */
#define CONTENT 258
#define PARENTHESIS 259
#define CLOSE_PARENTHESIS 260
#define BRACKET 261
#define CLOSE_BRACKET 262
#define COMMA 263
#define RANGE 264
#define BRACE 265
#define CLOSE_BRACE 266
#define COLON 267
#define IN 268
#define FOREACH 269
#define SET 270
#define PARSE 271
#define IF 272
#define ELSEIF 273
#define ELSE 274
#define END 275
#define DOLLARID 276
#define DOTID 277
#define STRING_LITERAL 278
#define COMMENT 279
#define MUL_COMMENT 280
#define CONSTANT 281
#define INTEGER_LITERAL 282
#define LOGICAL_AND 283
#define LOGICAL_OR 284
#define LOGIC_EQUAL 285
#define LOGICAL_LT 286
#define LOGICAL_LE 287
#define LOGICAL_GT 288
#define LOGICAL_GE 289
#define LOGICAL_NOT_EQUALS 290
#define ADD 291
#define SUB 292
#define MUL 293
#define DIV 294
#define MOD 295
#define EQUAL 296
#define UMINUS 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "vtl4.y"
{
    struct simpleNode *ast;
    double d;
    int i;
    bool b;
    char* string;
    struct symbol *sym;
}
/* Line 1529 of yacc.c.  */
#line 142 "vtl4.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

