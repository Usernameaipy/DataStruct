#ifndef BINARY_H
#define BINARY_H
#include <stdio.h>
#include <stdlib.h>
struct binary {
    int variable;
    struct binary* max;
    struct binary* min;
};
struct binary* init(int);
struct binary* add(struct binary*, int);
void print_recursively(struct binary*);
void print_sort(struct binary*);
void delete_tree(struct binary*);
#endif