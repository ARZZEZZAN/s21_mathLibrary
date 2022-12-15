#include "s21_math.h"

long double s21_asin(double x) {
  long double res = 0;
  if ((x > 1.F) || x < -1.F) {
    res = S21_NAN;
  } else {
    x /= s21_sqrt(1.F - x * x);
    res = s21_atan(x);
  }
  return res;
}