#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
typedef struct queue{
    int variable;
    struct queue *next;
} Queue_T;
// Создаёт начальный элемент очереди
// P.S применяеться единажды
Queue_T *createQueue(int);
// Добавляет элемент в очередь
bool insertQueue(Queue_T *, int);
// Вынимает элемент из очереди
// Возврашает новый адрес очереди
// В качестве параметра принимает адрес куда отгружать элемент очереди
Queue_T *pop(Queue_T *, int *);
// Удаляет всю очередь
void removeQueue(Queue_T *);
#endif