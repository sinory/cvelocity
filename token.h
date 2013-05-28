//
//  token.h
//  tree
//
//  Created by sinory on 13-2-27.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#ifndef tree_token_h
#define tree_token_h

struct token {
    int kind;
    char *image;
    struct token *next;
    int beginLine;
    int endLine;
    int beginColumn;
    int endColumn;
};


////ParserConstants
//enum tokenConstants {
//    EOF = 0,
//    LBRACKET = 1,
//    RBRACKET = 2,
//    COMMA = 3,
//    DOUBLEDOT = 4,
//    COLON = 5,
//    LEFT_CURLEY = 6, //{
//    RIGHT_CURLEY = 7,//}
//    LPAREN = 8,
//    RPAREN = 9,
//    REFMOD2_RPAREN = 10,
//    ESCAPE_DIRECTIVE = 11,
//    SET_DIRECTIVE = 12,  //#set
//    DOLLAR = 13,
//    DOLLARBANG = 14,
//    HASH = 17,
//    SINGLE_LINE_COMMENT_START = 18,
//    DOUBLE_ESCAPE = 19,
//    ESCAPE = 20,
//    TEXT = 21,
//    SINGLE_LINE_COMMENT = 22,
//    FORMAL_COMMENT = 23,
//    MULTI_LINE_COMMENT = 24,
//    WHITESPACE = 26,
//    STRING_LITERAL = 27,
//    TRUE = 28,
//    FALSE = 29,
//    NEWLINE = 30,
//    MINUS = 31,
//    PLUS = 32,
//    MULTIPLY = 33,
//    DIVIDE = 34,
//    MODULUS = 35,
//    LOGICAL_AND = 36,
//    LOGICAL_OR = 37,
//    LOGICAL_LT = 38,
//    LOGICAL_LE = 39,
//    LOGICAL_GT = 40,
//    LOGICAL_GE = 41,
//    LOGICAL_EQUALS = 42,
//    LOGICAL_NOT_EQUALS = 43,
//    LOGICAL_NOT = 44,
//    EQUALS = 45,
//    END = 46,
//    IF_DIRECTIVE = 47,
//    ELSEIF_DIRECTIVE = 48,
//    ELSE_DIRECTIVE = 49,
//    STOP_DIRECTIVE = 50,
//    DIGIT = 51,
//    INTEGER_LITERAL = 52,
//    FLOATING_POINT_LITERAL = 53,
//    EXPONENT = 54,
//    LETTER = 55,
//    DIRECTIVE_CHAR = 56,
//    WORD = 57,
//    BRACKETED_WORD = 58,
//    ALPHA_CHAR = 59,
//    ALPHANUM_CHAR = 60,
//    IDENTIFIER_CHAR = 61,
//    IDENTIFIER = 62,
//    DOT = 63,
//    LCURLY = 64,
//    RCURLY = 65,
//    REFERENCE_TERMINATOR = 66,
//    DIRECTIVE_TERMINATOR = 67,
//    
//    DIRECTIVE = 0,
//    REFMOD2 = 1,
//    REFMODIFIER = 2,
//    DEFAULT = 3,
//    REFERENCE = 4,
//    PRE_DIRECTIVE = 5,
//    IN_MULTI_LINE_COMMENT = 6,
//    IN_FORMAL_COMMENT = 7,
//    IN_SINGLE_LINE_COMMENT = 8
//};

//char* tokenImage[] = {
//    "<EOF>",
//    "\"[\"",
//    "\"]\"",
//    "\",\"",
//    "\"..\"",
//    "\":\"",
//    "\"{\"",
//    "\"}\"",
//    "\"(\"",
//    "<RPAREN>",
//    "\")\"",
//    "<ESCAPE_DIRECTIVE>",
//    "<SET_DIRECTIVE>",
//    "<DOLLAR>",
//    "<DOLLARBANG>",
//    "<token of kind 15>",
//    "\"#*\"",
//    "\"#\"",
//    "\"##\"",
//    "\"\\\\\\\\\"",
//    "\"\\\\\"",
//    "<TEXT>",
//    "<SINGLE_LINE_COMMENT>",
//    "\"*#\"",
//    "\"*#\"",
//    "<token of kind 25>",
//    "<WHITESPACE>",
//    "<STRING_LITERAL>",
//    "\"true\"",
//    "\"false\"",
//    "<NEWLINE>",
//    "\"-\"",
//    "\"+\"",
//    "\"*\"",
//    "\"/\"",
//    "\"%\"",
//    "<LOGICAL_AND>",
//    "<LOGICAL_OR>",
//    "<LOGICAL_LT>",
//    "<LOGICAL_LE>",
//    "<LOGICAL_GT>",
//    "<LOGICAL_GE>",
//    "<LOGICAL_EQUALS>",
//    "<LOGICAL_NOT_EQUALS>",
//    "<LOGICAL_NOT>",
//    "\"=\"",
//    "<END>",
//    "<IF_DIRECTIVE>",
//    "<ELSEIF_DIRECTIVE>",
//    "<ELSE_DIRECTIVE>",
//    "<STOP_DIRECTIVE>",
//    "<DIGIT>",
//    "<INTEGER_LITERAL>",
//    "<FLOATING_POINT_LITERAL>",
//    "<EXPONENT>",
//    "<LETTER>",
//    "<DIRECTIVE_CHAR>",
//    "<WORD>",
//    "<BRACKETED_WORD>",
//    "<ALPHA_CHAR>",
//    "<ALPHANUM_CHAR>",
//    "<IDENTIFIER_CHAR>",
//    "<IDENTIFIER>",
//    "<DOT>",
//    "\"{\"",
//    "\"}\"",
//    "<REFERENCE_TERMINATOR>",
//    "<DIRECTIVE_TERMINATOR>",
//};

#endif
