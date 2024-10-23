#ifndef TEST_LIST_DL_H
#define TEST_LIST_DL_H
#include "list_dl.h"
void success(void);
void fail(void);
void test_init(int);
void test_insert(int);
void test_insert_after(int);
void test_insert_before(int);
void test_index(int, int);
#define TEST_INIT_ONE 8
#define TEST_INIT_TWO 'c'
#define TEST_INIT_THREE 72000
#define TEST_INSERT_ONE 90
#define TEST_INSERT_TWO 'j'
#define TEST_INSERT_THREE 72000
#define TEST_INSERT_AFTER_ONE 45
#define TEST_INSERT_AFTER_TWO 'h'
#define TEST_INSERT_AFTER_THREE 72000
#define TEST_INSERT_BEFORE_ONE 78
#define TEST_INSERT_BEFORE_TWO 'o'
#define TEST_INSERT_BEFORE_THREE 72000
#define TEST_SEARCH_INDEX_ONE 2
#define TEST_SEARCH_INDEX_TWO 'j'
#endif