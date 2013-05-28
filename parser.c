//
//  parser.c
//  tree
//
//  Created by sinory on 13-3-6.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "util.h"
#include "parser_tree_constants.h"

static struct simpleNode *new_node(JJT jjt,cJSON *node_image);

struct simpleNode* process(struct simpleNode *n){
    printf("%s node!\n",__func__);
    struct simpleNode *a = new_node(JJTPROCESS,cJSON_CreateString("root"));
    a->firstChild = n;
    return a;
}

/*
 添加右兄弟
 @param ybrother   younger brother
 @return brother
 */
struct simpleNode* add_ybrother(struct simpleNode *brother,struct simpleNode *ybrother){
    printf("%s node!\n",__func__);
    if (brother ==NULL) {
        yyerror("FUNC[%s]error:Brother is null!",__func__);
        if (ybrother==NULL) {
            yyerror("FUNC[%s]error:Younger brother is null!",__func__);
            exit(0);
        }else {
            return ybrother;
        }
    }
    if (ybrother==NULL) {
        yyerror("FUNC[%s]error:Younger brother is null!",__func__);
        exit(0);
    }
    struct simpleNode* a = brother;
    while (a->nextSibling!=NULL) {
        a = a->nextSibling;
    }
    a->nextSibling = ybrother;
    //printf("%s node!\n",__func__);
    return brother;
}

struct simpleNode* reference(char *sym, struct simpleNode *attrs_n){
    printf("%s node!key:%s\n",__func__,sym);
    struct simpleNode *a = new_node(JJTREFERENCE,cJSON_CreateString(sym));
    addChild(a, attrs_n);
    return a;
}

struct simpleNode* reference_start_with_index(char *sym, struct simpleNode* index_n, struct simpleNode *attrs_n){
    printf("%s node!key:%s\n",__func__,sym);
    struct simpleNode *a = new_node(JJTREFERENCE,cJSON_CreateString(sym));
    struct simpleNode *index = new_node(JJTINDEX,cJSON_CreateString("index"));
    addChild(index, index_n);
    addChild(a, index);
    addChild(a, attrs_n);
    return a;
}

struct simpleNode* identifier(char *identifier){
    printf("%s node!key:%s\n",__func__,identifier);
    struct simpleNode *a = new_node(JJTIDENTIFIER,cJSON_CreateString(identifier));
    return a;
}

struct simpleNode* reference_index(struct simpleNode* identifier_n, struct simpleNode* index_n){
    struct simpleNode *a = new_node(JJTIDENTIFIER,identifier_n->info.image);
    struct simpleNode *index = new_node(JJTINDEX,cJSON_CreateString("index"));
    addChild(index, index_n);
    addChild(a, index);
    return a;
}

struct simpleNode* method(struct simpleNode* identifier_n, struct simpleNode* params_n){
    struct simpleNode *a = new_node(JJTIDENTIFIER,identifier_n->info.image);
    struct simpleNode *method = new_node(JJTMETHOD,cJSON_CreateString("method"));
    addChild(method, params_n);
    addChild(a, method);
    return a;
}

struct simpleNode* set_directive(struct simpleNode *ref_n, struct simpleNode *exp_n){
    printf("%s node!\n",__func__);
    struct simpleNode* a = new_node(JJTSETDIRECTIVE,cJSON_CreateString("#set"));
    addChild(a, ref_n);
    addChild(a, exp_n);
    return a;
}

struct simpleNode* parse_directive(struct simpleNode *str_n){
    printf("%s node!\n",__func__);
    struct simpleNode* a = new_node(JJTPARSEDIRECTIVE,cJSON_CreateString("#parse"));
    addChild(a, str_n);
    return a;
}

struct simpleNode* if_directive(struct simpleNode *exp_n, struct simpleNode *block_n, struct simpleNode *elseif_n,struct simpleNode *else_n){
    printf("%s node!\n",__func__);
    struct simpleNode *a = new_node(JJTIFSTATEMENT,cJSON_CreateString("#if"));
    addChild(a, exp_n);
    //添加一个虚拟的block节点
    struct simpleNode *b = new_node(JJTBLOCK,cJSON_CreateString("ifBlock"));
    addChild(b, block_n);
    addChild(a, b);
    addChild(a, elseif_n);
    addChild(a, else_n);
    return a;
}

struct simpleNode* elseif_directive(struct simpleNode *exp_n, struct simpleNode *block_n){
    printf("%s node!\n",__func__);
    struct simpleNode* a = new_node(JJTELSEIFSTATEMENT,cJSON_CreateString("#elseif"));
    addChild(a, exp_n);
    //添加一个虚拟的block节点
    struct simpleNode *b = new_node(JJTBLOCK,cJSON_CreateString("elseifBlock"));
    addChild(b, block_n);
    addChild(a, b);
    return a;
}
struct simpleNode* else_directive(struct simpleNode *block_n){
    printf("%s node!\n",__func__);
    struct simpleNode* a = new_node(JJTELSESTATEMENT,cJSON_CreateString("#else"));
    //添加一个虚拟的block节点
    struct simpleNode *b = new_node(JJTBLOCK,cJSON_CreateString("elseBlock"));
    addChild(b, block_n);
    addChild(a, b);
    return a;
}

struct simpleNode* foreach_directive(struct simpleNode *l_ref_n, struct simpleNode *r_ref_n, struct simpleNode *block_n){
    printf("%s node!\n",__func__);
    struct simpleNode* a = new_node(JJTFOREACHDIRECTIVE,cJSON_CreateString("#foreach"));
    addChild(a, l_ref_n);
    addChild(a, r_ref_n);
    //添加一个虚拟的block节点
    struct simpleNode *b = new_node(JJTBLOCK,cJSON_CreateString("foreachBlock"));
    addChild(b, block_n);
    addChild(a, b);
    return a;
}

//struct simpleNode* word(char *word){
//    printf("%s node!\n",__func__);
//    struct simpleNode* a = new_node(JJTWORD,cJSON_CreateString(word));
//    return a;
//}

struct simpleNode* string_literal(const char *str){
    printf("%s node!\n",__func__);
    char *strc = strclip(str,strlen(str)-2,1);
    printf("**********strclip:%s\n",strc);
    struct simpleNode* a = new_node(JJTSTRINGLITERAL,cJSON_CreateString(strc));
    return a;
}

struct simpleNode* integer_literal(double i){
    printf("%s node!\n",__func__);
    struct simpleNode* a = new_node(JJTINTEGERLITERAL,cJSON_CreateNumber(i));
    return a;
}

struct simpleNode* double_literal(double d){
    printf("%s node!\n",__func__);
    struct simpleNode* a = new_node(JJTFLOATINGPOINTLITERAL,cJSON_CreateNumber(d));
    return a;
}

struct simpleNode* boolean_literal(int b){
    printf("%s node!\n",__func__);
    struct simpleNode* a = NULL;
    if (b) {
        a = new_node(JJTTRUE,cJSON_CreateTrue());
    }else {
        a = new_node(JJTTRUE,cJSON_CreateFalse());
    }
    return a;
}

struct simpleNode* expression(struct simpleNode *n){
    printf("%s node!\n",__func__);
    struct simpleNode* a = new_node(JJTEXPRESSION,cJSON_CreateString("expression"));
    addChild(a, n);
    return a;
}

struct simpleNode* text(char *text){
    printf("%s node!%s\n",__func__,text);
    struct simpleNode* a = new_node(JJTTEXT,cJSON_CreateString(text));
    return a;
}

struct simpleNode* comment(char *comment){
    printf("%s node!\n",__func__);
    struct simpleNode* a = new_node(JJTCOMMENT,cJSON_CreateString(comment));
    return a;
}

struct simpleNode* constant(char *constant){
    printf("%s node!\n",__func__);
    struct simpleNode* a = new_node(JJTCONSTANT,cJSON_CreateString(constant));
    return a;
}

struct simpleNode* math_add(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTADDNODE,cJSON_CreateString("+"));
    addChild(a, l);
    addChild(a, r);
    return a;
}
struct simpleNode* math_sub(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTSUBTRACTNODE,cJSON_CreateString("-"));
    addChild(a, l);
    addChild(a, r);
    return a;
}
struct simpleNode* math_mul(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTMULNODE,cJSON_CreateString("*"));
    addChild(a, l);
    addChild(a, r);
    return a;
}
struct simpleNode* math_div(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTDIVNODE,cJSON_CreateString("/"));
    addChild(a, l);
    addChild(a, r);
    return a;
}
struct simpleNode* math_mod(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTMODNODE,cJSON_CreateString("%"));
    addChild(a, l);
    addChild(a, r);
    return a;
}
struct simpleNode* math_logical_or(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTORNODE,cJSON_CreateString("or"));
    addChild(a, l);
    addChild(a, r);
    return a;
}
struct simpleNode* math_logical_and(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTANDNODE,cJSON_CreateString("and"));
    addChild(a, l);
    addChild(a, r);
    return a;
}

struct simpleNode* math_logical_equals(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTEQNODE,cJSON_CreateString("=="));
    addChild(a, l);
    addChild(a, r);
    return a;
}
struct simpleNode* math_logical_not_equals(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTNOTNODE,cJSON_CreateString("!="));
    addChild(a, l);
    addChild(a, r);
    return a;
}
struct simpleNode* math_logical_lt(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTLTNODE,cJSON_CreateString("<"));
    addChild(a, l);
    addChild(a, r);
    return a;
}
struct simpleNode* math_logical_le(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTLENODE,cJSON_CreateString("<="));
    addChild(a, l);
    addChild(a, r);
    return a;
}
struct simpleNode* math_logical_gt(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTGTNODE,cJSON_CreateString(">"));
    addChild(a, l);
    addChild(a, r);
    return a;
}
struct simpleNode* math_logical_ge(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTGENODE,cJSON_CreateString(">="));
    addChild(a, l);
    addChild(a, r);
    return a;
}

/**java中没有这个节点，自己定义的*/
struct simpleNode* math_unary_uminus(struct simpleNode *r){
    struct simpleNode* a = new_node(JJTUNARYUMINUS,cJSON_CreateString("-"));
    addChild(a, r);
    return a;
}

struct simpleNode* bool_literal(bool b){
    JJT jjt;
    if (b== true) {
        jjt = JJTTRUE;
    }else {
        jjt = JJTFALSE;
    }
    struct simpleNode* a = new_node(jjt,cJSON_CreateBool(b));
    return a;
}

struct simpleNode* array(struct simpleNode *n){
    struct simpleNode* a = new_node(JJTOBJECTARRAY,cJSON_CreateString("array"));
    addChild(a, n);
    return a;
}

struct simpleNode* range(struct simpleNode *l,struct simpleNode *r){
    struct simpleNode* a = new_node(JJTINTEGERRANGE,cJSON_CreateString("range"));
    addChild(a, l);
    addChild(a, r);
    return a;
}

struct simpleNode* map(struct simpleNode *n){
    struct simpleNode* a = new_node(JJTMAP,cJSON_CreateString("map"));
    addChild(a, n);
    return a;
}

struct simpleNode* map_item(struct simpleNode *key, struct simpleNode *value){
    struct simpleNode* a = new_node(JJTMAPITEM,cJSON_CreateString("mapItem"));
    addChild(a, key);
    addChild(a, value);
    return a;
}

struct simpleNode *new_node(JJT jjt,cJSON *node_image){
    struct simpleNode *a = malloc(sizeof(struct simpleNode));
    if (a==NULL) {
        yyerror("FUNC[%s]error:Init a new simple error,out of space!",__func__);
        exit(0);
    }
    a->info.astn = jjt;
    a->info.node_name = jjtNodeName[jjt];
    a->info.image = node_image;
    a->info.already_rendered = cJSON_False;
    a->parent = NULL;
    a->firstChild = NULL;
    a->nextSibling = NULL;
    return a;
}
