#include "list_test.h"

int main() {
    struct door* door_one = malloc(sizeof(struct door));
    struct door* door_two = malloc(sizeof(struct door));
    door_one->id = 13;
    door_one->status = 0;
    door_two->id = 14;
    door_two->status = 0;
    struct node* list = init(door_one);
    struct node* list_copy = list;
    while (list_copy != NULL) {
        printf("id = %d, status = %d\n", list_copy->doors->id, list_copy->doors->status);
        list_copy = list_copy->next;
    }
    test_add_door(list, door_two);
    struct node* del = find_door(14, list);
    test_remove_door(del, list);
    free(door_one);
    free(door_two);
    destroy(list);
    return 0;
}

void success(void) { printf("SUCCESS"); }

void fail(void) { printf("FAIL"); }

void test_add_door(struct node* elem, struct door* door) {
    printf("Test add_door\n");
    add_door(elem, door);
    struct node* ptr = elem;
    while (ptr != NULL) {
        printf("id = %d, status = %d\n", ptr->doors->id, ptr->doors->status);
        ptr = ptr->next;
    }
    if (elem->next != NULL) {
        success();
    } else
        fail();
}

void test_remove_door(struct node* elem, struct node* root) {
    printf("\nTest remove_door\n");
    remove_door(elem, root);
    struct node* ptr = root;
    while (ptr != NULL) {
        printf("id = %d, status = %d\n", ptr->doors->id, ptr->doors->status);
        ptr = ptr->next;
    }
    if (root->next == NULL) {
        success();
    } else {
        fail();
    }
}