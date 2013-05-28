//
//  velocity.h
//  tree
//
//  Created by sinory on 13-3-13.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#ifndef tree_velocity_h
#define tree_velocity_h

#include "simpleNode.h"
#include "context.h"

#define VTL_COUNT 3000

struct velocity {
    struct context context;
    struct simpleNode ast;
    char *hash;
}vtl_tab[VTL_COUNT];

struct velocity get_velocity(char *hash);

#endif
