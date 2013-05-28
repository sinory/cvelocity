//
//  parserTreeConstants.h
//  tree
//
//  Created by sinory on 13-3-6.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#ifndef tree_parserTreeConstants_h
#define tree_parserTreeConstants_h

typedef enum ASTNode {
    JJTPROCESS = 0,
    JJTVOID = 1,
    JJTESCAPEDDIRECTIVE = 2,
    JJTESCAPE = 3,
    JJTCOMMENT = 4,
    JJTFLOATINGPOINTLITERAL = 5,
    JJTINTEGERLITERAL = 6,
    JJTSTRINGLITERAL = 7,
    JJTIDENTIFIER = 8,
    JJTWORD = 9,
    JJTDIRECTIVE = 10,
    JJTBLOCK = 11,
    JJTMAP = 12,
    JJTOBJECTARRAY = 13,
    JJTINTEGERRANGE = 14,
    JJTMETHOD = 15,
    JJTREFERENCE = 16,
    JJTTRUE = 17,
    JJTFALSE = 18,
    JJTTEXT = 19,
    JJTIFSTATEMENT = 20,
    JJTELSESTATEMENT = 21,
    JJTELSEIFSTATEMENT = 22,
    JJTSETDIRECTIVE = 23,
    JJTSTOP = 24,
    JJTEXPRESSION = 25,
    JJTASSIGNMENT = 26,
    JJTORNODE = 27,
    JJTANDNODE = 28,
    JJTEQNODE = 29,
    JJTNENODE = 30,
    JJTLTNODE = 31,
    JJTGTNODE = 32,
    JJTLENODE = 33,
    JJTGENODE = 34,
    JJTADDNODE = 35,
    JJTSUBTRACTNODE = 36,
    JJTMULNODE = 37,
    JJTDIVNODE = 38,
    JJTMODNODE = 39,
    JJTNOTNODE = 40,
    JJTUNARYUMINUS = 41,
    JJTPARSEDIRECTIVE = 42,
    JJTFOREACHDIRECTIVE = 43,
    JJTMAPITEM = 44,
    JJTINDEX = 45, /**added when velocity 1.7*/
    JJTCONSTANT = 46
}JJT;


const char* jjtNodeName[47];

#endif
