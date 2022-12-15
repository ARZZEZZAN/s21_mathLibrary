#include "s21_math.h"

long double s21_atan(double x) {
  int sign = 0, size = 0;
  long double res = 0, x2 = 0;
  if (x < 0.F) {
    x = -x;
    sign |= 1;
  }
  if (x > s21_pow(10, 7)) {
    x = s21_pow(10, 7);
  }
  if (x > 1.F) {
    x = 1.F / x;
    sign |= 2;
  }
  while (x > S21_PI_12) {  // сокращение области определения
    size++;
    res = 1.F / (x + S21_SQRT_3);
    x = ((x * S21_SQRT_3) - 1) * res;
  }
  x2 = s21_pow(x, 2);  // аппроксимация
  res = x * (0.55913709 / (1.4087812 + x2) + 0.60310579 -
             0.05160454 * x2);  // возвращение области определения в прежний вид
  while (size > 0) {
    res += S21_PI_6;
    size--;
  }
  (sign & 2) ? res = S21_PI_2 - res : res;  // инверсия
  (sign & 1) ? res = -res : res;            // знак
  return res;
}