#ifndef STACK_H
#define STACK_H
struct stack {
    int variable;
    struct stack* next;
};
struct stack* initSt(int var);
struct stack* pushSt(int var, struct stack* root);
struct stack* popSt(struct stack* root);
void removeSt(struct stack* root);
#endif
#ifndef STDIO_H_LIB
#define STDIO_H_LIB
#include <stdio.h>
#include <stdlib.h>
#endif