#ifndef MULTITUDE_H
#define MULTITUDE_H
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct multitude {
  int val;
  struct multitude *next;
  struct multitude *pref;
} Mul_T;
// Инициализирует множество
// Применяеться только один раз - при создании;
Mul_T *initMul(int);
// Ищет элемент множества с заданным значение
// возвращает адрес этого элемента
Mul_T *searchMul(Mul_T *, int);
// Вставляет элемент в множество
// Если элмента с данным значением нет - вставляет элемент
// в конец множества и возвращает true, иначе возвращает false
bool insertMul(Mul_T *, int);
// Удаляет элемент из множества
// Если такого элемента не найдено - возвращает false
// Иначе удаляет элемент и возвращает true
bool deleteMul(Mul_T **, int);
// Выводит множество в stdout
void printMul(Mul_T *);
// полностью удаляет множество
void removeMul(Mul_T **);
#endif