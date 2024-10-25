#include "stack.h"

struct stack* initSt(int var) {
    struct stack* stk = (struct stack*)malloc(sizeof(struct stack));
    stk->variable = var;
    stk->next = NULL;
    return stk;
}

struct stack* pushSt(int var, struct stack* root) {
    struct stack* new_root = initSt(var);
    new_root->next = root;
    return new_root;
}

struct stack* popSt(struct stack* root) {
    struct stack* new;
    if (root->next != NULL) {
        new = root->next;
        free(root);
    } else {
        new = NULL;
        free(root);
    }
    return new;
}

void removeSt(struct stack* root) {
    if (root) {
        removeSt(root->next);
        free(root);
    }
}