//
//  render.c
//  tree
//
//  Created by sinory on 13-4-1.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "render.h"
#include "cJSON.h"

//逻辑预算宏
#define math_logical(n,context,operator) \
double left = cJSON_GetNumber(node_render(n->firstChild, context)); \
double right = cJSON_GetNumber(node_render(n->firstChild->nextSibling, context)); \
return cJSON_CreateBool(left operator right);

//数学预算宏
#define math_number(n,context,operator) \
double left = cJSON_GetNumber(node_render(n->firstChild, context)); \
double right = cJSON_GetNumber(node_render(n->firstChild->nextSibling, context)); \
return cJSON_CreateNumber(left operator right);

static cJSON *__node_render(struct simpleNode *n,struct context *context, int render_able, int aleady_rendered);

static void __set_aleady_rendered(struct simpleNode *n, int aleady_rendered);

cJSON *text_render(struct simpleNode *n){
    /**
     这个地方要设置的原因是：他在block_render中会被渲染一次，然后在总递归中又会再次被渲染
     */
    //set_already_rendered(n);
    printf("%s",cJSON_GetString(n->info.image));
    return n->info.image;
}

cJSON *expression_render(struct simpleNode *n,struct context *context){
    //set_already_rendered(n);
    struct simpleNode *child = n->firstChild;
    cJSON *r = node_render(child, context);
    return r;
}

cJSON *math_add_render(struct simpleNode *n,struct context *context){
    math_number(n ,context, +);
}

cJSON * math_sub_render(struct simpleNode *n,struct context *context){
    math_number(n ,context, -);
}
cJSON * math_mul_render(struct simpleNode *n,struct context *context){
    math_number(n ,context, *);
}
cJSON * math_div_render(struct simpleNode *n,struct context *context){
    math_number(n ,context, /);
}
cJSON * math_mod_render(struct simpleNode *n,struct context *context){
    int left = cJSON_GetNumber(node_render(n->firstChild, context));
    int right = cJSON_GetNumber(node_render(n->firstChild->nextSibling, context));
    return cJSON_CreateNumber(left % right);
}
cJSON * math_unary_uminus_render(struct simpleNode *n,struct context *context){
    math_number(n ,context, -);
}

cJSON *math_logical_equals_render(struct simpleNode *n,struct context* context){
    math_logical(n, context, ==);
}

cJSON *math_logical_gt_render(struct simpleNode *n,struct context* context) {
    math_logical(n, context, >);
}

cJSON * math_logical_or_render(struct simpleNode *n,struct context* context){
    math_logical(n, context, ||);
}
cJSON * math_logical_and_render(struct simpleNode *n,struct context*context){
    math_logical(n, context, &&);
}
cJSON * math_logical_not_equals_render(struct simpleNode *n,struct context*context){
    math_logical(n, context, !=);
}
cJSON * math_logical_lt_render(struct simpleNode *n,struct context*context){
    math_logical(n, context, <);
}
cJSON * math_logical_le_render(struct simpleNode *n,struct context*context){
    math_logical(n, context, <=);
}
cJSON * math_logical_ge_render(struct simpleNode *n,struct context*context){
    math_logical(n, context, >=);
}

cJSON *if_render(struct simpleNode * n, struct context* context){
    //printf("#####render if\n");
    //render expression
    cJSON *condition = node_render(n->firstChild, context);
    struct simpleNode *if_block = n->firstChild->nextSibling;
    //if的子if，可能是elseif或者是else
    //struct simpleNode *sub_if = if_block->nextSibling;
    struct simpleNode* sub_if = if_block->nextSibling;
    if (cJSON_GetBoolean(condition)) {
        //printf("#####render if block\n");
        //if的判断成立，去渲染if中的block
        node_render(if_block, context);
        __set_aleady_rendered(sub_if,cJSON_True);
    }else {
        //把if的block设置，否者递归时候会重复渲染
        __set_aleady_rendered(if_block, cJSON_True);
        //printf("#####render elseif\n");
        //修改if的block为不可render
        //disable_node(if_block);
        //render elseif
        //如果有子if
        while (sub_if!=NULL) {
            if (sub_if->info.astn == JJTELSEIFSTATEMENT) {
                //else if
                if(cJSON_GetBoolean(node_render(sub_if, context))){
                    __set_aleady_rendered(sub_if->nextSibling,cJSON_True);
                    break;
                }
            }else if (sub_if->info.astn == JJTELSESTATEMENT && sub_if->nextSibling == NULL){
                //else
                node_render(sub_if, context);
            }else {
                printf("If Render error!");
                abort();
            }
            sub_if = sub_if->nextSibling;
            //printf("***********if n:%s\n",n->info.node_name);
        }
    }
    return NULL;
}

cJSON *elseif_render(struct simpleNode *n, struct context *context){
        //render expression
    //printf("elseif render:%s\n",n->firstChild->info.node_name);
        cJSON *condition = node_render(n->firstChild, context);
        if (cJSON_GetBoolean(condition)) {
            //满足去渲染block
            node_render(n->firstChild->nextSibling, context);
        }
    return condition;
}

cJSON *else_render(struct simpleNode *n, struct context *context){
    return node_render(n->firstChild, context);
}

cJSON *foreach_render(struct simpleNode *n, struct context *context){
    cJSON* mouk = cJSON_CreateArray();
    cJSON_AddItemToArray(mouk, cJSON_CreateString("hello 1"));
    cJSON_AddItemToArray(mouk, cJSON_CreateString("hello 2"));
    set_symbol("$mouk", mouk);
    cJSON *r_ref = node_render(n->firstChild->nextSibling, context);
    if (r_ref!=NULL) {
        int array_size = cJSON_GetArraySize(r_ref);
        if (array_size > 0) {
            cJSON *l_ref = node_render(n->firstChild, context);
            //循环renderblock
            struct simpleNode *block = n->firstChild->nextSibling->nextSibling;
            for (int i = 0; i < array_size; i++) {
                //取变量值
                cJSON *v = cJSON_GetArrayItem(r_ref, i);
                //赋值
                set_symbol(cJSON_GetString(l_ref), v);
                //render blcok
                if (i<array_size-1) {
                    //如果不是最后一次渲染
                    default_node_render(block, context);
                }else {
                    node_render(block, context);
                }
            }
            //销毁临时变量
            del_symbol(cJSON_GetString(l_ref));
        }
    }
    return NULL;
}

//cJSON *parse_render(struct simpleNode *n, struct context *context){
//    
//}

cJSON *block_render(struct simpleNode *n, struct context *context){
    //printf("Render-%s-nodeName:%s\n",__func__,n->info.node_name);
    //set_already_rendered(n);
    //if (!n->info.already_rendered) {
        render(n->firstChild, context);
    //}
    return NULL;
}

cJSON *reference_render(struct simpleNode *n,struct context *context, int print_able){
    struct symbol *sym = find_symbol(cJSON_GetString(n->info.image));
    if(print_able) {
        //@see cJSON.c line:202 会有双引号
        printf("%s",cJSON_Print(sym->obj));
    }
    return sym->obj;
}

void set_render(struct simpleNode *n,struct context *context){
    //key
    struct simpleNode *key_n = n->firstChild;
    cJSON *kjson = node_render(key_n, context);
    struct simpleNode *sub_key = key_n->firstChild;
    if (sub_key!=NULL) {
        //如果对象返回值为null，给属性赋值是一种不合法的行为
        if (kjson==NULL) {
            printf("Render error-%s-nodeName:%s,message:%s\n",__func__,n->info.node_name,"严重: reference set is not a valid reference");
            abort();
        }
        cJSON * up_level = kjson;
        //渲染子属性
        while (sub_key!=NULL) {
            //先看是否到此为止
            if (sub_key->nextSibling==NULL) {
                //判断上一级渲染结果是否为null，不为null直接set，否则报错
                if (up_level==NULL) {
                    printf("Render error-%s-nodeName:%s,message:%s\n",__func__,n->info.node_name,"严重: reference set is not a valid reference");
                    abort();
                }else {
                    //直接set
                }
            }else {
                
            }
        }
    }
    //value
    cJSON *v = node_render(n->firstChild->nextSibling,context);
    
    char *k = cJSON_GetString(kjson);
    printf("key:%s,value:%s\n",k,cJSON_Print(v));
    set_symbol(k, v);
}

cJSON *identifier_render(struct simpleNode *n){
    return n->info.image;
}

cJSON *reference_index_render(struct simpleNode *n){
    return n->info.image;
}

cJSON *string_literal_render(struct simpleNode *n){
    return n->info.image;
}

cJSON *integer_literal_render(struct simpleNode *n){
    return n->info.image;
}

cJSON *array_render(struct simpleNode *n, struct context* context){
    struct simpleNode *first = n->firstChild;
    cJSON *array_json = cJSON_CreateArray();
    if (first==NULL) {
        return array_json;
    }else if (first->info.astn == JJTINTEGERRANGE){
        return node_render(first, context);
    }else {
        while (first!=NULL) {
            cJSON *v = node_render(first, context);
            cJSON_AddItemToArray(array_json, v);
            first = first->nextSibling;
        }
        return array_json;
    }
}

cJSON *integer_range_render(struct simpleNode *n, struct context* context){
    cJSON *array_json = cJSON_CreateArray();
    double min = cJSON_GetNumber(node_render(n->firstChild, context));
    double max = cJSON_GetNumber(node_render(n->firstChild->nextSibling, context));
    if (max < min) {
        //return array_json;
    }else if (max == min){
        cJSON_AddItemToArray(array_json, cJSON_CreateNumber(min));
        //return array_json;
    }else {
        for (int i =min; i<= max; i++) {
            cJSON_AddItemToArray(array_json, cJSON_CreateNumber(i));
        }
    }
    return array_json;
}

cJSON *map_item_render(struct simpleNode *n, struct context *context){
    cJSON *object = cJSON_CreateObject();
    char *key = cJSON_GetString(node_render(n->firstChild, context));
    cJSON *value = node_render(n->firstChild->nextSibling, context);
    cJSON_AddItemToObject(object, key, value);
    return object;
}
cJSON *map_render(struct simpleNode *n, struct context *context){
    cJSON *object = cJSON_CreateObject();
    struct simpleNode *items = n->firstChild;
    if (items==NULL) {
        return object;
    }else {
        while (items!=NULL) {
            cJSON *item_object = node_render(items, context);
            char *key = item_object->child->string;
            cJSON *value = cJSON_GetObjectItem(item_object, key);
            cJSON_AddItemToObject(object, key, value);
            items = items->nextSibling;
        }
        return object;
    }
}

cJSON *default_node_render(struct simpleNode *n,struct context *context){
    return __node_render(n,context,cJSON_True, cJSON_False);
}

cJSON *node_render(struct simpleNode *n,struct context *context){
    return __node_render(n,context,cJSON_False, cJSON_True);
}

static cJSON *__node_render(struct simpleNode *n,struct context *context, int render_able, int aleady_rendered){
    if (n==NULL) {
        printf("Render error-%s-nodeName:%s\n",__func__,n->info.node_name);
        abort();
        return NULL;
    }
    if (n->info.already_rendered) {
        //printf("=========%s-aleady rendered nodeName:%s\n",__func__,n->info.node_name);
        return NULL;
    }
    __set_aleady_rendered(n,aleady_rendered);
    if (n->info.astn == JJTINTEGERLITERAL) {
        return integer_literal_render(n);
    }else if (n->info.astn == JJTEXPRESSION){
        return expression_render(n, context);
    }else if (n->info.astn == JJTTEXT){
        return text_render(n);
    }else if (n->info.astn == JJTSETDIRECTIVE){
        set_render(n, context);
        return NULL;
    }else if (n->info.astn == JJTREFERENCE){
        return reference_render(n, context,render_able);
    }else if (n->info.astn == JJTADDNODE){
        return math_add_render(n, context);
    }else if(n->info.astn == JJTPROCESS){
        return NULL;
    }else if (n->info.astn == JJTSTRINGLITERAL){
        return string_literal_render(n);
    }else if (n->info.astn == JJTIFSTATEMENT){
        return if_render(n, context);
    }else if (n->info.astn == JJTELSEIFSTATEMENT){
        return elseif_render(n, context);
    }else if (n->info.astn == JJTELSESTATEMENT){
        return else_render(n, context);
    }else if (n->info.astn == JJTBLOCK){
        return block_render(n, context);
    }else if (n->info.astn == JJTEQNODE){
        return math_logical_equals_render(n, context);
    }else if (n->info.astn == JJTGTNODE){
        return math_logical_gt_render(n, context);
    }else if (n->info.astn == JJTSUBTRACTNODE){
        return math_sub_render(n, context);
    }else if (n->info.astn == JJTMULNODE){
        return math_mul_render(n, context);
    }else if (n->info.astn == JJTDIVNODE){
        return math_div_render(n, context);
    }else if (n->info.astn == JJTMODNODE){
        return math_mod_render(n, context);
    }else if (n->info.astn == JJTUNARYUMINUS){
        return math_unary_uminus_render(n, context);
    }else if (n->info.astn == JJTEQNODE){
        return math_logical_equals_render(n, context);
    }else if (n->info.astn == JJTGTNODE){
        return math_logical_gt_render(n, context);
    }else if (n->info.astn == JJTORNODE){
        return math_logical_or_render(n, context);
    }else if (n->info.astn == JJTANDNODE){
        return math_logical_and_render(n, context);
    }else if (n->info.astn == JJTNOTNODE){
        return math_logical_not_equals_render(n, context);
    }else if (n->info.astn == JJTUNARYUMINUS){
        return math_logical_lt_render(n, context);
    }else if (n->info.astn == JJTLENODE){
        return math_logical_le_render(n, context);
    }else if (n->info.astn == JJTGENODE){
        return math_logical_ge_render(n, context);
    }else if (n->info.astn == JJTFOREACHDIRECTIVE){
        return foreach_render(n, context);
    }else if (n->info.astn == JJTINTEGERRANGE){
        return integer_range_render(n, context);
    }else if (n->info.astn == JJTOBJECTARRAY){
        return array_render(n, context);
    }else if (n->info.astn == JJTMAPITEM){
        return map_item_render(n, context);
    }else if (n->info.astn == JJTMAP){
        return map_render(n, context);
    }else if (n->info.astn == JJTIDENTIFIER){
        return identifier_render(n);
    }
    else {
        printf("Render error-%s-nodeName:%s\n",__func__,n->info.node_name);
        abort();

    }
    return NULL;
}

static void __set_aleady_rendered(struct simpleNode *n, int aleady_rendered){
    if(n!=NULL){
        n->info.already_rendered = aleady_rendered;
    }
}

void render(struct simpleNode *root,struct context *context){
    struct simpleNode *x = root;
    if (x!=NULL) {
        //printf("Render nodeName:%s\n",root->info.node_name);
        //printf("Render nodeName:%s\n",x->info.node_name);
        if (!x->info.already_rendered) {
            //render(x->nextSibling,context);
            default_node_render(x, context);
            //x->info.already_rendered = cJSON_False;
//            if (x->firstChild!=NULL) {
//                printf("Render firstChild-nodeName:%s,parent:%s\n",x->firstChild->info.node_name,x->info.node_name);
//            }
            render(x->firstChild,context);
//            if (x->nextSibling!=NULL) {
//                printf("Render nextSibling-nodeName:%s,parent:%s\n",x->nextSibling->info.node_name,x->info.node_name);
//            }
            render(x->nextSibling,context);
        }
    }else {
       // printf("NULL Tree\n");
    }
}