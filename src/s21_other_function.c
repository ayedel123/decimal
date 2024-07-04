#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = OK;  //как может возникнуть ошибка

  copyDecimal(result, &value);
  setSign(result, (getSign(&value) + 1) % 2);
  return error;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = OK;
  int scale = getScale(&value);
  (*result) = value;
  if (scale && !equalZero(value)) {
    s21_big_decimal big1 = toBigDecimal(value),
                    ten = toBigDecimal(intToDecimal(10, 0)), mod;

    while (scale > 0) {
      optiFineBaseDivBig(big1, ten, &big1, &mod);
      scale--;
    }
    // setBitBig(&big1,ADDITIONAL_SIGN_BIG_1,0);
    // setBitBig(&big1,ADDITIONAL_SIGN_BIG_2,0);
    // printDecimalBig();
    if (findHighestBitBig(big1) > LAST_MANTISA_BIT_DECIMAL)
      error = 1;
    else {
      *result = toNormalDecimal(big1);
      setScale(result, 0);
      setSign(result, getSign(&value));
    }
  }
  return error;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int error = OK;
  int sign = getSign(&value);
  if (sign == POSITIVE)
    s21_truncate(value, result);
  else {
    if (getScale(&value) != 0)
      error = s21_sub(value, intToDecimal(1, 0), &value);
    s21_truncate(value, result);
  }
  return error;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = OK;
  int sign = getSign(&value);
  int scale = getScale(&value);
  if (scale != 0) {
    setSign(&value, 0);
    s21_decimal tmp = value, tmpMod;

    error = s21_truncate(tmp, &tmp);

    if (!error) {
      tmpMod = tmp;
      error = s21_sub(value, tmpMod, &tmpMod);
      s21_decimal ultrTmp = intToDecimal(5, 0);
      setScale(&ultrTmp, 1);
      setSign(&ultrTmp, getSign(&value));
      if (s21_is_greater(tmpMod, ultrTmp)) {
        tmpMod = intToDecimal(1, 0);
        s21_add(tmp, tmpMod, &tmp);
      }
    }
    setSign(&tmp, sign);
    (*result) = tmp;

  } else

    copyDecimal(result, &value);
  if (!equalZero(*result)) setBit(result, SIGN_INDEX, sign);
  return error;
}