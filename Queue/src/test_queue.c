#include "test_queue.h"

START_TEST(createQueueNormal) {
  Queue_T *queue = createQueue(10);
  _ck_assert_ptr(queue, !=, NULL);
  _ck_assert_int(queue->variable, ==, 10);
  removeQueue(queue);
}
END_TEST

START_TEST(createQueueLarge) {
  Queue_T *queue = createQueue(100000000);
  _ck_assert_ptr(queue, !=, NULL);
  _ck_assert_int(queue->variable, ==, 100000000);
  removeQueue(queue);
}
END_TEST

Suite *QueueTest(void) {
  Suite *suite = suite_create("Queue");
  TCase *tcase = tcase_create("Queue");

  tcase_add_test(tcase, createQueueNormal);
  tcase_add_test(tcase, createQueueLarge);

  suite_add_tcase(suite, tcase);
  return suite;
}

int main() {
  Suite *suite = QueueTest();
  SRunner *sRunner = srunner_create(suite);
  srunner_set_fork_status(sRunner, CK_NOFORK);
  srunner_run_all(sRunner, CK_VERBOSE);
  printf("Всего выполнено: %d тестов.\n", srunner_ntests_run(sRunner));
  printf("Провалено: %d тестов.\n", srunner_ntests_failed(sRunner));
  srunner_free(sRunner);
  return 0;
}