//
//  bool.c
//  tree
//
//  Created by sinory on 13-3-14.
//  Copyright (c) 2013年 sinory. All rights reserved.
//


#include <string.h>
#include "bool.h"

bool get_bool_value(char* b){
    if (strcmp(b,"true")) {
        return true;
    }else return false;
}