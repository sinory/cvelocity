//
//  parserTreeConstants.c
//  tree
//
//  Created by sinory on 13-3-11.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#include <stdio.h>
#include "parser_tree_constants.h"


const char* jjtNodeName[] = {
    "process",
    "void",
    "EscapedDirective",
    "Escape",
    "Comment",
    "FloatingPointLiteral",
    "IntegerLiteral",
    "StringLiteral",
    "Identifier",
    "Word",
    "Directive",
    "Block",
    "Map",
    "ObjectArray",
    "IntegerRange",
    "Method",
    "Reference",
    "True",
    "False",
    "Text",
    "IfStatement",
    "ElseStatement",
    "ElseIfStatement",
    "SetDirective",
    "Stop",
    "Expression",
    "Assignment",
    "OrNode",
    "AndNode",
    "EQNode",
    "NENode",
    "LTNode",
    "GTNode",
    "LENode",
    "GENode",
    "AddNode",
    "SubtractNode",
    "MulNode",
    "DivNode",
    "ModNode",
    "NotNode",
    "MathUnaryUminusNode",
    "ParseDirective",
    "ForeachDirective",
    "MapItem",
    "Index",
    "Constant"
};
