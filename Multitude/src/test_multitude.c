#include "test_multitude.h"

START_TEST(initMulNormal) {
  Mul_T *multitude = initMul(78);
  _ck_assert_ptr(multitude, !=, NULL);
  ck_assert_int_eq(multitude->val, 78);
  removeMul(&multitude);
}
END_TEST

START_TEST(initMulLarge) {
  Mul_T *multitude = initMul(100000000);
  _ck_assert_ptr(multitude, !=, NULL);
  ck_assert_int_eq(multitude->val, 100000000);
  removeMul(&multitude);
}
END_TEST

START_TEST(searchNormal) {
  Mul_T *multitude = initMul(76);
  insertMul(multitude, 65);
  insertMul(multitude, 43);
  insertMul(multitude, 21);
  Mul_T *one = searchMul(multitude, 76);
  Mul_T *two = searchMul(multitude, 65);
  Mul_T *three = searchMul(multitude, 43);
  _ck_assert_ptr(one, !=, NULL);
  _ck_assert_ptr(two, !=, NULL);
  _ck_assert_ptr(three, !=, NULL);
  ck_assert_int_eq(one->val, 76);
  ck_assert_int_eq(two->val, 65);
  ck_assert_int_eq(three->val, 43);
  removeMul(&multitude);
}
END_TEST

START_TEST(searchIsNotMul) {
  Mul_T *multitude = NULL;
  Mul_T *one = searchMul(multitude, 76);
  Mul_T *two = searchMul(multitude, 65);
  Mul_T *three = searchMul(multitude, 43);
  _ck_assert_ptr(one, ==, NULL);
  _ck_assert_ptr(two, ==, NULL);
  _ck_assert_ptr(three, ==, NULL);
  if (multitude) {
    removeMul(&multitude);
  }
}
END_TEST

START_TEST(searchIsNorVar) {
  Mul_T *multitude = initMul(78);
  insertMul(multitude, 67);
  insertMul(multitude, 89);
  Mul_T *one = searchMul(multitude, 98);
  Mul_T *two = searchMul(multitude, 32);
  Mul_T *three = searchMul(multitude, 45);
  _ck_assert_ptr(one, ==, NULL);
  _ck_assert_ptr(two, ==, NULL);
  _ck_assert_ptr(three, ==, NULL);
  removeMul(&multitude);
}
END_TEST

START_TEST(insertMulNormal) {
  Mul_T *multitude = initMul(76);
  insertMul(multitude, 65);
  insertMul(multitude, 43);
  insertMul(multitude, 21);
  Mul_T *one = searchMul(multitude, 76);
  Mul_T *two = searchMul(multitude, 65);
  Mul_T *three = searchMul(multitude, 43);
  _ck_assert_ptr(one, !=, NULL);
  _ck_assert_ptr(two, !=, NULL);
  _ck_assert_ptr(three, !=, NULL);
  ck_assert_int_eq(one->val, 76);
  ck_assert_int_eq(two->val, 65);
  ck_assert_int_eq(three->val, 43);
  removeMul(&multitude);
}
END_TEST

START_TEST(insertMulIsNotMul) {
  Mul_T *multitude = NULL;
  bool one = insertMul(multitude, 78);
  bool two = insertMul(multitude, 65);
  bool three = insertMul(multitude, 63);
  ck_assert_int_eq(one, ERROR);
  ck_assert_int_eq(two, ERROR);
  ck_assert_int_eq(three, ERROR);
  if (multitude) {
    removeMul(&multitude);
  }
}
END_TEST

START_TEST(insertMulIsLarge) {
  Mul_T *multitude = initMul(10000000);
  bool one = insertMul(multitude, 1000000);
  bool two = insertMul(multitude, 32789999);
  bool three = insertMul(multitude, 237822222);
  ck_assert_int_eq(one, OK);
  ck_assert_int_eq(two, OK);
  ck_assert_int_eq(three, OK);
  removeMul(&multitude);
}
END_TEST

START_TEST(insertMulIsMul) {
  Mul_T *multitude = initMul(76);
  bool one = insertMul(multitude, 76);
  bool two = insertMul(multitude, 89);
  bool three = insertMul(multitude, 89);
  ck_assert_int_eq(one, ERROR);
  ck_assert_int_eq(two, OK);
  ck_assert_int_eq(three, ERROR);
  removeMul(&multitude);
}
END_TEST

START_TEST(deleteMulNormal) {
  Mul_T *multitude = initMul(78);
  bool one = insertMul(multitude, 43);
  bool two = insertMul(multitude, 32);
  bool three = insertMul(multitude, 89);
  ck_assert_int_eq(one, OK);
  ck_assert_int_eq(two, OK);
  ck_assert_int_eq(three, OK);
  Mul_T *oneP = searchMul(multitude, 78);
  Mul_T *twoP = searchMul(multitude, 43);
  Mul_T *threeP = searchMul(multitude, 89);
  _ck_assert_ptr(oneP, !=, NULL);
  _ck_assert_ptr(twoP, !=, NULL);
  _ck_assert_ptr(threeP, !=, NULL);
  ck_assert_int_eq(oneP->val, 78);
  ck_assert_int_eq(twoP->val, 43);
  ck_assert_int_eq(threeP->val, 89);
  one = deleteMul(&multitude, 78);
  two = deleteMul(&multitude, 43);
  three = deleteMul(&multitude, 89);
  ck_assert_int_eq(one, OK);
  ck_assert_int_eq(two, OK);
  ck_assert_int_eq(three, OK);
  oneP = searchMul(multitude, 78);
  twoP = searchMul(multitude, 43);
  threeP = searchMul(multitude, 89);
  _ck_assert_ptr(oneP, ==, NULL);
  _ck_assert_ptr(twoP, ==, NULL);
  _ck_assert_ptr(threeP, ==, NULL);
  removeMul(&multitude);
}
END_TEST

START_TEST(deleteMulIsNotMul) {
  Mul_T *multitude = NULL;
  bool one = deleteMul(&multitude, 78);
  bool two = deleteMul(&multitude, 1);
  bool three = deleteMul(&multitude, 900000000);
  ck_assert_int_eq(one, ERROR);
  ck_assert_int_eq(two, ERROR);
  ck_assert_int_eq(three, ERROR);
  if (multitude) {
    removeMul(&multitude);
  }
}
END_TEST

START_TEST(deleteMulISNotVal) {
  Mul_T *multitude = initMul(78);
  bool one = insertMul(multitude, 43);
  bool two = insertMul(multitude, 32);
  bool three = insertMul(multitude, 89);
  ck_assert_int_eq(one, OK);
  ck_assert_int_eq(two, OK);
  ck_assert_int_eq(three, OK);
  Mul_T *oneP = searchMul(multitude, 78);
  Mul_T *twoP = searchMul(multitude, 43);
  Mul_T *threeP = searchMul(multitude, 89);
  _ck_assert_ptr(oneP, !=, NULL);
  _ck_assert_ptr(twoP, !=, NULL);
  _ck_assert_ptr(threeP, !=, NULL);
  ck_assert_int_eq(oneP->val, 78);
  ck_assert_int_eq(twoP->val, 43);
  ck_assert_int_eq(threeP->val, 89);
  one = deleteMul(&multitude, 56);
  two = deleteMul(&multitude, 23);
  three = deleteMul(&multitude, 98);
  ck_assert_int_eq(one, ERROR);
  ck_assert_int_eq(two, ERROR);
  ck_assert_int_eq(three, ERROR);
  removeMul(&multitude);
}
END_TEST

START_TEST(deleteMulIsOneVal) {
  Mul_T *multitude = initMul(89);
  bool one = deleteMul(&multitude, 89);
  ck_assert_int_eq(one, OK);
  _ck_assert_ptr(multitude, ==, NULL);
  if (multitude) {
    removeMul(&multitude);
  }
}
END_TEST

Suite *multitudeTest(void) {
  Suite *suite = suite_create("MultitudeTest");
  TCase *tcase = tcase_create("MultitudeTest");

  // Инициализация множества
  tcase_add_test(tcase, initMulNormal);
  tcase_add_test(tcase, initMulLarge);

  // Поиск элемента по множеству
  tcase_add_test(tcase, searchNormal);
  tcase_add_test(tcase, searchIsNotMul);
  tcase_add_test(tcase, searchIsNorVar);

  // Добавление элемента во множество
  tcase_add_test(tcase, insertMulNormal);
  tcase_add_test(tcase, insertMulIsNotMul);
  tcase_add_test(tcase, insertMulIsLarge);
  tcase_add_test(tcase, insertMulIsMul);

  // Удаление элемента из множества
  tcase_add_test(tcase, deleteMulNormal);
  tcase_add_test(tcase, deleteMulIsNotMul);
  tcase_add_test(tcase, deleteMulISNotVal);
  tcase_add_test(tcase, deleteMulIsOneVal);

  suite_add_tcase(suite, tcase);
  return suite;
}

int main() {
  Suite *suite = multitudeTest();
  SRunner *sRunner = srunner_create(suite);
  srunner_set_fork_status(sRunner, CK_NOFORK);
  srunner_run_all(sRunner, CK_VERBOSE);
  printf("Всего тесто запущено: %d\n", srunner_ntests_run(sRunner));
  printf("Всего тестов провалено: %d\n", srunner_ntests_failed(sRunner));
  srunner_free(sRunner);
  return 0;
}