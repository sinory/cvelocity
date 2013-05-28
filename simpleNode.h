//
//  simpleNode.h
//  tree
//
//  Created by sinory on 13-3-6.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#ifndef tree_Header_h
#define tree_Header_h

#include "bool.h"
#include "token.h"
#include "parser_tree_constants.h"
#include "cJSON.h"

#define SEQUENCE_MAX 30
#define STOP 10086

struct nodeInfo {
    cJSON *image;
    int already_rendered;//是否已经被渲染过了,防止子节点被重复渲染,默认为cJSON_False
    JJT astn;//node编号
    const char * node_name;
    char *current_tpl_name;
};

struct simpleNode {
    struct nodeInfo info;
    struct simpleNode* firstChild;//第一个孩子
    struct simpleNode* nextSibling;//右兄弟
    struct simpleNode* parent;//父亲
};

void addChild(struct simpleNode *n,struct simpleNode *child);

void dump_tree(struct simpleNode *n);
void traverse(struct simpleNode* root);
void free_tree(struct simpleNode* n);
void free_nodeInfo(struct simpleNode* n);
extern int yylineno; /* from lexer */
void yyerror(char *s, ...);

/*================================================================*/


#endif
