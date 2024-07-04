#include "s21_decimal.h"

#include <stdio.h>

#define EPSILON_START_INDEX_IN_BITS3 15
#define EPSILON_START_INDEX 112
#define EPSILON_BIG_START_INDEX_IN_BITS3 15
#define EPSILON_BIG_START_INDEX 240

#define S21_MAX_AVAILABLE_SCALE_VALUE 28
#include "decimal_api/s21_decimal_utils.h"

void initDecimal(s21_decimal *number) {
  number->bits[0] = 0;
  number->bits[1] = 0;
  number->bits[2] = 0;
  number->bits[3] = 0;
}

long double getNum(s21_decimal *src) {
  return getDoubleFromBitsRange(src, MANTISSA_START_INDEX,
                                MANTISSA_START_INDEX + MANTISSA_LEN);
}

void setNum(s21_decimal *number, long double src) {
  setBitsToRange(number, src, MANTISSA_START_INDEX,
                 MANTISSA_START_INDEX + getBitsCount(src));
}

int getScale(s21_decimal *number) {
  return (int)getDoubleFromBitsRange(number, SCALE_START_INDEX,
                                     SCALE_START_INDEX + SCALE_LEN);
}

void setScale(s21_decimal *number, int epsilon) {
  setBitsToRange(number, epsilon, SCALE_START_INDEX,
                 SCALE_START_INDEX + SCALE_LEN);
}

int getEpsilonBig(s21_big_decimal *number) {
  unsigned int epsilon = 0;
  for (int i = EPSILON_BIG_START_INDEX; i <= EPSILON_BIG_START_INDEX + 7; i++) {
    int bit = (int)getBitBig(number, i);
    setBitToInt(&epsilon, i - EPSILON_BIG_START_INDEX, bit);
  }
  return epsilon;
}

void setEpsilonBig(s21_big_decimal *number, int epsilon) {
  for (int i = EPSILON_BIG_START_INDEX; i <= EPSILON_BIG_START_INDEX + 7; i++) {
    int bit = getBitFromInt(epsilon, i - EPSILON_BIG_START_INDEX);
    setBitBig(number, i, bit);
  }
}

int getSign(s21_decimal *number) { return getBit(number, SIGN_INDEX); }

void setSign(s21_decimal *number, int sign) {
  setBit(number, SIGN_INDEX, sign);
}

void copyDecimal(s21_decimal *first, s21_decimal *second) {
  for (int i = 0; i <= SIGN_INDEX; i++) {
    setBit(first, i, getBit(second, i));
  }
}

void printDecimal(s21_decimal *number) {
  printf("<s21_decimal.decimal>\n");
  printf("sign = ");
  if (getSign(number) == POSITIVE) {
    printf("POSITIVE\n");
  } else {
    printf("NEGATIVE\n");
  }

  printf("scale = %d\n", getScale(number));
  printf("scaleBits = ");
  for (int i = SCALE_START_INDEX + SCALE_LEN; i >= SCALE_START_INDEX; i--) {
    printf("%d", getBit(number, i));
  }
  printf("\n");
  printf("mantissa = %Lf\n", getNum(number));
  printf("mantissaBits = ");
  for (int i = 127; i >= 0; i--) {
    printf("%d", getBit(number, i));
  }

  printf("\n");

  printf("bits[3] = %u bits[2] = %u bits[1] = %u bits[0] = %u\n",
         number->bits[3], number->bits[2], number->bits[1], number->bits[0]);
  printf("</s21_decimal.decimal>\n");
}
