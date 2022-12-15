#include "s21_math_test.h"

START_TEST(test_pos_1) {
  double num = 134.5;
  double p = 1.4;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(test_pos_2) {
  double num = 134.5;
  double p = 20.5e-34;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(test_neg_pow_1) {
  double num = 563.23;
  double p = -42.;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(test_neg_num_odd_int_pow) {
  double num = -10.1;
  double p = -3.;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(test_neg_num_int_pow) {
  double num = -10.1;
  double p = 2.;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(test_neg_num_fract_pow) {
  double num = -10.1;
  double p = -1.5;
  ck_assert_ldouble_nan(s21_pow(num, p));
}
END_TEST

START_TEST(test_fractional_pow) {
  double num = 10.1;
  double p = 0.123;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(test_fractional_pow_neg_num) {
  double num = -27.45;
  double p = 1.0 / 3.0;
  ck_assert_ldouble_nan(s21_pow(num, p));
}
END_TEST

START_TEST(test_zero_power) {
  double nums[6] = {1.12, -34.45, S21_NAN, -S21_NAN, S21_INF, -S21_INF};
  double p = 0;
  int i = _i;
  ck_assert_ldouble_eq_tol(pow(nums[i], p), s21_pow(nums[i], p), 1e-6);
}
END_TEST

START_TEST(test_one_num) {
  double num = 1.0;
  double p[7] = {1, 1.23, -1.23, S21_NAN, -S21_NAN, S21_INF, -S21_INF};
  int i = _i;
  ck_assert_ldouble_eq_tol(pow(num, p[i]), s21_pow(num, p[i]), 1e-6);
}
END_TEST

START_TEST(test_one_power) {
  double num = 12.34;
  double p = 1;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(test_nan_power) {
  double nums[6] = {1.12, -34.45, S21_NAN, -S21_NAN, S21_INF, -S21_INF};
  double p = S21_NAN;
  int i = _i;
  ck_assert_ldouble_nan(s21_pow(nums[i], p));
}
END_TEST

START_TEST(test_nan_num) {
  double num = S21_NAN;
  double p[8] = {1, -1, -11.1, 11.1, S21_INF, -S21_INF, S21_NAN, -S21_NAN};
  int i = _i;
  ck_assert_ldouble_nan(s21_pow(num, p[i]));
}
END_TEST

START_TEST(test_neg_nan_power) {
  double nums[6] = {1.12, -34.45, S21_NAN, -S21_NAN, S21_INF, -S21_INF};
  double p = -S21_NAN;
  int i = _i;
  ck_assert_ldouble_nan(s21_pow(nums[i], p));
}
END_TEST

START_TEST(test_neg_nan_num) {
  double num = -S21_NAN;
  double p[8] = {1, -1, -11.1, 11.1, S21_INF, -S21_INF, S21_NAN, -S21_NAN};
  int i = _i;
  ck_assert_ldouble_nan(s21_pow(num, p[i]));
}
END_TEST

START_TEST(test_zero_neg_pow) {
  double num = 0;
  double p = -12;
  ck_assert_ldouble_infinite(s21_pow(num, p));
  ck_assert_ldouble_infinite(pow(num, p));
}

START_TEST(test_zero_pos_pow) {
  double num = 0;
  double p = 12;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}

START_TEST(test_minus_one_inf_pow) {
  double num = -1;
  ck_assert_ldouble_eq_tol(pow(num, S21_INF), s21_pow(num, S21_INF), 1e-6);
}

START_TEST(test_fract_num_neg_inf_pow) {
  double num = 0.123;
  double p = -S21_INF;
  ck_assert_ldouble_infinite(s21_pow(num, p));
  ck_assert_ldouble_infinite(pow(num, p));
}
END_TEST

START_TEST(test_fract_num_pos_inf_pow) {
  double num = 0.123;
  double p = S21_INF;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(test_num_neg_pos_pow) {
  double num = 13;
  double p = -S21_INF;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(test_fract_num_pos_pow) {
  double num = S21_NEGZERO;
  double p = 12;
  ck_assert_ldouble_eq(pow(num, p), s21_pow(num, p));
}
END_TEST

START_TEST(test_num_inf_pow) {
  double num = 13;
  double p = S21_INF;
  ck_assert_ldouble_infinite(s21_pow(num, p));
  ck_assert_ldouble_infinite(pow(num, p));
}
END_TEST

START_TEST(test_pos_inf_neg_pow) {
  double num = S21_INF;
  double p = -12;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(test_neg_inf_pos_pow) {
  double num = -S21_INF;
  double p = -13;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(test_neg_inf_pos_odd_pow) {
  double num = -S21_INF;
  double p = 13;
  ck_assert_ldouble_infinite(s21_pow(num, p));
  ck_assert_ldouble_infinite(pow(num, p));
}
END_TEST

START_TEST(test_neg_inf_neg_pow) {
  double num = -S21_INF;
  double p = -12;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(test_pos_inf_pos_pow) {
  double num = S21_INF;
  double p = 12;
  ck_assert_ldouble_infinite(s21_pow(num, p));
  ck_assert_ldouble_infinite(pow(num, p));
}
END_TEST

START_TEST(maximum) {
  double num = DBL_MAX;
  double p = -10;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

START_TEST(minimum) {
  double num = DBL_MIN;
  double p = 10;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), 1e-6);
}
END_TEST

Suite *suite_pow(void) {
  Suite *s = suite_create("suite_pow");
  TCase *tc = tcase_create("pow_tc");

  tcase_add_test(tc, test_pos_1);
  tcase_add_test(tc, test_pos_2);
  tcase_add_test(tc, test_neg_pow_1);
  tcase_add_test(tc, test_neg_num_odd_int_pow);
  tcase_add_test(tc, test_neg_num_int_pow);
  tcase_add_test(tc, test_neg_num_fract_pow);
  tcase_add_test(tc, test_fractional_pow);
  tcase_add_test(tc, test_fractional_pow_neg_num);
  tcase_add_loop_test(tc, test_zero_power, 0, 6);
  tcase_add_loop_test(tc, test_one_num, 0, 7);
  tcase_add_test(tc, test_one_power);
  tcase_add_loop_test(tc, test_nan_power, 0, 6);
  tcase_add_loop_test(tc, test_nan_num, 0, 8);
  tcase_add_loop_test(tc, test_neg_nan_power, 0, 6);
  tcase_add_loop_test(tc, test_neg_nan_num, 0, 8);
  tcase_add_test(tc, test_zero_neg_pow);
  tcase_add_test(tc, test_zero_pos_pow);
  tcase_add_test(tc, test_minus_one_inf_pow);
  tcase_add_test(tc, test_fract_num_neg_inf_pow);
  tcase_add_test(tc, test_fract_num_pos_inf_pow);
  tcase_add_test(tc, test_num_neg_pos_pow);
  tcase_add_test(tc, test_fract_num_pos_pow);
  tcase_add_test(tc, test_num_inf_pow);
  tcase_add_test(tc, test_pos_inf_neg_pow);
  tcase_add_test(tc, test_neg_inf_pos_pow);
  tcase_add_test(tc, test_neg_inf_pos_odd_pow);
  tcase_add_test(tc, test_neg_inf_neg_pow);
  tcase_add_test(tc, test_pos_inf_pos_pow);

  tcase_add_test(tc, maximum);
  tcase_add_test(tc, minimum);

  suite_add_tcase(s, tc);
  return s;
}