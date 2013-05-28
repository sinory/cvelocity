//
//  parser.h
//  tree
//
//  Created by sinory on 13-3-6.
//  Copyright (c) 2013年 sinory. All rights reserved.
//

#ifndef tree_parser_h
#define tree_parser_h

#include "simpleNode.h"
#include "parser_tree_constants.h"
#include "context.h"

struct simpleNode* process(struct simpleNode *n);

/*
    添加右兄弟
    ybrother   younger brother
 */
struct simpleNode* add_ybrother(struct simpleNode *brother,struct simpleNode *ybrother);

//directive
struct simpleNode* set_directive(struct simpleNode *ref_n, struct simpleNode *exp_n);
struct simpleNode* if_directive(struct simpleNode *exp_n, struct simpleNode *block_n, struct simpleNode *elseif_n,struct simpleNode *else_n);
struct simpleNode* elseif_directive(struct simpleNode *exp_n, struct simpleNode *block_n);
struct simpleNode* else_directive(struct simpleNode *block_n);
struct simpleNode* parse_directive(struct simpleNode *str_n);
struct simpleNode* foreach_directive(struct simpleNode *l_ref_n, struct simpleNode *r_ref_n, struct simpleNode *block);

//reference

/**
 @param sym dollarId $foo
 @param attrs_n $foo.name/[2]/bar()
 */
struct simpleNode* reference(char *sym, struct simpleNode *attrs_n);
struct simpleNode* reference_start_with_index(char *sym, struct simpleNode* index_n, struct simpleNode *attrs_n);
struct simpleNode* identifier(char *identifier);
struct simpleNode* reference_index(struct simpleNode* identifier_n, struct simpleNode* n);
struct simpleNode* method(struct simpleNode* identifier_n, struct simpleNode* params_n);

//struct simpleNode* word(char *word);

//
struct simpleNode* string_literal(const char *str);

struct simpleNode* integer_literal(double i);

struct simpleNode* double_literal(double d);

struct simpleNode* boolean_literal(int);

struct simpleNode* array(struct simpleNode *n);

struct simpleNode* range(struct simpleNode *l,struct simpleNode *r);

struct simpleNode* map(struct simpleNode *n);

struct simpleNode* map_item(struct simpleNode *key, struct simpleNode *value);

struct simpleNode* expression(struct simpleNode *n);

struct simpleNode* text(char *text);

struct simpleNode* comment(char *comment);

struct simpleNode* constant(char *constant);

//math
struct simpleNode* math_add(struct simpleNode *l,struct simpleNode *r);
struct simpleNode* math_sub(struct simpleNode *l,struct simpleNode *r);
struct simpleNode* math_mul(struct simpleNode *l,struct simpleNode *r);
struct simpleNode* math_div(struct simpleNode *l,struct simpleNode *r);
struct simpleNode* math_mod(struct simpleNode *l,struct simpleNode *r);
struct simpleNode* math_unary_uminus(struct simpleNode *r);
struct simpleNode* bool_literal(bool b);

struct simpleNode* math_logical_or(struct simpleNode *l,struct simpleNode *r);
struct simpleNode* math_logical_and(struct simpleNode *l,struct simpleNode *r);
struct simpleNode* math_logical_equals(struct simpleNode *l,struct simpleNode *r);
struct simpleNode* math_logical_not_equals(struct simpleNode *l,struct simpleNode *r);
struct simpleNode* math_logical_lt(struct simpleNode *l,struct simpleNode *r);
struct simpleNode* math_logical_le(struct simpleNode *l,struct simpleNode *r);
struct simpleNode* math_logical_gt(struct simpleNode *l,struct simpleNode *r);
struct simpleNode* math_logical_ge(struct simpleNode *l,struct simpleNode *r);

#endif
