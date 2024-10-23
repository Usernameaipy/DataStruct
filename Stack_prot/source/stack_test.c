#include "stack_test.h"

int main() {
    struct stack* pere = init(4);
    struct stack* popr = test_push(7, pere);
    struct stack* des = test_pop(popr);
    destroy(des);
    return 0;
}

void success(void) { printf("SUCCESS"); }

void fail(void) { printf("FAIL"); }

struct stack* test_push(int var, struct stack* root) {
    printf("Test push\n");
    struct stack* new_root = push(7, root);
    if (new_root->variable == var) {
        success();
    } else {
        fail();
    }
    return new_root;
}

struct stack* test_pop(struct stack* root) {
    printf("\nTest pop\n");
    struct stack* next = pop(root);
    if (next->variable == 4) {
        success();
    } else {
        fail();
    }
    return next;
}