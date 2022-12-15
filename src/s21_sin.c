#include "s21_math.h"

long double s21_sin(double x) {
  long double res;
  if (s21_is_inf(x) || s21_is_nan(x)) {
    res = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    while (x > S21_PI) {
      x -= 2 * S21_PI;
    }

    while (x < -S21_PI) {
      x += 2 * S21_PI;
    }
    res = x;
    int fact = 1;
    long double temp = x;
    while (s21_fabs(temp) > S21_EPS) {
      temp = (-temp * x * x) / ((2 * fact + 1) * (2 * fact));
      res += temp;
      fact++;
    }
  }
  return res;
}