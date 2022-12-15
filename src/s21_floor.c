#include "s21_math.h"

// long double s21_floor(double x) {
//   long double res = 0;
//   if (s21_is_inf(x) || x == 0 || x == S21_NEGZERO || s21_is_nan(x)) {
//     res = x;
//   } else {
//     res = (long long int)x;
//     if ((long long int)x != x && x < 0) {
//       res = --x;
//     }
//   }
//   return res;
// }

long double s21_floor(double x) {
  long double floor_x = (long long int)x;
  if (s21_is_inf(x) || x == 0 || x == S21_NEGZERO || s21_is_nan(x)) {
    floor_x = x;
  } else {
    if (s21_fabs(x - floor_x) > 0. && s21_fabs(x) > 0.)
      if (x < 0.) {
        floor_x -= 1;
      }
  }

  return floor_x;
}