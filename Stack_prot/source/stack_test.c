#include "stack_test.h"

Suite *createTestStack() {
  Suite *suite = suite_create("TestStack");
  TCase *tcase = tcase_create("TestStack");

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