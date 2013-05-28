//
//  simpleNode.c
//  tree
//
//  Created by sinory on 13-3-6.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "simpleNode.h"

void __free(struct simpleNode *n);

void addChild(struct simpleNode *n,struct simpleNode *child){
    if (child!=NULL&&n!=NULL) {
        if(n->firstChild!=NULL){
            struct simpleNode *tmp = malloc(sizeof(struct simpleNode));
            tmp = n->firstChild;
            while (tmp->nextSibling!=NULL) {
                tmp = tmp->nextSibling;
            }
            tmp->nextSibling = child;
        }else {
            n->firstChild = child;
        }
    }
}


//void traverse(struct simpleNode* root){
//    if(root==NULL){
//        printf("Empty tree!\n");
//    }else {
//        //遍历
//        struct simpleNode *x = malloc(sizeof(struct simpleNode));
//        //struct simpleNode *y = malloc(sizeof(struct simpleNode));
//        x = root;
//        //y = root;
//        if(x->firstChild!=NULL){
//            dump_tree(x);
//            x=x->firstChild;
//            traverse(x);
//        }else if(x->nextSibling!=NULL){
//            dump_tree(x);
//            x=x->nextSibling;
//            traverse(x);
//        }else {
//            dump_tree(x);
//        }
//    }
//}

void traverse(struct simpleNode* root){
        //遍历
        struct simpleNode *x = root;
        /**
            如果他既没有孩子也没有兄弟，直接dump
         */
        if (x!=NULL) {
            dump_tree(x);
            traverse(x->firstChild);
            traverse(x->nextSibling);
        }
}

void free_tree(struct simpleNode* n){
    //遍历
    struct simpleNode *x = n;
    
    if (x) {
        //printf("==========Begin to free %s, image=%s=============\n",x->info.node_name,cJSON_Print(x->info.image));
        
        //free_tree(x->firstChild);
        //__free(x);
        
        free_tree(x->firstChild);
        
        free_tree(x->nextSibling);
        __free(x);
        
        //__free(x);
    }
}

void free_nodeInfo(struct simpleNode* n){
    if (n!=NULL) {
        printf("==============begin delete %s node!\n",n->info.node_name);
        struct nodeInfo ni = n->info;
        if (ni.image!=NULL) {
            cJSON_Delete(ni.image);
        }
        free(ni.current_tpl_name);
        free(n);
        printf("==============delete node done!\n");
    }
}

void __free(struct simpleNode *n){
    //printf("==========__free %s, image=%s=============\n",n->info.node_name,cJSON_Print(n->info.image));
    //dump_tree(n);
    
    if (n) {
        //printf("==============begin delete %s node!\n",n->info.node_name);
            free_nodeInfo(n);
    }
}

void dump_tree(struct simpleNode *n){
    if (n!=NULL) {
        //render
        switch (n->info.astn) {
            case JJTPROCESS:
                break;
            case JJTTEXT:
            default:
                break;
        }
    }
    printf("Node:astn=%s,image:%s,already_rendered:%d\n",jjtNodeName[n->info.astn],cJSON_Print(n->info.image),n->info.already_rendered);
    //printf("Node:astn=%s,image:%s\n",jjtNodeName[n->info.astn],cJSON_GetString(n->info.image));
    if (n->firstChild!=NULL) {
        struct simpleNode *children = n->firstChild;
        int i = 1;
        printf("====== The %d children,astn=%s\n",i,jjtNodeName[children->info.astn]);
        while (children->nextSibling!=NULL) {
            children = children->nextSibling;
            printf("====== The %d children,astn=%s\n",++i,jjtNodeName[children->info.astn]);
        }
    }
}


void yyerror(char *s, ...)
{
    va_list ap;
    va_start(ap, s);
    fprintf(stderr, "line:%d: error: ",yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}