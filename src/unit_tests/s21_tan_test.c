#include "s21_math_test.h"

START_TEST(test_tan_positive) {
  double x = 0.4;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(test_tan_negative) {
  double x = -0.4;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(test_tan_zero) {
  double x = 0;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(test_tan_one) {
  double x = 1;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(test_tan_one_negative) {
  double x = -1;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(test_tan_huge_positive) {
  double x = 400000.23;
  /* 598987986; */
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(test_tan_huge_negative) {
  double x = -400000.23;
  /* 5938409234; */
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(test_tan_big_mantissa) {
  double x = 0.123456789012345678901234567890;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST
START_TEST(test_tan_two_pi) {
  double x = S21_PI;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(test_tan_eps_positive) {
  double x = 1 + 1e-6;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(test_tan_eps_negative) {
  double x = -1 - 1e-6;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(test_tan_inf) { ck_assert_ldouble_nan(s21_tan(S21_INF)); }
END_TEST

START_TEST(test_tan_nan) { ck_assert_ldouble_nan(s21_tan(S21_NAN)); }
END_TEST

START_TEST(test_tan_minus_inf) { ck_assert_ldouble_nan(s21_tan(-S21_INF)); }
END_TEST
START_TEST(test_tan_fractional_pi_values) {
  int i = _i;
  if (i != 2 && i != -2) {
    if (i != 0) {
      ck_assert_ldouble_eq_tol(tan(S21_PI / i), s21_tan(S21_PI / i), 1e-6);
    } else {
      ck_assert_ldouble_nan(s21_tan(S21_PI / i));
    }
  }
}
END_TEST
START_TEST(test_tan_whole_pi_values) {
  int i = _i;
  ck_assert_ldouble_eq_tol(tan(S21_PI * i), s21_tan(S21_PI * i), 1e-6);
}
END_TEST

Suite *suite_tan(void) {
  Suite *s = suite_create("suite_tan");
  TCase *tc = tcase_create("tan_tc");

  tcase_add_test(tc, test_tan_positive);
  tcase_add_test(tc, test_tan_negative);
  tcase_add_test(tc, test_tan_zero);
  tcase_add_test(tc, test_tan_one);
  tcase_add_test(tc, test_tan_negative);
  tcase_add_test(tc, test_tan_one_negative);
  tcase_add_test(tc, test_tan_huge_positive);
  tcase_add_test(tc, test_tan_huge_negative);
  tcase_add_test(tc, test_tan_big_mantissa);
  tcase_add_test(tc, test_tan_eps_positive);
  tcase_add_test(tc, test_tan_eps_negative);
  tcase_add_test(tc, test_tan_inf);
  tcase_add_test(tc, test_tan_nan);
  tcase_add_test(tc, test_tan_minus_inf);
  tcase_add_test(tc, test_tan_two_pi);
  tcase_add_loop_test(tc, test_tan_fractional_pi_values, -10, 10);
  tcase_add_loop_test(tc, test_tan_whole_pi_values, -10, 10);
  suite_add_tcase(s, tc);
  return s;
}