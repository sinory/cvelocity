//
//  render.h
//  tree
//
//  Created by sinory on 13-4-1.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#include "simpleNode.h"
#include "context.h"

#ifndef tree_render_h
#define tree_render_h

/**
 具体某个node的渲染
 */
cJSON *node_render(struct simpleNode *,struct context*);
//输出是渲染
cJSON *default_node_render(struct simpleNode *,struct context*);

//Directive render
void set_render(struct simpleNode *, struct context*);
cJSON *if_render(struct simpleNode *, struct context*);
cJSON *elseif_render(struct simpleNode *, struct context*);
cJSON *else_render(struct simpleNode *, struct context*);
cJSON *foreach_render(struct simpleNode *, struct context*);
cJSON *parse_render(struct simpleNode *, struct context*);

cJSON *text_render(struct simpleNode *);

cJSON *reference_render(struct simpleNode *, struct context*, int);
cJSON *identifier_render(struct simpleNode *);
cJSON *reference_index_render(struct simpleNode *);

cJSON *expression_render(struct simpleNode *n,struct context*);

cJSON *math_add_render(struct simpleNode *n,struct context*);
cJSON * math_sub_render(struct simpleNode *n,struct context*);
cJSON * math_mul_render(struct simpleNode *n,struct context*);
cJSON * math_div_render(struct simpleNode *n,struct context*);
cJSON * math_mod_render(struct simpleNode *n,struct context*);
cJSON * math_unary_uminus_render(struct simpleNode *n,struct context*);

cJSON *math_logical_equals_render(struct simpleNode *n,struct context*);
cJSON *math_logical_gt_render(struct simpleNode *n,struct context*);
cJSON * math_logical_or_render(struct simpleNode *n,struct context*);
cJSON * math_logical_and_render(struct simpleNode *n,struct context*);
cJSON * math_logical_not_equals_render(struct simpleNode *n,struct context*);
cJSON * math_logical_lt_render(struct simpleNode *n,struct context*);
cJSON * math_logical_le_render(struct simpleNode *n,struct context*);
cJSON * math_logical_ge_render(struct simpleNode *n,struct context*);

cJSON *integer_literal_render(struct simpleNode *n);
cJSON *string_literal_render(struct simpleNode *n);

cJSON *array_render(struct simpleNode *n, struct context*);
cJSON *integer_range_render(struct simpleNode *n, struct context*);

cJSON *map_item_render(struct simpleNode *n, struct context *context);
cJSON *map_render(struct simpleNode *n, struct context *context);

void render(struct simpleNode *,struct context*);
#endif
