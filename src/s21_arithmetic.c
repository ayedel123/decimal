#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int scale1 = getScale(&value_1);
  int scale2 = getScale(&value_2);

  if (scale1 > 28 || scale2 > 28) return 2;

  s21_big_decimal big1, big2, bigRes;
  int errorCode = 0;
  int scale = 0;

  clearDecimal(result);
  clearBigDecimal(&bigRes);

  normalizeToBigDecimal(value_1, value_2, &big1, &big2, &scale);

  errorCode = baseAddBig(big1, big2, &bigRes);

  if (errorCode || findHighestBitBig(bigRes) > LAST_MANTISA_BIT_DECIMAL) {
    errorCode = roundBig(&bigRes, scale);
  } else
    setEpsilonBig(&bigRes, scale);

  if (!errorCode) {
    *result = toNormalDecimal(bigRes);
    if (equalZero(*result)) setSign(result, 0);
  }

  return errorCode;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  setSign(&value_2, (getSign(&value_2) + 1) % 2);
  return s21_add(value_1, value_2, result);
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int scale1 = getScale(&value_1);
  int scale2 = getScale(&value_2);
  clearDecimal(result);
  if (scale1 > 28 || scale2 > 28) return 2;
  s21_big_decimal big1 = toBigDecimal(value_1), big2 = toBigDecimal(value_2),
                  bigRes;

  baseMulBig(big1, big2, &bigRes);

  int errorCode = roundBig(&bigRes, scale1 + scale2);
  *result = toNormalDecimal(bigRes);
  return errorCode;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int scale1 = getScale(&value_1);
  int scale2 = getScale(&value_2);
  int scale = 0;
  clearDecimal(result);

  if (scale1 > 28 || scale2 > 28) return 2;
  if (equalZero(value_2)) return 3;

  s21_big_decimal big1, big2, bigRes, mod,
      ten = toBigDecimal(intToDecimal(10, 0)), tmpBigres;

  clearBigDecimal(&tmpBigres);
  normalizeToBigDecimal(value_1, value_2, &big1, &big2, &scale);

  int errorCode = baseDivBig(big1, big2, &bigRes, &mod);
  scale = 0;

  while (!equalZeroBig(mod) && scale < 33) {
    while (baseCompareBig(mod, big2) > 1 && !errorCode) {
      baseMulBig(bigRes, ten, &bigRes);
      baseMulBig(mod, ten, &mod);
      scale++;
    }

    errorCode = optiFineBaseDivBig(mod, big2, &tmpBigres, &mod);
    baseAddBig(bigRes, tmpBigres, &bigRes);
  }

  errorCode = roundBig(&bigRes, scale);
  scale = getEpsilonBig(&bigRes);

  if (!errorCode && scale > 0) {
    scale = cutZeroes(&bigRes, scale);
  }
  if (equalZeroBig(bigRes)) {
    scale = 0;
  }
  setEpsilonBig(&bigRes, scale);

  *result = toNormalDecimal(bigRes);

  return errorCode;
}
