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

START_TEST(insertQueueNormal) {
  Queue_T *queue = createQueue(89);
  insertQueue(queue, 12);
  insertQueue(queue, 77);
  insertQueue(queue, 54);
  int one, two, three;
  queue = pop(queue, &one);
  queue = pop(queue, &two);
  queue = pop(queue, &three);
  _ck_assert_int(one, ==, 89);
  _ck_assert_int(two, ==, 12);
  _ck_assert_int(three, ==, 77);
  _ck_assert_int(queue->variable, ==, 54);
  _ck_assert_ptr(queue, !=, NULL);
  removeQueue(queue);
}
END_TEST

START_TEST(insertQueueIsNotQueue) {
  Queue_T *queue = NULL;
  _ck_assert_int(insertQueue(queue, 43), ==, ERROR);
  _ck_assert_int(insertQueue(queue, 54), ==, ERROR);
  _ck_assert_int(insertQueue(queue, 100000000), ==, ERROR);
  if (queue) {
    removeQueue(queue);
  }
}
END_TEST

START_TEST(insertQueueLarge) {
  Queue_T *queue = createQueue(348764271);
  insertQueue(queue, 1000000000);
  insertQueue(queue, 632535155);
  insertQueue(queue, 859180499);
  int one, two, three;
  queue = pop(queue, &one);
  queue = pop(queue, &two);
  queue = pop(queue, &three);
  _ck_assert_int(one, ==, 348764271);
  _ck_assert_int(two, ==, 1000000000);
  _ck_assert_int(three, ==, 632535155);
  _ck_assert_int(queue->variable, ==, 859180499);
  _ck_assert_ptr(queue, !=, NULL);
  removeQueue(queue);
}
END_TEST

Suite *QueueTest(void) {
  Suite *suite = suite_create("Queue");
  TCase *tcase = tcase_create("Queue");

  // Тесты создания очереди
  tcase_add_test(tcase, createQueueNormal);
  tcase_add_test(tcase, createQueueLarge);

  // Тесты добавления элемента в очередь
  tcase_add_test(tcase, insertQueueNormal);
  tcase_add_test(tcase, insertQueueIsNotQueue);
  tcase_add_test(tcase, insertQueueLarge);

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