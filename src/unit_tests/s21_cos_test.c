#include "s21_math_test.h"

START_TEST(test_cos_positive) {
  double x = 0.4;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
}
END_TEST

START_TEST(test_cos_negative) {
  double x = -0.4;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
}
END_TEST

START_TEST(test_cos_zero) {
  double x = 0;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
}
END_TEST

START_TEST(test_cos_one) {
  double x = 1;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
}
END_TEST

START_TEST(test_cos_one_negative) {
  double x = -1;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
}
END_TEST

START_TEST(test_cos_huge_positive) {
  double x = 598987986;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
}
END_TEST

START_TEST(test_cos_huge_negative) {
  double x = -5938409234;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
}
END_TEST

START_TEST(test_cos_big_mantissa) {
  double x = 0.123456789012345678901234567890;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
}
END_TEST
START_TEST(test_cos_two_pi) {
  double x = S21_PI;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
}
END_TEST

START_TEST(test_cos_eps_positive) {
  double x = 1 + 1e-6;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
}
END_TEST

START_TEST(test_cos_eps_negative) {
  double x = -1 - 1e-6;
  ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), 1e-6);
}
END_TEST

START_TEST(test_cos_inf) { ck_assert_ldouble_nan(s21_cos(S21_INF)); }
END_TEST

START_TEST(test_cos_nan) { ck_assert_ldouble_nan(s21_cos(S21_NAN)); }
END_TEST

START_TEST(test_cos_minus_inf) { ck_assert_ldouble_nan(s21_cos(-S21_INF)); }
END_TEST

START_TEST(test_cos_fractional_pi_values) {
  int i = _i;
  if (i != 0) {
    ck_assert_ldouble_eq_tol(cos(S21_PI / i), s21_cos(S21_PI / i), 1e-6);
  } else {
    ck_assert_ldouble_nan(s21_cos(S21_PI / i));
  }
}
END_TEST

START_TEST(test_cos_whole_pi_values) {
  int i = _i;
  ck_assert_ldouble_eq_tol(cos(S21_PI * i), s21_cos(S21_PI * i), 1e-6);
}
END_TEST

Suite *suite_cos(void) {
  Suite *s = suite_create("suite_cos");
  TCase *tc = tcase_create("cos_tc");
  tcase_add_test(tc, test_cos_positive);
  tcase_add_test(tc, test_cos_negative);
  tcase_add_test(tc, test_cos_zero);
  tcase_add_test(tc, test_cos_one);
  tcase_add_test(tc, test_cos_negative);
  tcase_add_test(tc, test_cos_one_negative);
  tcase_add_test(tc, test_cos_huge_positive);
  tcase_add_test(tc, test_cos_huge_negative);
  tcase_add_test(tc, test_cos_big_mantissa);
  tcase_add_test(tc, test_cos_eps_positive);
  tcase_add_test(tc, test_cos_eps_negative);
  tcase_add_test(tc, test_cos_inf);
  tcase_add_test(tc, test_cos_nan);
  tcase_add_test(tc, test_cos_minus_inf);
  tcase_add_test(tc, test_cos_two_pi);
  tcase_add_loop_test(tc, test_cos_fractional_pi_values, -10, 10);
  tcase_add_loop_test(tc, test_cos_whole_pi_values, -10, 10);
  suite_add_tcase(s, tc);
  return s;
}
