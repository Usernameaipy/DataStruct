#include "test_multitude.h"

START_TEST(initMulNormal){
    Mul_T *multitude = initMul(78);
    _ck_assert_ptr(multitude, !=, NULL);
    ck_assert_int_eq(multitude->val, 78);
    removeMul(&multitude);
}
END_TEST

START_TEST(initMulLarge){
    Mul_T *multitude = initMul(100000000);
    _ck_assert_ptr(multitude, !=, NULL);
    ck_assert_int_eq(multitude->val, 100000000);
    removeMul(&multitude);
}
END_TEST

Suite *multitudeTest(void){
    Suite *suite = suite_create("MultitudeTest");
    TCase *tcase = tcase_create("MultitudeTest");

    tcase_add_test(tcase, initMulNormal);
    tcase_add_test(tcase, initMulLarge);

    suite_add_tcase(suite, tcase);
    return suite;
}

int main(){
    Suite *suite = multitudeTest();
    SRunner *sRunner = srunner_create(suite);
    srunner_set_fork_status(sRunner, CK_NOFORK);
    srunner_run_all(sRunner, CK_VERBOSE);
    printf("Всего тесто запущено: %d\n", srunner_ntests_run(sRunner));
    printf("Всего тестов провалено: %d\n", srunner_ntests_failed(sRunner));
    srunner_free(sRunner);
    return 0;
}