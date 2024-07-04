#include "s21_decimal_utils.h"

void writeDecimalInFile(s21_decimal value, const char *fileName) {
  FILE *file = fopen(fileName, "a");

  if (file) {
    for (int i = 127; i >= 0; i--) {
      int bit = getBit(&value, i);
      fprintf(file, "%d", bit);
    }
    fprintf(file, "\n");
    fclose(file);
  }
}

s21_big_decimal toBigDecimal(s21_decimal value) {
  s21_big_decimal res;
  clearBigDecimal(&res);
  for (int i = 0; i < 3; i++) res.bits[i] = value.bits[i];
  for (int i = 3; i < 7; i++) res.bits[i] = 0;
  res.bits[7] = value.bits[3];
  setBitBig(&res, ADDITIONAL_SIGN_BIG_1, getSign(&value));
  setBitBig(&res, ADDITIONAL_SIGN_BIG_2, getSign(&value));
  setSignBig(&res, getSign(&value));

  return res;
}

s21_decimal toNormalDecimal(s21_big_decimal value) {
  s21_decimal res;
  for (int i = 0; i < 3; i++) res.bits[i] = value.bits[i];
  res.bits[3] = value.bits[7];
  setBit(&res, ADDITIONAL_SIGN_1, 0);
  setBit(&res, ADDITIONAL_SIGN_2, 0);
  return res;
}

void clearBigDecimal(s21_big_decimal *value) {
  for (int i = 0; i < 8; i++) value->bits[i] = 0;
}

void clearDecimal(s21_decimal *value) {
  for (int i = 0; i < 4; i++) value->bits[i] = 0;
}

s21_big_decimal returnCode(s21_big_decimal value) {
  s21_big_decimal res;
  for (int i = 0; i < 7; i++) {
    res.bits[i] = ~value.bits[i];
  }
  res.bits[7] = value.bits[7];
  return res;
}
// rename bit
s21_decimal intToDecimal(int val, int bit) {
  s21_decimal res;
  clearDecimal(&res);
  res.bits[bit] = abs(val);
  setSign(&res, (val < 0) ? 1 : 0);
  return res;
}

// unsigned and unscaled add

int baseUnsignAddBig(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result) {
  unsigned int tmpbit = 0;
  clearBigDecimal(result);

  for (int i = 0; i <= ADDITIONAL_SIGN_BIG_2; i++) {
    tmpbit += getBitBig(&value_1, i) + getBitBig(&value_2, i);
    setBitBig(result, i, tmpbit % 2);
    tmpbit = tmpbit >> 1u;
  }

  return tmpbit;
}

void setAddSignBig(s21_big_decimal *value, int sign) {
  setBitBig(value, ADDITIONAL_SIGN_BIG_1, sign);
  setBitBig(value, ADDITIONAL_SIGN_BIG_2, sign);
}

int baseAddBig(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result) {
  s21_big_decimal tmpResult;
  clearBigDecimal(&tmpResult);
  int sign1 = getSignBig(&value_1), sign2 = getSignBig(&value_2), ressign = 0;
  setAddSignBig(&value_1, sign1);
  setAddSignBig(&value_2, sign2);

  if (sign1) value_1 = returnCode(value_1);
  if (sign2) value_2 = returnCode(value_2);
  int tmpbit = baseUnsignAddBig(value_1, value_2, &tmpResult);

  s21_decimal tmp = intToDecimal(tmpbit, 0);
  value_2 = toBigDecimal(tmp);
  baseUnsignAddBig(tmpResult, value_2, &tmpResult);
  ressign = getBitBig(&tmpResult, ADDITIONAL_SIGN_BIG_2);
  if (ressign) {
    tmpResult = returnCode(tmpResult);
  }
  setSignBig(&tmpResult, ressign);
  *result = tmpResult;

  return (getBitBig(&tmpResult, ADDITIONAL_SIGN_BIG_1) !=
          getBitBig(&tmpResult, ADDITIONAL_SIGN_BIG_2)) *
         (1 + getBitBig(&tmpResult, ADDITIONAL_SIGN_BIG_2));
}

int baseSubBig(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result) {
  setSignBig(&value_2, (getSignBig(&value_2) + 1) % 2);

  return baseAddBig(value_1, value_2, result);
}

int baseCompareBig(s21_big_decimal value_1, s21_big_decimal value_2) {
  if (getBitBig(&value_1, ADDITIONAL_SIGN_BIG_1) ==
      getBitBig(&value_1, ADDITIONAL_SIGN_BIG_1))
    setAddSignBig(&value_1, 0);
  if (getBitBig(&value_2, ADDITIONAL_SIGN_BIG_1) ==
      getBitBig(&value_2, ADDITIONAL_SIGN_BIG_1))
    setAddSignBig(&value_2, 0);
  int res = 0;
  for (int i = ADDITIONAL_SIGN_BIG_1; i >= 0 && !res; i--) {
    int bit1 = getBitBig(&value_1, i);
    int bit2 = getBitBig(&value_2, i);
    res = (bit1 > bit2) ? 1 : (bit2 > bit1) ? 2 : res;
  }
  return res;
}

s21_big_decimal selectOptimalTermBig(s21_big_decimal value,
                                     s21_big_decimal term,
                                     s21_big_decimal *res) {
  s21_big_decimal tmp = term, ten = toBigDecimal(intToDecimal(10, 0)),
                  counter = toBigDecimal(intToDecimal(1, 0));
  *res = term;
  int errorCode = 0;

  while (errorCode == 0) {
    errorCode = baseMulBig(tmp, ten, &tmp);

    if (baseCompareBig(value, tmp) < 2) {
      if (!errorCode) {
        baseMulBig(counter, ten, &counter);
        *res = tmp;
      }
    } else {
      errorCode = 1;
    }
  }

  return counter;
}

int baseDivBig(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result, s21_big_decimal *mod) {
  int overflow = 0;
  int resSign = getSignBig(&value_1) ^ getSignBig(&value_2),
      modSign = getSignBig(&value_1);
  if (!equalZeroBig(value_1)) {
    setSignBig(&value_1, 0);
    setSignBig(&value_2, 0);
    s21_big_decimal tmp, counter;
    clearBigDecimal(result);
    clearBigDecimal(mod);
    clearBigDecimal(&tmp);
    clearBigDecimal(&counter);
    while (!overflow && baseCompareBig(value_1, value_2) < 2) {
      counter = selectOptimalTermBig(value_1, value_2, &tmp);
      overflow = baseSubBig(value_1, tmp, &value_1);
      if (!overflow) overflow = baseAddBig(*result, counter, result);

      clearBigDecimal(&tmp);
    }

    if (!overflow) {
      setSignBig(result, resSign);
      *mod = value_1;
      setSignBig(mod, modSign);
    }
  } else {
    *result = value_1;
    *mod = value_1;
  }
  return overflow;
}

int hasSpecialValuesBig(s21_big_decimal value_1, s21_big_decimal value_2) {
  int res = 0;
  if (value_1.bits[1] == 0 && value_1.bits[2] == 0 && value_1.bits[3] == 0 &&
      value_1.bits[4] == 0 && value_1.bits[5] == 0 && value_2.bits[6] == 0) {
    if (value_1.bits[0] == 0)
      res = 1;
    else if (value_1.bits[0] == 1) {
      res = 2;
    }
  }
  if (value_2.bits[1] == 0 && value_2.bits[2] == 0 && value_2.bits[3] == 0 &&
      value_2.bits[4] == 0 && value_2.bits[5] == 0 && value_2.bits[6] == 0) {
    if (!value_2.bits[0])
      res = 1;
    else if (value_2.bits[0] == 1)
      res = 3;
  }
  return res;
}

int findHighestBitBig(s21_big_decimal value) {
  int res = 0;
  for (int i = LAST_MANTISA_BIT_BIGDECIMAL; i >= 0 && !res; i--) {
    if (getBitBig(&value, i)) res = i;
  }
  return res;
}

int splitBig(s21_big_decimal *value, int count) {
  int highestBit = findHighestBitBig(*value);
  if (highestBit + count > LAST_MANTISA_BIT_BIGDECIMAL) return 1;
  for (int i = 0; i < count && highestBit != 0; i++) {
    value->bits[6] <<= 1;
    setBitBig(value, 192, getBitBig(value, 191));
    value->bits[5] <<= 1;
    setBitBig(value, 160, getBitBig(value, 159));
    value->bits[4] <<= 1;
    setBitBig(value, 128, getBitBig(value, 127));
    value->bits[3] <<= 1;
    setBitBig(value, 96, getBitBig(value, 95));
    value->bits[2] <<= 1;
    setBitBig(value, 64, getBitBig(value, 63));
    value->bits[1] <<= 1;
    setBitBig(value, 32, getBitBig(value, 31));
    value->bits[0] <<= 1;
  }
  return 0;
}

int baseMulBig(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result) {
  int errorCode = 0;
  s21_big_decimal tmp;
  clearBigDecimal(&tmp);
  clearBigDecimal(result);

  int specVal = hasSpecialValuesBig(value_1, value_2);
  switch (specVal) {
    case 1:
      *result = toBigDecimal(intToDecimal(0, 0));
      break;
    case 2:
      *result = value_2;
      break;
    case 3:
      *result = value_1;
      break;
  }

  if (!specVal) {
    for (int i = LAST_MANTISA_BIT_BIGDECIMAL; i > 0 && !errorCode; i--) {
      if (getBitBig(&value_2, i)) {
        tmp = value_1;
        errorCode = splitBig(&tmp, i);
        errorCode = (!errorCode) ? baseAddBig(*result, tmp, result) : errorCode;
      }
    }
    if (getBitBig(&value_2, 0) && !errorCode)
      errorCode = baseAddBig(*result, value_1, result);
  }

  if (!errorCode) {
    setSignBig(result, getSignBig(&value_1) ^ getSignBig(&value_2));
  }

  return errorCode;
}

int normalizeToBigDecimal(s21_decimal value_1, s21_decimal value_2,
                          s21_big_decimal *scaledVal1,
                          s21_big_decimal *scaledVal2, int *scale) {
  s21_big_decimal ten = toBigDecimal(intToDecimal(10, 0));

  int scale1 = getScale(&value_1);
  int scale2 = getScale(&value_2);
  int resScale = (scale1 > scale2) ? scale1 : scale2;
  int errorCode = 0;
  *scaledVal1 = toBigDecimal(value_1);
  *scaledVal2 = toBigDecimal(value_2);
  while (scale1 < scale2 && !errorCode) {
    errorCode = baseMulBig(*scaledVal1, ten, scaledVal1);
    scale1++;
  }
  while (scale1 > scale2 && !errorCode) {
    scale2++;
    errorCode = baseMulBig(*scaledVal2, ten, scaledVal2);
  }
  if (!errorCode) *scale = resScale;
  return errorCode;
}

void bankRounding(s21_big_decimal *value, int mod) {
  int sign = getSignBig(value);
  if (mod == 5) {
    if (getBitBig(value, 0)) {
      baseAddBig(*value, toBigDecimal(intToDecimal(-2 * sign + 1, 0)), value);
    }
  } else if (mod > 5) {
    baseAddBig(*value, toBigDecimal(intToDecimal(-2 * sign + 1, 0)), value);
  }
}
int cutZeroes(s21_big_decimal *value, int scale) {
  s21_big_decimal ten = toBigDecimal(intToDecimal(10, 0)), mod, tmpVal = *value;
  clearBigDecimal(&mod);

  if (!equalZeroBig(*value)) {
    baseDivBig(tmpVal, ten, &tmpVal, &mod);
    while (equalZeroBig(mod)) {
      optiFineBaseDivBig(*value, ten, value, &mod);
      optiFineBaseDivBig(tmpVal, ten, &tmpVal, &mod);
      scale--;
    }
  }
  return scale;
}

int roundBig(s21_big_decimal *value, int scale) {
  int addSignFlag = 0;
  int errorCode = 0;
  s21_big_decimal ten = toBigDecimal(intToDecimal(10, 0)), tmp, mod;
  clearBigDecimal(&tmp);
  clearBigDecimal(&mod);
  if ((getBitBig(value, ADDITIONAL_SIGN_1) !=
       getBitBig(value, ADDITIONAL_SIGN_2))) {
    addSignFlag = 1;
  }

  if (scale != 0) {
    while ((findHighestBitBig(*value) > LAST_MANTISA_BIT_DECIMAL ||
            addSignFlag || scale > 28) &&
           !errorCode) {
      if (scale <= 0) {
        errorCode = 1;

      } else {
        optiFineBaseDivBig(*value, ten, &tmp, &mod);

        scale--;
        tmp.bits[7] = value->bits[7];
        *value = tmp;

        if (addSignFlag) {
          addSignFlag = 0;
          setAddSignBig(value, 0);
        }
      }
    }

  } else if (findHighestBitBig(*value) > LAST_MANTISA_BIT_DECIMAL) {
    errorCode = 1;
  }

  if (!errorCode) {
    bankRounding(value, mod.bits[0]);

  } else {
    errorCode += getSignBig(value);
  }

  if (findHighestBitBig(*value) > LAST_MANTISA_BIT_DECIMAL) {
    errorCode = 1 + getSignBig(value);
  }

  setEpsilonBig(value, scale);

  return errorCode;
}

int equalZeroBig(s21_big_decimal value) {
  int c = 1;
  for (int i = 0; i < 7; i++) {
    if (value.bits[i] != 0) c = 0;
  }
  return c;
}
int equalZero(s21_decimal value) {
  int c = 1;
  for (int i = 0; i < 3; i++) {
    if (value.bits[i] != 0) c = 0;
  }
  return c;
}
int optiFineBaseDivBig(s21_big_decimal value_1, s21_big_decimal value_2,
                       s21_big_decimal *result, s21_big_decimal *mod) {
  int firstNonEmptyBit = 0, errorCode = 0;
  for (int i = 7; i > 0 && !firstNonEmptyBit; i--) {
    if (value_1.bits[i] || value_2.bits[i]) firstNonEmptyBit = 1;
  }
  if (!firstNonEmptyBit) {
    unsigned long long lval1 = value_1.bits[0], lval2 = value_2.bits[0],
                       lres = 0, lmod = 0;
    lres = lval1 / lval2;
    lmod = lval1 % lval2;
    if (lres < (unsigned long long)UINT32_MAX &&
        lmod < (unsigned long long)UINT32_MAX) {
      *result = toBigDecimal(intToDecimal(lres, 0));
      *mod = toBigDecimal(intToDecimal(lmod, 0));
      setSignBig(result, (getSignBig(&value_1) + getSignBig(&value_2)) % 2);
      setSignBig(mod, (getSignBig(&value_1) + getSignBig(&value_2)) % 2);
    } else {
      errorCode = baseDivBig(value_1, value_2, result, mod);
    }
  } else
    errorCode = baseDivBig(value_1, value_2, result, mod);
  return errorCode;
}

void readDecimalsFromFile(s21_decimal *v1, s21_decimal *v2, s21_decimal *res,
                          const char *fName, int *errorCode, int line) {
  FILE *fp = fopen(fName, "r");
  if (fp == NULL) {
    printf("ERROR\n");
    return;
  }
  int skipedLines = 0;
  char c;
  while (skipedLines != (line * 5 + 1)) {
    c = fgetc(fp);
    if (c == '\n') {
      skipedLines++;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 127; j >= 0; j--) {
      int bit;

      c = fgetc(fp);

      if (c == 49)
        bit = 1;
      else
        bit = 0;
      switch (i) {
        case 0:
          setBit(v1, j, bit);
          break;
        case 1:
          setBit(v2, j, bit);
          break;
        case 2:
          setBit(res, j, bit);
          break;
      }
    }
    fgetc(fp);
  }
  c = fgetc(fp);
  *errorCode = c - 48;
  fclose(fp);
}