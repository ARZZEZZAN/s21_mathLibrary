#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double res = 0;
  int tmp = 0;
  if (base == 1 || exp == 0 || (base == -1 && (s21_is_inf(exp)))) {
    res = 1;
  } else if ((s21_fabs(base) < 1 && exp == -S21_INF) ||
             (s21_fabs(base) > 1 && exp == S21_INF) ||
             (base == -S21_INF &&
              ((exp > 0 && (int)exp % 2 == 0) || exp == S21_INF)) ||
             (base == S21_INF && exp > 0)) {
    res = S21_INF;
  } else if ((base < 0 && (int)exp - exp != 0) ||
             (base != base && exp != exp)) {
    res = S21_NAN;
  } else if ((base == 0 && exp > 0) ||
             (s21_fabs(base) > 1 && exp == -S21_INF) ||
             (s21_fabs(base) < 1 && exp == S21_INF) ||
             (base == S21_NEGZERO && (exp > 0 && (int)exp % 2 == 0)) ||
             (base == -S21_INF && (exp < 0 && (int)exp % 2 == 0)) ||
             (base == S21_INF && exp < 0)) {
    res = 0;
  } else if ((base == S21_NEGZERO && (exp > 0 && (int)exp % 2 != 0)) ||
             (base == -S21_INF && (exp < 0 && (int)exp % 2 != 0))) {
    res = S21_NEGZERO;
  } else if (base == -S21_INF && (exp > 0 && (int)exp % 2 != 0)) {
    res = -S21_INF;
  } else {
    if (base < 0) {
      if ((int)exp % 2 != 0) {
        tmp = 1;
      }
      base = s21_fabs(base);
    }
    res = tmp ? -s21_exp(exp * s21_log(base)) : s21_exp(exp * s21_log(base));
  }
  return res;
}
