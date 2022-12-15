#include "s21_math.h"

long double s21_log(double x) {
  long double res = 0;
  if (x < 0 || x == -S21_INF || s21_is_nan(x)) {
    res = S21_NAN;
  } else if (x == 0) {
    res = -S21_INF;
  } else if (x == S21_INF) {
    res = S21_INF;
  } else if (x == 1) {
    res = 0;
  } else {
    double N = 0.0, P = x, A = 0;
    while (P >= S21_E) {
      P /= S21_E;
      N++;
    }
    N += (P / S21_E);
    P = x;
    int j = 0;
    do {
      double L, R;
      A = N;
      L = (P / (s21_exp(N - 1.0)));
      R = ((N - 1.0) * S21_E);
      N = ((L + R) / S21_E);
      j++;
    } while (N != A && j < 10000);
    res = N;
  }
  return res;
}