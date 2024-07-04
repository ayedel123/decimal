#include <math.h>

#include "s21_decimal.h"

long long int iabs(long long int number) {
  if (number < 0) {
    return -number;
  } else {
    return number;
  }
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  initDecimal(dst);
  setSign(dst, src < 0);
  setNum(dst, iabs(src));
  return OK;
}

int getFractionPartLength(double num) {
  int count = 0;
  num = fabs(num);
  num = modf(num, &num) * 10;
  for (int i = 1; i < 8; i++) {
    int fractionTen = (int)fmod(num, 10);
    if (fractionTen != 0) count = i;
    num = modf(num, &num) * 10;
  }
  return count;
}

float roundFloat(float number, int scale) {
  return (float)(number + (powl(0.1, scale + 1) * 5));
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (fabsf(src) == INFINITY || (fabsf(src) - MAX_DECIMAL) == 0 ||
      fabsf(src) < 1e-28 || fabsf(src) == 0.0 || isnan(src)) {
    return ERROR_CONVERTING;
  }

  initDecimal(dst);

  if (src < 0) {
    src = fabsf(src);
    setSign(dst, NEGATIVE);
  }

  int mantissaDegree = 0;

  src = roundFloat(src, 7);
  mantissaDegree += getFractionPartLength((double)src);

  setScale(dst, mantissaDegree);

  src *= powf(10.0f, (float)mantissaDegree);
  setNum(dst, src);

  return OK;
}

int s21_from_decimal_to_double(s21_decimal src, double *dst) {
  if (dst == NULL || getScale(&src) > 28) {
    return ERROR_CONVERTING;
  }

  *dst = ((double)getNum(&src));
  *dst /= pow(10.0, (double)getScale(&src));
  if (getSign(&src) == NEGATIVE) {
    *dst = -*dst;
  }
  return OK;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  double number = 0;

  int res = s21_from_decimal_to_double(src, &number);
  if (number > MAX_INT || number < MIN_INT || res != OK) {
    res = ERROR_CONVERTING;
  } else {
    *dst = (int)number;
  }

  return res;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  double number = 0;

  if (dst == NULL) {
    return ERROR_CONVERTING;
  }

  int res = s21_from_decimal_to_double(src, &number);
  if (res == OK) *dst = (float)number;

  return res;
}
