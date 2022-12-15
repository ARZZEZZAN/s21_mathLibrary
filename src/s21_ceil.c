#include "s21_math.h"

// long double s21_ceil(double x) {
//   long double res = 0;
//   if (s21_is_inf(x) || x == 0 || x == S21_NEGZERO || s21_is_nan(x)) {
//     res = x;
//   } else {
//     res = (signed long long int)x;
//     if ((signed long long int)x != x && x > 0) {
//       res = ++x;
//     }
//   }
//   return res;
// }

long double s21_ceil(double x) {
  long double ceil_x = (long long int)x;
  if (s21_is_inf(x) || x == 0 || x == S21_NEGZERO || s21_is_nan(x)) {
    ceil_x = x;
  } else {
    if (s21_fabs(x) > 0. && x != ceil_x)
      if (x > 0.) {
        ceil_x += 1;
      }
  }

  return ceil_x;
}
