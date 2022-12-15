#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = (long long int)x;
  if (s21_is_inf(x) || x == 0 || x == S21_NEGZERO || s21_is_nan(x)) {
    res = x;
  } else {
    if (s21_fabs(x) > 0. && x != res)
      if (x > 0.) {
        res += 1;
      }
  }

  return res;
}
