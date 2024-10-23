#include "stack.h"

struct stack* init(int var) {
    struct stack* stk = (struct stack*)malloc(sizeof(struct stack));
    stk->variable = var;
    stk->next = NULL;
    return stk;
}

struct stack* push(int var, struct stack* root) {
    struct stack* new_root = init(var);
    new_root->next = root;
    return new_root;
}

struct stack* pop(struct stack* root) {
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

void destroy(struct stack* root) {
    if (root) {
        destroy(root->next);
        free(root);
    }
}