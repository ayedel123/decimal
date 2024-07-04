#include <math.h>
#include <stdio.h>

#include "s21_decimal.h"

int s21_is_less(s21_decimal first, s21_decimal second) {
  int result = 0;
  int sign1 = getSign(&first);
  int sign2 = getSign(&second);
  // writeDecimalInFile(first, "tests/manual_test_py/test_data.txt");
  // writeDecimalInFile(second, "tests/manual_test_py/test_data.txt");
  if (s21_is_equal(first, second) == TRUE)
    result = FALSE;
  else if (sign1 == POSITIVE && sign2 == NEGATIVE) {
    result = FALSE;
  } else if (sign1 == NEGATIVE && sign2 == POSITIVE) {
    result = TRUE;
  } else {
    s21_big_decimal big1;
    s21_big_decimal big2;
    int scale = 0;
    normalizeToBigDecimal(first, second, &big1, &big2, &scale);
    setSignBig(&big1, 0);
    setSignBig(&big2, 1);
    baseAddBig(big1, big2, &big1);
    if (getSignBig(&big1) == NEGATIVE) {
      result = TRUE;
    } else
      result = FALSE;

    if (sign1 == NEGATIVE) {
      result = !result;
    }
  }
  return result;
}

int s21_is_equal(s21_decimal first, s21_decimal second) {
  int result = FALSE;
  int sign1 = getSign(&first);
  int sign2 = getSign(&second);
  if (equalZero(first) && equalZero(second)) {
    result = TRUE;
  } else if (sign1 != sign2) {
    result = FALSE;
  } else {
    s21_big_decimal big1;
    s21_big_decimal big2;
    int scale = 0;
    normalizeToBigDecimal(first, second, &big1, &big2, &scale);

    setSignBig(&big2, !getSignBig(&big2));
    baseAddBig(big1, big2, &big1);
    if (equalZeroBig(big1)) result = TRUE;
  }

  return result;
}

int s21_is_less_or_equal(s21_decimal first, s21_decimal second) {
  int result = FALSE;
  if (s21_is_less(first, second) || s21_is_equal(first, second)) result = TRUE;
  return result;
}

int s21_is_greater(s21_decimal first, s21_decimal second) {
  int result = TRUE;
  if (s21_is_less_or_equal(first, second)) result = FALSE;
  return result;
}

int s21_is_greater_or_equal(s21_decimal first, s21_decimal second) {
  int result = TRUE;
  if (s21_is_less(first, second)) result = FALSE;
  return result;
}

int s21_is_not_equal(s21_decimal first, s21_decimal second) {
  int result = TRUE;
  if (s21_is_equal(first, second)) result = FALSE;
  return result;
}
