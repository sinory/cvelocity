//
//  context.c
//  tree
//
//  Created by sinory on 13-3-13.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "context.h"
#include "util.h"

struct symbol *
find_symbol(char* sym)
{
    struct symbol *sp = &symtab[symhash(sym)%NHASH];
    int scount = NHASH;		/* how many have we looked at */
    while(--scount >= 0) {
        if(sp->name && !strcmp(sp->name, sym)) { return sp; }

        if(!sp->name) {		/* new entry */
            sp->name = strdup(sym);
            sp->obj = NULL;
            return sp;
        }

        if(++sp >= symtab+NHASH) sp = symtab; /* try the next entry */
    }
    yyerror("FUNC[%s]error:symbol table overflow\n",__func__);
    abort(); /* tried them all, table is full */
}
void set_symbol(char *sym, cJSON* v){
    struct symbol *sp = find_symbol(sym);
    if (sp!=NULL) {
        sp->obj = v;
    }else {
        yyerror("FUNC[%s]error:symbol null\n",__func__);
    }
}

void del_symbol(char *sym){
    struct symbol *sp = find_symbol(sym);
    if (sp !=NULL) {
        free(sp->name);
        cJSON_Delete(sp->obj);
        //free(sp);
    }
}
