#include "s21_math_test.h"

START_TEST(test_pos) {
  double x = 24.67;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST

START_TEST(maximum) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq(exp(x), s21_exp(x));
}
END_TEST

START_TEST(minimum) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq(exp(x), s21_exp(x));
}
END_TEST

START_TEST(int_max) {
  double x = INT_MAX;
  ck_assert_ldouble_eq(exp(x), s21_exp(x));
}
END_TEST

START_TEST(test_pos_less_than_one) {
  double x = 7.345e-29;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}

START_TEST(test_neg_less_than_one) {
  double x = -0.767;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}

START_TEST(test_neg) {
  double x = -13.567;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST

START_TEST(test_zero) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST

START_TEST(test_nan_pos) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_exp(x));
}
END_TEST

START_TEST(test_nan_neg) {
  double x = S21_NEGZERO;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST

START_TEST(test_inf_pos) {
  double x = S21_INF;
  ck_assert_ldouble_eq(exp(x), s21_exp(x));
}
END_TEST

START_TEST(test_inf_neg) {
  double x = -S21_INF;
  ck_assert_ldouble_eq(exp(x), s21_exp(x));
}
END_TEST

Suite *suite_exp(void) {
  Suite *s = suite_create("suite_exp");
  TCase *tc = tcase_create("exp_tc");

  tcase_add_test(tc, test_pos);
  tcase_add_test(tc, maximum);
  tcase_add_test(tc, minimum);
  tcase_add_test(tc, int_max);
  tcase_add_test(tc, test_neg);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_pos_less_than_one);
  tcase_add_test(tc, test_neg_less_than_one);
  tcase_add_test(tc, test_nan_pos);
  tcase_add_test(tc, test_nan_neg);
  tcase_add_test(tc, test_inf_pos);
  tcase_add_test(tc, test_inf_neg);

  suite_add_tcase(s, tc);
  return s;
}