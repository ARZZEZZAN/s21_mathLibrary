#include "s21_math.h"

long double s21_exp(double x) {
  long double res = 1.0;
  if (x == S21_INF) {
    res = S21_INF;
  } else if (x != x) {
    res = S21_NAN;
  } else if (x == -S21_INF) {
    res = 0;
  } else {
    int n = 1;
    long double a = x, sn = 1;
    if (x < 0.0) a = -x;
    for (int i = 0; i < 1600; i++) {
      sn *= a / n++;
      res += sn;
    }
    if (x < 0.0) res = 1 / res;
  }
  return res;
}
