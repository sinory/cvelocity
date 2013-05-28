//
//  util.c
//  tree
//
//  Created by sinory on 13-4-1.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "util.h"

/* symbol table */
/* hash a symbol */
unsigned symhash(char *sym){
    unsigned int hash = 0;
    unsigned c;

    while((c = *sym++)) hash = hash*9 ^ c;

    return hash;
}

char * strclip(const char *src, unsigned long n,unsigned long m) /*n为长度，m为位置*/
{
    char *p = strdup(src);
    unsigned long len = strlen(src);
    if(n>len) n = len-m;    /*从第m个到最后*/
    if(m>len) return NULL;
    p += m;
    char *q = malloc(n+1);
    return memcpy(q,p,n);
}

long cost(long start){
    clock_t finish;
    finish = clock();
    return (finish - start);
}
