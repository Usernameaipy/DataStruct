#include "test_list_dl.h"

void success(void){
    printf("SUCCESS\n");
}

void fail(void){
    printf("FAIL\n");
}

void test_init(int var){
    printf("TEST_INIT\n");
    struct node* check=init(var);
    if(check->variable==var && check->next==NULL && check->pref==NULL){
        success();
    }
    else fail();
    delete_list(check);
}

void test_insert(int var){
    printf("TEST_INSERT\n");
    struct node* root=init(9);
    print_next(root);
    insert(root, var);
    print_next(root);
    struct node* root_cp=root->next;
    if(root_cp->variable==var && root_cp->next==NULL && root_cp->pref!=NULL){
        success();
    }
    else fail();
    delete_list(root);
}

void test_insert_after(int var){
    printf("TEST_INSERT_AFTER\n");
    struct node* root=init(9);
    insert(root, 2);
    print_next(root);
    insert_after(root, root, var);
    print_next(root);
    struct node* root_cp=root->next;
    if(root_cp->variable==var && root_cp->pref==root && root_cp->next!=NULL){
        success();
    }
    else fail();
    delete_list(root);
}

void test_insert_before(int var){
    printf("TEST_INSERT_BEFORE\n");
    struct node* root=init(9);
    insert(root, 7);
    print_next(root);
    insert_before(root, root->next, var);
    print_next(root);
    struct node* root_cp=root->next;
    if(root_cp->variable==var && root_cp->pref==root && root_cp->next!=NULL){
        success();
    }
    else fail();
    delete_list(root);
}

void test_index(int var, int pos){
    printf("TEST_INDEX\n");
    struct node* root=init(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    int index=search_index(root, var);
    if(index==pos){
        success();
    }
    else fail();
    delete_list(root);
}

int main(){
    test_init(TEST_INIT_ONE);
    test_init(TEST_INIT_TWO);
    test_init(TEST_INIT_THREE);
    test_insert(TEST_INSERT_ONE);
    test_insert(TEST_INSERT_TWO);
    test_insert(TEST_INSERT_THREE);
    test_insert_after(TEST_INSERT_AFTER_ONE);
    test_insert_after(TEST_INSERT_AFTER_TWO);
    test_insert_after(TEST_INSERT_AFTER_THREE);
    test_insert_before(TEST_INSERT_BEFORE_ONE);
    test_insert_before(TEST_INSERT_BEFORE_TWO);
    test_insert_before(TEST_INSERT_BEFORE_THREE);
    test_index(TEST_SEARCH_INDEX_ONE, 1);
    test_index(TEST_SEARCH_INDEX_TWO, -1);
    return 0;
}