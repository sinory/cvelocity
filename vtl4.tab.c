/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "vtl4.y"

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 209 "vtl4.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 222 "vtl4.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   275

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    37,    46,    48,    51,    54,
      58,    60,    63,    65,    67,    69,    74,    78,    81,    85,
      89,    91,    98,   106,   114,   123,   125,   128,   134,   137,
     144,   149,   151,   153,   155,   157,   159,   161,   163,   165,
     167,   169,   173,   177,   181,   185,   189,   192,   196,   200,
     204,   208,   212,   216,   220,   224,   228,   230,   232,   234,
     238,   240,   243,   249,   251,   255,   257,   259,   261,   265,
     268,   270,   274,   278
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    -1,    46,    -1,    45,    46,    -1,
       3,    -1,    47,    -1,    49,    -1,    24,    -1,    25,    -1,
      48,    -1,    56,    -1,    60,    -1,    61,    -1,    14,     4,
      49,    13,    49,     5,    45,    20,    -1,    14,     4,    49,
      13,    68,     5,    45,    20,    -1,    21,    -1,    21,    50,
      -1,    21,    54,    -1,    21,    54,    50,    -1,    51,    -1,
      50,    51,    -1,    52,    -1,    53,    -1,    55,    -1,    55,
       4,    70,     5,    -1,    55,     4,     5,    -1,    55,    54,
      -1,     6,    65,     7,    -1,     6,    49,     7,    -1,    22,
      -1,    17,     4,    62,     5,    45,    20,    -1,    17,     4,
      62,     5,    45,    59,    20,    -1,    17,     4,    62,     5,
      45,    57,    20,    -1,    17,     4,    62,     5,    45,    57,
      59,    20,    -1,    58,    -1,    57,    58,    -1,    18,     4,
      62,     5,    45,    -1,    19,    45,    -1,    15,     4,    49,
      41,    62,     5,    -1,    16,     4,    63,     5,    -1,    67,
      -1,    68,    -1,    72,    -1,    23,    -1,    27,    -1,    63,
      -1,    64,    -1,    65,    -1,    68,    -1,    72,    -1,    67,
      36,    67,    -1,    67,    37,    67,    -1,    67,    38,    67,
      -1,    67,    39,    67,    -1,    67,    40,    67,    -1,    37,
      67,    -1,     4,    67,     5,    -1,    67,    29,    67,    -1,
      67,    28,    67,    -1,    67,    30,    67,    -1,    67,    31,
      67,    -1,    67,    32,    67,    -1,    67,    33,    67,    -1,
      67,    34,    67,    -1,    67,    35,    67,    -1,    64,    -1,
      49,    -1,    63,    -1,     6,    70,     7,    -1,    69,    -1,
       6,     7,    -1,     6,    64,     9,    64,     7,    -1,    71,
      -1,    70,     8,    71,    -1,    66,    -1,    49,    -1,    26,
      -1,    10,    73,    11,    -1,    10,    11,    -1,    74,    -1,
      73,     8,    74,    -1,    63,    12,    66,    -1,    63,    12,
      49,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    64,    65,    70,    71,    72,    73,    74,
      77,    78,    79,    80,    83,    84,    87,    88,    89,    90,
      93,    94,    97,    98,    99,   103,   104,   108,   111,   112,
     115,   118,   119,   120,   121,   124,   124,   127,   130,   133,
     136,   139,   140,   141,   144,   148,   151,   152,   155,   156,
     157,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   182,
     183,   184,   188,   191,   192,   195,   196,   197,   200,   201,
     204,   205,   208,   209
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONTENT", "PARENTHESIS",
  "CLOSE_PARENTHESIS", "BRACKET", "CLOSE_BRACKET", "COMMA", "RANGE",
  "BRACE", "CLOSE_BRACE", "COLON", "IN", "FOREACH", "SET", "PARSE", "IF",
  "ELSEIF", "ELSE", "END", "DOLLARID", "DOTID", "STRING_LITERAL",
  "COMMENT", "MUL_COMMENT", "CONSTANT", "INTEGER_LITERAL", "LOGICAL_AND",
  "LOGICAL_OR", "LOGIC_EQUAL", "LOGICAL_LT", "LOGICAL_LE", "LOGICAL_GT",
  "LOGICAL_GE", "LOGICAL_NOT_EQUALS", "ADD", "SUB", "MUL", "DIV", "MOD",
  "EQUAL", "UMINUS", "$accept", "root", "stmts", "stmt", "directive",
  "foreach", "reference", "attributes", "attribute", "method", "index",
  "indexBody", "identifier", "if", "elseifs", "elseif", "else", "set",
  "parse", "expression", "stringliteral", "integerliteral",
  "simpleliteral", "literal", "math", "array", "range", "params", "param",
  "map", "map_items", "map_item", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      47,    47,    47,    47,    48,    48,    49,    49,    49,    49,
      50,    50,    51,    51,    51,    52,    52,    53,    54,    54,
      55,    56,    56,    56,    56,    57,    57,    58,    59,    60,
      61,    62,    62,    62,    63,    64,    65,    65,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    69,    70,    70,    71,    71,    71,    72,    72,
      73,    73,    74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     8,     8,     1,     2,     2,     3,
       1,     2,     1,     1,     1,     4,     3,     2,     3,     3,
       1,     6,     7,     7,     8,     1,     2,     5,     2,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     3,
       1,     2,     5,     1,     3,     1,     1,     1,     3,     2,
       1,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     0,     0,    16,     8,     9,     0,
       2,     3,     6,    10,     7,    11,    12,    13,     0,     0,
       0,     0,     0,    30,    17,    20,    22,    23,    18,    24,
       1,     4,     0,     0,    44,     0,     0,     0,     0,    45,
       0,    67,     0,    68,    66,    41,    42,    70,    43,     0,
      46,    47,     0,    21,    19,     0,    27,     0,     0,    40,
       0,    71,    77,    76,    47,    48,    75,    49,     0,    73,
      50,    79,     0,     0,    80,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,    28,    26,     0,     0,     0,     0,    57,     0,    69,
       0,     0,     0,    78,     0,    59,    58,    60,    61,    62,
      63,    64,    65,    51,    52,    53,    54,    55,    25,     0,
       0,    39,     0,    74,    83,    82,    81,     0,     0,    31,
       0,    35,     0,     0,     0,    72,     0,    38,    33,    36,
       0,    32,    14,    15,     0,    34,     0,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    41,    24,    25,    26,
      27,    28,    29,    15,   130,   131,   132,    16,    17,    42,
      43,    44,    65,    66,    45,    67,    47,    68,    69,    70,
      73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
     222,   -70,    22,    30,    39,    44,     5,   -70,   -70,     9,
     222,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    63,    63,
      67,   159,    33,   -70,    73,   -70,   -70,   -70,    73,    79,
     -70,   -70,    84,    58,   -70,   100,     8,    26,    19,   -70,
       8,   -70,   101,   -70,   -70,   235,   -70,   -70,   -70,   103,
     -70,   -70,   105,   -70,    73,    88,   -70,    -1,   159,   -70,
     122,   -70,   -70,   -70,    98,   -70,   -70,   -70,    95,   -70,
     -70,   -70,    96,    50,   -70,   -70,   222,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
     -70,   -70,   -70,    70,   108,   112,   116,   -70,    97,   -70,
     158,   234,    67,   -70,   173,   104,   104,   104,   104,   104,
     104,   104,   104,   -23,   -23,   -70,   -70,   -70,   -70,   222,
     222,   -70,   115,   -70,   -70,   -70,   -70,   119,   222,   -70,
      61,   -70,   110,   192,   207,   -70,   159,   222,   -70,   -70,
     111,   -70,   -70,   -70,   127,   -70,   222,   222
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -69,    -8,   -70,   -70,     0,   107,   -10,   -70,
     -70,   109,   -70,   -70,   -70,     6,    15,   -70,   -70,   -54,
     -14,    -9,   126,    48,   -15,   -18,   -70,   117,    66,   -20,
     -70,    65
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      14,    48,    31,    46,    96,    37,    35,   104,    50,    30,
      14,    22,    36,    51,    53,    87,    88,    89,    32,    33,
       6,    60,    49,    50,    72,    75,    18,    23,    64,     6,
      71,    34,    37,    61,    19,    39,    38,    63,    48,    95,
      46,    50,    34,    20,    53,    40,    51,     6,    21,    34,
     133,   134,    62,    39,     6,    63,    34,    94,   102,   137,
      39,   103,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    14,   147,   100,   127,
     128,   138,   144,    55,     6,    22,    50,    50,    72,   122,
      34,    51,    51,    92,    37,    23,    31,    57,    38,    58,
      63,   124,    99,   100,    14,    59,    76,    98,   101,     6,
      90,    34,    91,   119,    62,    39,    48,   120,    46,    14,
      14,   121,   135,   136,    39,    31,    31,    97,    14,    31,
     141,   145,   146,    14,    14,    54,   139,    14,    56,    31,
      85,    86,    87,    88,    89,   140,    14,    14,    52,   125,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    36,    37,    37,   123,   126,    38,    38,
       0,     0,    93,     0,     0,     0,     1,     0,     0,     6,
       6,    34,    34,     0,    62,    39,    39,     2,     3,     4,
       5,   127,   128,   129,     6,     1,    40,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       1,     0,   142,     6,     0,     0,     7,     8,     0,     0,
       0,     2,     3,     4,     5,     1,     0,   143,     6,     0,
       0,     7,     8,     0,     0,     0,     2,     3,     4,     5,
      37,     0,     0,     6,    38,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     6,     0,    34,     0,     0,
       0,    39,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89
};

static const yytype_int16 yycheck[] =
{
       0,    21,    10,    21,    58,     6,    20,    76,    22,     0,
      10,     6,     4,    22,    24,    38,    39,    40,    18,    19,
      21,    36,    22,    37,    38,    40,     4,    22,    37,    21,
      11,    23,     6,     7,     4,    27,    10,    37,    58,    57,
      58,    55,    23,     4,    54,    37,    55,    21,     4,    23,
     119,   120,    26,    27,    21,    55,    23,    57,     8,   128,
      27,    11,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     5,    76,   146,     8,    18,
      19,    20,   136,     4,    21,     6,   100,   101,   102,    98,
      23,   100,   101,     5,     6,    22,   104,    13,    10,    41,
     100,   101,     7,     8,   104,     5,     5,     9,    12,    21,
       7,    23,     7,     5,    26,    27,   136,     5,   136,   119,
     120,     5,     7,     4,    27,   133,   134,     5,   128,   137,
      20,    20,     5,   133,   134,    28,   130,   137,    29,   147,
      36,    37,    38,    39,    40,   130,   146,   147,    22,   101,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     4,     6,     6,   100,   102,    10,    10,
      -1,    -1,    55,    -1,    -1,    -1,     3,    -1,    -1,    21,
      21,    23,    23,    -1,    26,    27,    27,    14,    15,    16,
      17,    18,    19,    20,    21,     3,    37,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
       3,    -1,    20,    21,    -1,    -1,    24,    25,    -1,    -1,
      -1,    14,    15,    16,    17,     3,    -1,    20,    21,    -1,
      -1,    24,    25,    -1,    -1,    -1,    14,    15,    16,    17,
       6,    -1,    -1,    21,    10,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    23,    -1,    -1,
      -1,    27,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    14,    15,    16,    17,    21,    24,    25,    44,
      45,    46,    47,    48,    49,    56,    60,    61,     4,     4,
       4,     4,     6,    22,    50,    51,    52,    53,    54,    55,
       0,    46,    49,    49,    23,    63,     4,     6,    10,    27,
      37,    49,    62,    63,    64,    67,    68,    69,    72,    49,
      63,    64,    65,    51,    50,     4,    54,    13,    41,     5,
      67,     7,    26,    49,    64,    65,    66,    68,    70,    71,
      72,    11,    63,    73,    74,    67,     5,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       7,     7,     5,    70,    49,    68,    62,     5,     9,     7,
       8,    12,     8,    11,    45,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,     5,     5,
       5,     5,    64,    71,    49,    66,    74,    18,    19,    20,
      57,    58,    59,    45,    45,     7,     4,    45,    20,    58,
      59,    20,    20,    20,    62,    20,     5,    45
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 52 "vtl4.y"
    {
    (yyval.ast)=process((yyvsp[(1) - (1)].ast));
    printf("----------------------- Begin to render1!-------------------------\n");
    traverse((yyval.ast));
    free_tree((yyval.ast));
    //printf("----------------------- Begin to render2!-------------------------\n");
    //traverse($$);
    //render($$,NULL);
    //printf("----------------------- End to render!-------------------------\n");
    ;}
    break;

  case 3:
#line 64 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 4:
#line 65 "vtl4.y"
    {
    (yyval.ast) = add_ybrother((yyvsp[(1) - (2)].ast),(yyvsp[(2) - (2)].ast));
    ;}
    break;

  case 5:
#line 70 "vtl4.y"
    {(yyval.ast) = text((yyvsp[(1) - (1)].string));;}
    break;

  case 6:
#line 71 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 7:
#line 72 "vtl4.y"
    {printf("stmt ---reference\n");(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 8:
#line 73 "vtl4.y"
    {printf("stmt ---common\n");(yyval.ast) = comment((yyvsp[(1) - (1)].string));;}
    break;

  case 9:
#line 74 "vtl4.y"
    {printf("stmt ---mul common\n");(yyval.ast) = comment((yyvsp[(1) - (1)].string));;}
    break;

  case 10:
#line 77 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 11:
#line 78 "vtl4.y"
    {(yyval.ast)=(yyvsp[(1) - (1)].ast);;}
    break;

  case 12:
#line 79 "vtl4.y"
    {(yyval.ast)=(yyvsp[(1) - (1)].ast);;}
    break;

  case 13:
#line 80 "vtl4.y"
    {(yyval.ast)=(yyvsp[(1) - (1)].ast);;}
    break;

  case 14:
#line 83 "vtl4.y"
    {(yyval.ast) = foreach_directive((yyvsp[(3) - (8)].ast),(yyvsp[(5) - (8)].ast),(yyvsp[(7) - (8)].ast));;}
    break;

  case 15:
#line 84 "vtl4.y"
    {(yyval.ast) = foreach_directive((yyvsp[(3) - (8)].ast),(yyvsp[(5) - (8)].ast),(yyvsp[(7) - (8)].ast));;}
    break;

  case 16:
#line 87 "vtl4.y"
    {(yyval.ast) = reference((yyvsp[(1) - (1)].string), NULL);;}
    break;

  case 17:
#line 88 "vtl4.y"
    {(yyval.ast) = reference((yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].ast));;}
    break;

  case 18:
#line 89 "vtl4.y"
    {(yyval.ast) = reference_start_with_index((yyvsp[(1) - (2)].string),(yyvsp[(2) - (2)].ast),NULL);;}
    break;

  case 19:
#line 90 "vtl4.y"
    {(yyval.ast) = reference_start_with_index((yyvsp[(1) - (3)].string),(yyvsp[(2) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 20:
#line 93 "vtl4.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); ;}
    break;

  case 21:
#line 94 "vtl4.y"
    { (yyval.ast) = add_ybrother((yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast));;}
    break;

  case 22:
#line 97 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 23:
#line 98 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 24:
#line 99 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 25:
#line 103 "vtl4.y"
    {(yyval.ast) = method((yyvsp[(1) - (4)].ast),(yyvsp[(3) - (4)].ast));;}
    break;

  case 26:
#line 104 "vtl4.y"
    {(yyval.ast) = method((yyvsp[(1) - (3)].ast),NULL);;}
    break;

  case 27:
#line 108 "vtl4.y"
    { (yyval.ast) = reference_index((yyvsp[(1) - (2)].ast),(yyvsp[(2) - (2)].ast)); ;}
    break;

  case 28:
#line 111 "vtl4.y"
    {(yyval.ast) = (yyvsp[(2) - (3)].ast);;}
    break;

  case 29:
#line 112 "vtl4.y"
    {(yyval.ast) = (yyvsp[(2) - (3)].ast);;}
    break;

  case 30:
#line 115 "vtl4.y"
    {(yyval.ast) = identifier((yyvsp[(1) - (1)].string));;}
    break;

  case 31:
#line 118 "vtl4.y"
    {(yyval.ast) = if_directive((yyvsp[(3) - (6)].ast),(yyvsp[(5) - (6)].ast),NULL,NULL);;}
    break;

  case 32:
#line 119 "vtl4.y"
    {(yyval.ast) = if_directive((yyvsp[(3) - (7)].ast),(yyvsp[(5) - (7)].ast),NULL,(yyvsp[(6) - (7)].ast));;}
    break;

  case 33:
#line 120 "vtl4.y"
    {(yyval.ast) = if_directive((yyvsp[(3) - (7)].ast),(yyvsp[(5) - (7)].ast),(yyvsp[(6) - (7)].ast),NULL);;}
    break;

  case 34:
#line 121 "vtl4.y"
    {(yyval.ast) = if_directive((yyvsp[(3) - (8)].ast),(yyvsp[(5) - (8)].ast),(yyvsp[(6) - (8)].ast),(yyvsp[(7) - (8)].ast));;}
    break;

  case 36:
#line 124 "vtl4.y"
    {(yyval.ast) = add_ybrother((yyvsp[(1) - (2)].ast),(yyvsp[(2) - (2)].ast));;}
    break;

  case 37:
#line 127 "vtl4.y"
    {(yyval.ast) = elseif_directive((yyvsp[(3) - (5)].ast),(yyvsp[(5) - (5)].ast));;}
    break;

  case 38:
#line 130 "vtl4.y"
    {(yyval.ast) = else_directive((yyvsp[(2) - (2)].ast));;}
    break;

  case 39:
#line 133 "vtl4.y"
    {(yyval.ast) = set_directive((yyvsp[(3) - (6)].ast),(yyvsp[(5) - (6)].ast)); ;}
    break;

  case 40:
#line 136 "vtl4.y"
    {(yyval.ast) = parse_directive((yyvsp[(3) - (4)].ast));;}
    break;

  case 41:
#line 139 "vtl4.y"
    {(yyval.ast) = expression((yyvsp[(1) - (1)].ast));;}
    break;

  case 42:
#line 140 "vtl4.y"
    {(yyval.ast) = expression((yyvsp[(1) - (1)].ast));;}
    break;

  case 43:
#line 141 "vtl4.y"
    {(yyval.ast) = expression((yyvsp[(1) - (1)].ast));;}
    break;

  case 44:
#line 144 "vtl4.y"
    {(yyval.ast) = string_literal((yyvsp[(1) - (1)].string));;}
    break;

  case 45:
#line 148 "vtl4.y"
    {(yyval.ast) =integer_literal((yyvsp[(1) - (1)].d));;}
    break;

  case 46:
#line 151 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 47:
#line 152 "vtl4.y"
    {printf("simpleliteral--integerliteral\n");(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 48:
#line 155 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 49:
#line 156 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 50:
#line 157 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 51:
#line 161 "vtl4.y"
    {(yyval.ast) = math_add((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 52:
#line 162 "vtl4.y"
    {(yyval.ast) = math_sub((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 53:
#line 163 "vtl4.y"
    {(yyval.ast) = math_mul((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 54:
#line 164 "vtl4.y"
    {(yyval.ast) = math_div((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 55:
#line 165 "vtl4.y"
    {(yyval.ast) = math_mod((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 56:
#line 166 "vtl4.y"
    {(yyval.ast) = math_unary_uminus((yyvsp[(2) - (2)].ast));;}
    break;

  case 57:
#line 167 "vtl4.y"
    {(yyval.ast) = (yyvsp[(2) - (3)].ast);;}
    break;

  case 58:
#line 168 "vtl4.y"
    {(yyval.ast) = math_logical_or((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 59:
#line 169 "vtl4.y"
    {(yyval.ast) = math_logical_and((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 60:
#line 170 "vtl4.y"
    {(yyval.ast) = math_logical_equals((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 61:
#line 171 "vtl4.y"
    {(yyval.ast) = math_logical_lt((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 62:
#line 172 "vtl4.y"
    {(yyval.ast) = math_logical_le((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 63:
#line 173 "vtl4.y"
    {(yyval.ast) = math_logical_gt((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 64:
#line 174 "vtl4.y"
    {(yyval.ast) = math_logical_ge((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 65:
#line 175 "vtl4.y"
    {(yyval.ast) = math_logical_not_equals((yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast));;}
    break;

  case 66:
#line 176 "vtl4.y"
    {(yyval.ast) =(yyvsp[(1) - (1)].ast);;}
    break;

  case 67:
#line 177 "vtl4.y"
    {printf("math:---reference\n");(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 68:
#line 178 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 69:
#line 182 "vtl4.y"
    { (yyval.ast) = array((yyvsp[(2) - (3)].ast)); ;}
    break;

  case 70:
#line 183 "vtl4.y"
    { (yyval.ast) = array((yyvsp[(1) - (1)].ast)); ;}
    break;

  case 71:
#line 184 "vtl4.y"
    { (yyval.ast) = array(NULL); ;}
    break;

  case 72:
#line 188 "vtl4.y"
    {(yyval.ast) = range((yyvsp[(2) - (5)].ast), (yyvsp[(4) - (5)].ast));;}
    break;

  case 73:
#line 191 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 74:
#line 192 "vtl4.y"
    {(yyval.ast) = add_ybrother((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;

  case 75:
#line 195 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 76:
#line 196 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 77:
#line 197 "vtl4.y"
    {(yyval.ast) = constant((yyvsp[(1) - (1)].string));;}
    break;

  case 78:
#line 200 "vtl4.y"
    {(yyval.ast) = map((yyvsp[(2) - (3)].ast));;}
    break;

  case 79:
#line 201 "vtl4.y"
    {(yyval.ast) = map(NULL);;}
    break;

  case 80:
#line 204 "vtl4.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 81:
#line 205 "vtl4.y"
    {(yyval.ast) = add_ybrother((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;

  case 82:
#line 208 "vtl4.y"
    {(yyval.ast) = map_item((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;

  case 83:
#line 209 "vtl4.y"
    {(yyval.ast) = map_item((yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;


/* Line 1267 of yacc.c.  */
#line 1998 "vtl4.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 212 "vtl4.y"

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
