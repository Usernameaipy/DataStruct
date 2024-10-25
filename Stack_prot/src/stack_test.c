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

START_TEST(popStNormal) {
  Stack_T *stack = initSt(89);
  Stack_T *one = pushSt(78, stack);
  Stack_T *two = pushSt(23, one);
  Stack_T *three = pushSt(65, two);
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

START_TEST(popStIsNotSt) {
  Stack_T *stack = NULL;
  Stack_T *one = pushSt(78, stack);
  Stack_T *two = pushSt(32, one);
  Stack_T *three = pushSt(23, two);
  _ck_assert_ptr(one, ==, NULL);
  _ck_assert_ptr(two, ==, NULL);
  _ck_assert_ptr(three, ==, NULL);
  int oneR = 0, twoR = 0, threeR = 0;
  one = popSt(three, &oneR);
  two = popSt(one, &twoR);
  three = popSt(two, &threeR);
  _ck_assert_ptr(one, ==, NULL);
  _ck_assert_ptr(two, ==, NULL);
  _ck_assert_ptr(three, ==, NULL);
  ck_assert_int_eq(oneR, 0);
  ck_assert_int_eq(twoR, 0);
  ck_assert_int_eq(threeR, 0);
  if (three) {
    removeSt(&three);
  }
}
END_TEST

START_TEST(popStIsNotTmp) {
  Stack_T *stack = initSt(78);
  Stack_T *one = pushSt(32, stack);
  stack = pushSt(34, one);
  one = pushSt(54, stack);
  stack = popSt(one, NULL);
  one = popSt(stack, NULL);
  _ck_assert_ptr(one, !=, NULL);
  _ck_assert_ptr(one->next, !=, NULL);
  ck_assert_int_eq(one->variable, 32);
  removeSt(&one);
}
END_TEST

START_TEST(popStIsOneSt) {
  Stack_T *stack = initSt(23);
  int oneR;
  Stack_T *one = popSt(stack, &oneR);
  _ck_assert_ptr(one, ==, NULL);
  ck_assert_int_eq(oneR, 23);
  if (one) {
    removeSt(&one);
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

  // Получение элемента из стэка
  tcase_add_test(tcase, popStNormal);
  tcase_add_test(tcase, popStIsNotSt);
  tcase_add_test(tcase, popStIsNotTmp);
  tcase_add_test(tcase, popStIsOneSt);

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