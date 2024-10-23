#include "list_dl.h"

struct node* init(int var){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->pref=NULL;
    root->next=NULL;
    root->variable=var;
    return root;
}

struct node* insert(struct node* root, int var){
    int trig=0;
    struct node* elem=init(var);
    if(root==NULL){
        trig=1;
    }
    if(trig==0){
        struct node* root_cp=root;
        while(root_cp->next!=NULL){
            root_cp=root_cp->next;
        }
        root_cp->next=elem;
        elem->pref=root_cp;
    }
    return elem;
}

struct node* insert_after(struct node* root, struct node* elem, int var){
    struct node* root_cp = root;
    while(root_cp!=elem && root_cp!=NULL){
        root_cp=root_cp->next;
    }
    if(root_cp!=NULL){
        struct node* next_elem = root_cp->next;
        struct node* new_elem = init(var);
        new_elem->next=next_elem;
        new_elem->pref=root_cp;
        root_cp->next=new_elem;
        next_elem->pref=new_elem;
    }
    return root_cp;
}

struct node* insert_before(struct node* root, struct node* elem, int var){
    struct node* root_cp = root;
    while(root_cp->next!=elem && root_cp->next!=NULL){
        root_cp=root_cp->next;
    }
    if(root_cp->next!=NULL){
        struct node* new_elem = init(var);
        struct node* pref_elem = root_cp->next;
        new_elem->pref=root_cp;
        new_elem->next=pref_elem;
        root_cp->next=new_elem;
        pref_elem->pref=new_elem;
    }
    return root_cp;
}

struct node* print_next(struct node* root){
    struct node* root_cp = root;
    struct node* last = NULL;
    while(root_cp!=NULL){
        last=root_cp;
        (root_cp->next==NULL) ? printf("%d\n", root_cp->variable) : printf("%d ", root_cp->variable);
        root_cp=root_cp->next;
    }
    return last;
}

struct node* print_pref(struct node* root){
    struct node* root_cp=root;
    struct node* first = NULL;
    while(root_cp!=NULL){
        first=root_cp;
        (root_cp->pref==NULL) ? printf("%d\n", root_cp->variable) : printf("%d ", root_cp->variable);
        root_cp=root_cp->pref;
    }
    return first;
}

int search_index(struct node* root, int elem){
    int index=0;
    struct node* root_cp=root;
    while(root_cp!=NULL && root_cp->variable!=elem){
        root_cp=root_cp->next;
        index+=1;
    }
    return (root_cp!=NULL) ? index : -1;
}

void delete_list(struct node* root) {
    if (root) {
        delete_list(root->next);
        free(root);
    }
}