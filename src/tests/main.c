#include "s21_decimal_tests.h"

void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_tests(Suite *cases[]) {
  for (; *cases != NULL; cases++) run_testcase(*cases);
}

int main(void) {
  Suite *cases[] = {TEST_CASES, ARSENIY_TEST_CASES, NULL};
  //  Suite *cases[] = {ARSENIY_TEST_CASES, NULL};

  run_tests(cases);

  return 0;
}
