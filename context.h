//
//  context.h
//  tree
//
//  Created by sinory on 13-3-11.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#include "cJSON.h"
#include "simpleNode.h"

#ifndef tree_context_h
#define tree_context_h

#define default_array_key array
#define default_map_key map

/**The context of velocity*/
struct context {
    struct symbol *sym;
};

//function table
struct func {
    char *name;
    struct symbol *params;
    cJSON* (*fc)(struct symbol *params);
};

/* symbol table */
struct symbol {		/* a variable name */
    //hash key;
    char *name;
    //hash obj
    cJSON *obj;
};

//暂时使用全局变量symtab，之后改成使用模板hash到struct context中去取
#define NHASH 9997
struct symbol symtab[NHASH];

struct symbol *find_symbol(char* sym);

/**赋值*/
void set_symbol(char *, cJSON*);

void del_symbol(char *sym);

//struct context {
//    struct symbol symtab[NHASH];
//};

#endif
