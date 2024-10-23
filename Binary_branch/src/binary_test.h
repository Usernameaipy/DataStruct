#ifndef BINARY_TEST_H
#define BINARY_TEST_H
#include "binary.h"
void success(void);
void fail(void);
void test_init(int);
void test_add(int);
#define TEST_ONE_INIT 3
#define TEST_TWO_INIT 'j'
#define TEST_THREE_INIT 72000
#define TEST_ONE_ADD 0
#define TEST_TWO_ADD 'b'
#define TEST_THREE_ADD 72000
#endif