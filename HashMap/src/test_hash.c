#include "test_hash.h"

#include <check.h>

START_TEST(createTableIsPositiv) {
  HashTable *table = createTable(10);
  _ck_assert_ptr(table, !=, ERROR);
  removeHash(&table);
}
END_TEST

START_TEST(createTableIsLarge) {
  HashTable *table = createTable(100000);
  _ck_assert_ptr(table, !=, ERROR);
  removeHash(&table);
}
END_TEST

START_TEST(createTableIsNegativ) {
  HashTable *table = createTable(-49);
  if (table) {
    removeHash(&table);
  }
  _ck_assert_ptr(table, ==, ERROR);
}
END_TEST

START_TEST(createTableIsNull) {
  HashTable *table = createTable(0);
  _ck_assert_ptr(table, ==, ERROR);
  if (table) {
    removeHash(&table);
  }
}
END_TEST

START_TEST(insertNormal) {
  HashTable *table = createTable(10);
  insert(table, "key1", 98);
  insert(table, "key6", 67);
  insert(table, "key8", 19082);
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key8"), OK);
  AnsHash *ansOne = search(table, "key1");
  AnsHash *ansTwo = search(table, "key6");
  AnsHash *ansThree = search(table, "key8");
  _ck_assert_ptr(ansOne->values, !=, NULL);
  _ck_assert_ptr(ansTwo->values, !=, NULL);
  _ck_assert_ptr(ansThree->values, !=, NULL);
  removeHash(&table);
  free(ansOne);
  free(ansTwo);
  free(ansThree);
}
END_TEST

START_TEST(insertIsNotTable) {
  HashTable *table = createTable(-78);
  insert(table, "key1", 98);
  insert(table, "key6", 67);
  insert(table, "key8", 19082);
  ck_assert_int_eq(checkBacet(table, "key1"), ERROR);
  ck_assert_int_eq(checkBacet(table, "key6"), ERROR);
  ck_assert_int_eq(checkBacet(table, "key8"), ERROR);
  AnsHash *ansOne = NULL;
  AnsHash *ansTwo = NULL;
  AnsHash *ansThree = NULL;
  ansOne = search(table, "key1");
  ansTwo = search(table, "key6");
  ansThree = search(table, "key8");
  _ck_assert_ptr(ansOne, ==, NULL);
  _ck_assert_ptr(ansTwo, ==, NULL);
  _ck_assert_ptr(ansThree, ==, NULL);
  if (table) {
    removeHash(&table);
  }
}
END_TEST

START_TEST(insertIsNotKey) {
  HashTable *table = createTable(10);
  insert(table, "", 98);
  insert(table, NULL, 67);
  insert(table, NULL, 19082);
  removeHash(&table);
}
END_TEST

START_TEST(insertIsNotValue) {
  HashTable *table = createTable(10);
  insert(table, "key1", 0);
  insert(table, "key6", 0);
  insert(table, "key8", 0);
  ck_assert_int_eq(checkBacet(table, "key1"), ERROR);
  ck_assert_int_eq(checkBacet(table, "key6"), ERROR);
  ck_assert_int_eq(checkBacet(table, "key8"), ERROR);
  removeHash(&table);
}
END_TEST

START_TEST(addBacetNormal) {
  HashTable *table = createTable(10);
  insert(table, "key1", 898);
  insert(table, "key6", 7163);
  insert(table, "key8", 8172);
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key8"), OK);
  ck_assert_int_eq(table->valBacets, 10);
  addBacet(table, 20);
  ck_assert_int_eq(table->valBacets, 20);
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key8"), OK);
  removeHash(&table);
}
END_TEST

START_TEST(addBacetIsNotTable) {
  HashTable *table = createTable(-78);
  insert(table, "key1", 898);
  insert(table, "key6", 7163);
  insert(table, "key8", 8172);
  ck_assert_int_eq(checkBacet(table, "key1"), ERROR);
  ck_assert_int_eq(checkBacet(table, "key6"), ERROR);
  ck_assert_int_eq(checkBacet(table, "key8"), ERROR);
  addBacet(table, 20);
  ck_assert_int_eq(checkBacet(table, "key1"), ERROR);
  ck_assert_int_eq(checkBacet(table, "key6"), ERROR);
  ck_assert_int_eq(checkBacet(table, "key8"), ERROR);
  if (table) {
    removeHash(&table);
  }
}
END_TEST

START_TEST(addBacetIsNegativeValue) {
  HashTable *table = createTable(10);
  insert(table, "key1", 898);
  insert(table, "key6", 7163);
  insert(table, "key8", 8172);
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key8"), OK);
  ck_assert_int_eq(table->valBacets, 10);
  addBacet(table, -76);
  ck_assert_int_eq(table->valBacets, 10);
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key8"), OK);
  removeHash(&table);
}
END_TEST

START_TEST(addBacetNullValue) {
  HashTable *table = createTable(10);
  insert(table, "key1", 898);
  insert(table, "key6", 7163);
  insert(table, "key8", 8172);
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key8"), OK);
  ck_assert_int_eq(table->valBacets, 10);
  addBacet(table, 0);
  ck_assert_int_eq(table->valBacets, 10);
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key8"), OK);
  removeHash(&table);
}
END_TEST

START_TEST(addBacetLargeValue) {
  HashTable *table = createTable(10);
  insert(table, "key1", 898);
  insert(table, "key6", 7163);
  insert(table, "key8", 8172);
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key8"), OK);
  ck_assert_int_eq(table->valBacets, 10);
  addBacet(table, 100000);
  ck_assert_int_eq(table->valBacets, 100000);
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key8"), OK);
  removeHash(&table);
}
END_TEST

START_TEST(rmForHashNormal) {
  HashTable *table = createTable(10);
  insert(table, "key1", 898);
  insert(table, "key6", 982);
  insert(table, "key76", 782);
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key76"), OK);
  rmForHash(table, "key6");
  ck_assert_int_eq(checkBacet(table, "key6"), ERROR);
  removeHash(&table);
}
END_TEST

START_TEST(rmForHashIsNotHash) {
  HashTable *table = createTable(10);
  insert(table, "key1", 898);
  insert(table, "key6", 982);
  insert(table, "key76", 782);
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key76"), OK);
  rmForHash(table, "jvjnkjdvs");
  rmForHash(table, "hbbjnkv");
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key76"), OK);
  removeHash(&table);
}
END_TEST

START_TEST(rmForHashIsNotTable) {
  HashTable *table = createTable(-76);
  insert(table, "key1", 78);
  rmForHash(table, "key1");
  _ck_assert_ptr(table, ==, NULL);
  if (table) {
    removeHash(&table);
  }
}
END_TEST

START_TEST(removeHashNormal) {
  HashTable *table = createTable(10);
  _ck_assert_ptr(table, !=, NULL);
  removeHash(&table);
  _ck_assert_ptr(table, ==, NULL);
}
END_TEST

START_TEST(removeHashIsNotTable) {
  HashTable *table = createTable(-76);
  _ck_assert_ptr(table, ==, NULL);
  removeHash(&table);
  _ck_assert_ptr(table, ==, NULL);
}
END_TEST

START_TEST(checkBacetNormal) {
  HashTable *table = createTable(10);
  insert(table, "key1", 898);
  insert(table, "key6", 982);
  insert(table, "key76", 782);
  ck_assert_int_eq(checkBacet(table, "key1"), OK);
  ck_assert_int_eq(checkBacet(table, "key6"), OK);
  ck_assert_int_eq(checkBacet(table, "key76"), OK);
  removeHash(&table);
}
END_TEST

START_TEST(checkBacetIsNotTable) {
  HashTable *table = createTable(-76);
  insert(table, "key1", 898);
  insert(table, "key6", 982);
  insert(table, "key76", 782);
  ck_assert_int_eq(checkBacet(table, "key1"), ERROR);
  ck_assert_int_eq(checkBacet(table, "ke6"), ERROR);
  ck_assert_int_eq(checkBacet(table, "key76"), ERROR);
  removeHash(&table);
}
END_TEST

START_TEST(checkBacetIsNotBacet) {
  HashTable *table = createTable(10);
  insert(table, "key1", 898);
  insert(table, "key6", 982);
  insert(table, "key76", 782);
  ck_assert_int_eq(checkBacet(table, "khvfbfmc"), ERROR);
  ck_assert_int_eq(checkBacet(table, "72uqbwfj"), ERROR);
  ck_assert_int_eq(checkBacet(table, "kvmma"), ERROR);
  removeHash(&table);
}
END_TEST

START_TEST(searchNormal) {
  HashTable *table = createTable(10);
  insert(table, "key1", 898);
  insert(table, "key6", 982);
  insert(table, "key76", 782);
  AnsHash *one = search(table, "key1");
  AnsHash *two = search(table, "key6");
  AnsHash *three = search(table, "key76");
  _ck_assert_ptr(one, !=, NULL);
  _ck_assert_ptr(two, !=, NULL);
  _ck_assert_ptr(three, !=, NULL);
  _ck_assert_ptr(one->values, !=, NULL);
  _ck_assert_ptr(two->values, !=, NULL);
  _ck_assert_ptr(three->values, !=, NULL);
  removeHash(&table);
  free(one);
  free(two);
  free(three);
}
END_TEST

START_TEST(searchIsNotTable) {
  HashTable *table = createTable(-76);
  insert(table, "key1", 898);
  insert(table, "key6", 982);
  insert(table, "key76", 782);
  AnsHash *one = search(table, "key1");
  AnsHash *two = search(table, "key6");
  AnsHash *three = search(table, "key76");
  _ck_assert_ptr(one, ==, NULL);
  _ck_assert_ptr(two, ==, NULL);
  _ck_assert_ptr(three, ==, NULL);
  if (table) removeHash(&table);
  if (one) free(one);
  if (two) free(two);
  if (three) free(three);
}
END_TEST

START_TEST(searchIsNotHash) {
  HashTable *table = createTable(10);
  insert(table, "key1", 898);
  insert(table, "key6", 982);
  insert(table, "key76", 782);
  AnsHash *one = search(table, "eavcd");
  AnsHash *two = search(table, "nafjk");
  AnsHash *three = search(table, "navkmcw");
  _ck_assert_ptr(one, ==, NULL);
  _ck_assert_ptr(two, ==, NULL);
  _ck_assert_ptr(three, ==, NULL);
  removeHash(&table);
  if (one) free(one);
  if (two) free(two);
  if (three) free(three);
}
END_TEST

Suite *HashTableTest(void) {
  Suite *suite = suite_create("HashTable");
  TCase *tcase = tcase_create("HashTable");

  // Создание Таблицы
  tcase_add_test(tcase, createTableIsPositiv);
  tcase_add_test(tcase, createTableIsLarge);
  tcase_add_test(tcase, createTableIsNegativ);
  tcase_add_test(tcase, createTableIsNull);

  // Вставка элемента в таблицу
  // P.S гарантируеться что элементы не равны нулю
  tcase_add_test(tcase, insertNormal);
  tcase_add_test(tcase, insertIsNotTable);
  tcase_add_test(tcase, insertIsNotKey);
  tcase_add_test(tcase, insertIsNotValue);

  // Изменение количества Бакетов
  tcase_add_test(tcase, addBacetNormal);
  tcase_add_test(tcase, addBacetIsNotTable);
  tcase_add_test(tcase, addBacetIsNegativeValue);
  tcase_add_test(tcase, addBacetNullValue);
  tcase_add_test(tcase, addBacetLargeValue);

  // Удаление бакета
  tcase_add_test(tcase, rmForHashNormal);
  tcase_add_test(tcase, rmForHashIsNotHash);
  tcase_add_test(tcase, rmForHashIsNotTable);

  // Удаление таблицы
  tcase_add_test(tcase, removeHashNormal);
  tcase_add_test(tcase, removeHashIsNotTable);

  // Проверка наличия бакета
  tcase_add_test(tcase, checkBacetNormal);
  tcase_add_test(tcase, checkBacetIsNotBacet);
  tcase_add_test(tcase, checkBacetIsNotTable);

  // Поиск по таблице
  tcase_add_test(tcase, searchNormal);
  tcase_add_test(tcase, searchIsNotHash);
  tcase_add_test(tcase, searchIsNotTable);

  suite_add_tcase(suite, tcase);

  return suite;
}

int main() {
  Suite *suite = HashTableTest();
  SRunner *sRunner = srunner_create(suite);
  srunner_set_fork_status(sRunner, CK_NOFORK);
  srunner_run_all(sRunner, CK_VERBOSE);
  int total_tests = srunner_ntests_run(sRunner);
  int failed_tests = srunner_ntests_failed(sRunner);
  srunner_free(sRunner);
  printf("Всего выполнено тестов: %d\n", total_tests);
  printf("Провалено тестов: %d\n", failed_tests);
  return 0;
}
