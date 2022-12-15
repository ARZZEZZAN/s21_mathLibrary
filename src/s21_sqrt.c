#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = 0;
  if (x < 0 || s21_is_nan(x)) {
    res = S21_NAN;
  } else if (s21_is_inf(x) || x <= S21_SQRT_EPS) {
    res = x;
  } else {
    res = s21_pow(x, 0.5);
  }
  return res;
}
