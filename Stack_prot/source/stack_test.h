#ifndef STACK_TEST_H
#define STACK_TEST_H
#include "stack.h"
struct stack* test_push(int var, struct stack* root);
struct stack* test_pop(struct stack* root);
void success(void);
void fail(void);
#endif