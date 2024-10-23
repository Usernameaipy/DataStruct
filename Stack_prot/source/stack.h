#ifndef STACK_H
#define STACK_H
struct stack {
    int variable;
    struct stack* next;
};
struct stack* init(int var);
struct stack* push(int var, struct stack* root);
struct stack* pop(struct stack* root);
void destroy(struct stack* root);
#endif
#ifndef STDIO_H_LIB
#define STDIO_H_LIB
#include <stdio.h>
#include <stdlib.h>
#endif