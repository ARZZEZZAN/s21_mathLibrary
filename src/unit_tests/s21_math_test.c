#include "s21_math_test.h"

void run_tests(void) {
  Suite *list_cases[] = {
      suite_abs(),   suite_fabs(), suite_fmod(), suite_ceil(),
      suite_floor(), suite_sqrt(), suite_exp(),  suite_log(),
      suite_pow(),   suite_acos(), suite_asin(), suite_atan(),
      suite_cos(),   suite_sin(),  suite_tan(),  NULL};
  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 0) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;
  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
  sleep(1);
}

int main(void) {
  run_tests();
  return 0;
}