#include "queue.h"

Queue_T *createQueue(int var){
    if(var>INT_MAX || var<INT_MIN)
        return NULL;
    Queue_T *newQueue = (Queue_T*)malloc(sizeof(Queue_T));
    if(newQueue!=NULL){
        newQueue->variable=var;
        newQueue->next=NULL;
    }
    return newQueue;
}

bool insertQueue(Queue_T *root, int var){
    if((!root) || (var>INT_MAX || var<INT_MIN))
        return false;
    Queue_T *root_cp = root;
    while(root_cp->next!=NULL){
        root_cp=root_cp->next;
    }
    if(root_cp){
        Queue_T *newQueue = createQueue(var);
        if(newQueue==NULL)
            return false;
        root_cp->next=newQueue;
        return true;
    }
    return false;
}

Queue_T *pop(Queue_T *root, int *popVar){
    Queue_T *newRoot = root->next;
    *popVar = root->variable;
    free(root);
    root=NULL;
    return newRoot;
}

void removeQueue(Queue_T *root){
    if(root!=NULL){
        removeQueue(root->next);
        free(root);
    }
    return;
}

