#include "s21_math_test.h"

START_TEST(test_atan_positive) {
  double x = 0.4;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_negative) {
  double x = -0.4;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_zero) {
  double x = 0;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_one) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_one_negative) {
  double x = -1;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_huge_positive) {
  double x = 100000000.0;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_huge_negative) {
  double x = -1000000000000000;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_big_mantissa) {
  double x = 0.923456789012345678901234567890;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_nan) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_atan(x));
}
END_TEST

START_TEST(test_atan_inf) {
  double x = S21_INF;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_neg_inf) {
  double x = -S21_INF;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_loop_values) {
  double i = _i;
  ck_assert_ldouble_eq_tol(atan(i / 20.0), s21_atan(i / 20.0), 1e-6);
}
END_TEST

// START_TEST(test_atan_dbl_max) {
//   double x = DBL_MAX;
//   ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
// }
// END_TEST

// START_TEST(test_atan_dbl_min) {
//   double x = DBL_MIN;
//   ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
// }
// END_TEST

Suite *suite_atan(void) {
  Suite *s = suite_create("suite_atan");
  TCase *tc = tcase_create("atan_tc");

  tcase_add_test(tc, test_atan_positive);
  tcase_add_test(tc, test_atan_negative);
  tcase_add_test(tc, test_atan_zero);
  tcase_add_test(tc, test_atan_one);
  tcase_add_test(tc, test_atan_negative);
  tcase_add_test(tc, test_atan_one_negative);
  tcase_add_test(tc, test_atan_huge_positive);
  tcase_add_test(tc, test_atan_huge_negative);
  tcase_add_test(tc, test_atan_big_mantissa);
  tcase_add_test(tc, test_atan_nan);
  tcase_add_test(tc, test_atan_inf);
  tcase_add_test(tc, test_atan_neg_inf);
  tcase_add_loop_test(tc, test_atan_loop_values, -10, 10);
  // tcase_add_test(tc, test_atan_dbl_max);
  // tcase_add_test(tc, test_atan_dbl_min);

  suite_add_tcase(s, tc);
  return s;
}