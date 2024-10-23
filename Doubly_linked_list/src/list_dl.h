#ifndef LIST_DL_H
#define LIST_DL_H
#include <stdio.h>
#include <stdlib.h>
struct node {
    int variable;
    struct node* pref;
    struct node* next;
};
struct node* init(int);
struct node* insert(struct node*, int);
struct node* insert_after(struct node*,struct node*, int);
struct node* insert_before(struct node*, struct node*, int);
struct node* print_next(struct node*);
struct node* print_pref(struct node*);
int search_index (struct node*, int);
void delete_list(struct node*);
#endif