#include "stack.h"

Stack_T* initSt(int var) {
  if(var>INT_MAX || var<INT_MIN)
    return NULL;
  Stack_T* stk = (Stack_T*)malloc(sizeof(Stack_T));
  stk->variable = var;
  stk->next = NULL;
  return stk;
}

Stack_T* pushSt(int var, Stack_T* root) {
  if(!root || (var>INT_MAX || var<INT_MIN))
    return NULL;
  Stack_T* new_root = initSt(var);
  new_root->next = root;
  return new_root;
}

Stack_T* popSt(Stack_T* root) {
  if(!root)
    return NULL;
  Stack_T* new;
  if (root->next != NULL) {
    new = root->next;
    free(root);
  } else {
    new = NULL;
    free(root);
  }
  return new;
}

void removeSt(Stack_T** root) {
  if (*root && root) {
    removeSt(&((*root)->next));
    free((*root));
  }
}