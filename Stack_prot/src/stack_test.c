#include "stack_test.h"

START_TEST(intiStNormal) {
  Stack_T *stack = initSt(89);
  _ck_assert_ptr(stack, !=, NULL);
  ck_assert_int_eq(stack->variable, 89);
  removeSt(&stack);
}
END_TEST

START_TEST(intiStLarge) {
  Stack_T *stack = initSt(10000000);
  _ck_assert_ptr(stack, !=, NULL);
  ck_assert_int_eq(stack->variable, 10000000);
  removeSt(&stack);
}
END_TEST

START_TEST(pushStNormal) {
  Stack_T *stack = initSt(89);
  Stack_T *one = pushSt(78, stack);
  Stack_T *two = pushSt(23, one);
  Stack_T *three = pushSt(65, two);
  _ck_assert_ptr(one, !=, NULL);
  _ck_assert_ptr(two, !=, NULL);
  _ck_assert_ptr(three, !=, NULL);
  ck_assert_int_eq(three->variable, 65);
  ck_assert_int_eq(two->variable, 23);
  ck_assert_int_eq(one->variable, 78);
  int oneR, twoR, threeR;
  one = popSt(three, &oneR);
  _ck_assert_ptr(one, !=, NULL);
  ck_assert_int_eq(one->variable, 23);
  two = popSt(one, &twoR);
  _ck_assert_ptr(two, !=, NULL);
  ck_assert_int_eq(two->variable, 78);
  three = popSt(two, &threeR);
  _ck_assert_ptr(three, !=, NULL);
  ck_assert_int_eq(three->variable, 89);
  ck_assert_int_eq(oneR, 65);
  ck_assert_int_eq(twoR, 23);
  ck_assert_int_eq(threeR, 78);
  removeSt(&stack);
}
END_TEST

START_TEST(pushStIsNotSt) {
  Stack_T *stack = NULL;
  Stack_T *one = pushSt(78, stack);
  Stack_T *two = pushSt(32, one);
  Stack_T *three = pushSt(23, two);
  _ck_assert_ptr(one, ==, NULL);
  _ck_assert_ptr(two, ==, NULL);
  _ck_assert_ptr(three, ==, NULL);
  if (three) {
    removeSt(&three);
  }
}
END_TEST

Suite *createTestStack() {
  Suite *suite = suite_create("TestStack");
  TCase *tcase = tcase_create("TestStack");

  // Инициализирование стека
  tcase_add_test(tcase, intiStNormal);
  tcase_add_test(tcase, intiStLarge);

  // добавление элемента в стэк
  tcase_add_test(tcase, pushStNormal);
  tcase_add_test(tcase, pushStIsNotSt);

  suite_add_tcase(suite, tcase);
  return suite;
}

int main() {
  Suite *suite = createTestStack();
  SRunner *sRunner = srunner_create(suite);
  srunner_set_fork_status(sRunner, CK_NOFORK);
  srunner_run_all(sRunner, CK_VERBOSE);
  printf("Всего запущено: %d тест(ов)\n", srunner_ntests_run(sRunner));
  printf("Всего провалено: %d теста\n", srunner_ntests_failed(sRunner));
  srunner_free(sRunner);
  return 0;
}