#include "binary_test.h"

void success(void){
    printf("SUCCESS\n");
}

void fail(void){
    printf("FAIL\n");
}

void test_init(int var){
    struct binary* root=init(var);
    if(root->variable==var && root!=NULL){
        success();
    }
    else fail();
    print_sort(root);
    printf("\n");
    delete_tree(root);
}

void test_add(int var){
    struct binary* root = init(9);
    struct binary* cp = root;
    add(root, var);
    cp = (var>9) ? cp->max : cp->min;
    if(cp->variable==var && cp!=NULL){
        success();
    }
    else fail();
    print_sort(root);
    printf("\n");
    delete_tree(root);
}

int main(){
    test_init(TEST_ONE_INIT);
    test_init(TEST_TWO_INIT);
    test_init(TEST_THREE_INIT);
    test_add(TEST_ONE_ADD);
    test_add(TEST_TWO_ADD);
    test_add(TEST_THREE_ADD);
}