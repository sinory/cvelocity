//
//  util.h
//  tree
//
//  Created by sinory on 13-4-1.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#ifndef tree_util_h
#define tree_util_h

/* symbol table */
/* hash a symbol */
unsigned symhash(char *sym);

char * strclip(const char *src, unsigned long n,unsigned long m); /*n为长度，m为位置*/

long cost(long start);

#endif
