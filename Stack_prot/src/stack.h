#ifndef STACK_H
#define STACK_H
typedef struct stack {
  int variable;
  struct stack* next;
} Stack_T;
// Инициализирует стэк
Stack_T* initSt(int var);
// Добавляет элемент в стэк
Stack_T* pushSt(int var, Stack_T* root);
// Получает элемент из стэка
Stack_T* popSt(Stack_T* root, int* tmp);
// Полностью удаляет стэк
void removeSt(Stack_T** root);
#endif
#ifndef STDIO_H_LIB
#define STDIO_H_LIB
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#endif