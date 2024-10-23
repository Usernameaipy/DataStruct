#include "list.h"

struct node* init(struct door* door) {
    struct node* list_one = (struct node*)malloc(sizeof(struct node));
    list_one->doors = door;
    list_one->next = NULL;
    return list_one;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* temp = init(door);
    struct node* tmp = elem;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = temp;
    return tmp;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* tmp = root;
    while (tmp != NULL && tmp->doors->id != door_id) {
        tmp = tmp->next;
    }
    return tmp;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* current = root;
    if (elem == root) {
        root = root->next;
        free(elem);
        return root;
    }
    while (current != NULL && current->next != elem) {
        current = current->next;
    }
    if (current != NULL) {
        if (elem->next == NULL) {
            current->next = NULL;
        } else {
            current->next = elem->next;
        }
        free(elem);
    }
    return root;
}

void destroy(struct node* root) {
    if (root) {
        destroy(root->next);
        free(root);
    }
}