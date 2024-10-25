#ifndef STACK_H
#define STACK_H
typedef struct stack {
  int variable;
  struct stack* next;
} Stack_T;
Stack_T* initSt(int var);
Stack_T* pushSt(int var, Stack_T* root);
Stack_T* popSt(Stack_T* root);
void removeSt(Stack_T** root);
#endif
#ifndef STDIO_H_LIB
#define STDIO_H_LIB
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#endif