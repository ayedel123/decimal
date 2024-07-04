#include "s21_decimal_bits.h"

#include <math.h>

long double getDoubleFromBitsRange(s21_decimal *number, int start, int end) {
  if (start < 0 || end >= 128) {
    return -1.0f;
  }

  if (end < start) {
    return -1.0f;
  }

  long double result = 0.0;

  float coefficent = 1;

  for (int i = start; i <= end; i++) {
    if (getBit(number, i)) {
      result += coefficent;
    }
    coefficent *= 2;
  }
  return result;
}

void setBitsToRange(s21_decimal *number, long double source, int start,
                    int end) {
  if (start < 0 || end >= 128) {
    return;
  }

  if (start > end) {
    return;
  }

  if (end - start > UNSIGNED_LONG_LEN) {
    return;
  }

  for (int i = start; i <= end; i++) {
    int value = (int)fmodl(source, 2);
    source /= 2;
    setBit(number, i, value);
  }
}

void setBit(s21_decimal *number, int index, int value) {
  setBitToInt(&number->bits[index / 32], index % 32, value);
}

int getBit(s21_decimal *number, int index) {
  return getBitFromInt(number->bits[index / 32], index % 32);
}

void setBitToInt(unsigned *number, int index, int value) {
  if (value == 0) {
    (*number) &= ~(1 << index);
  } else {
    (*number) |= (1 << index);
  }
}

void setBitBig(s21_big_decimal *value, int index, unsigned int bit) {
  unsigned int mask = 1 << (index % 32);
  if (bit)
    value->bits[index / 32] |= mask;
  else
    value->bits[index / 32] &= ~mask;
}

void setSignBig(s21_big_decimal *value, unsigned int sign) {
  setBitBig(value, SIGN_BIT_BIG, sign);
}

int getSignBig(const s21_big_decimal *value) {
  return getBitBig(value, SIGN_BIT_BIG);
}

uint32_t getBitBig(const s21_big_decimal *value, int index) {
  unsigned int mask = 1u << (index % 32);
  return ((value->bits[index / 32] & mask) != 0) ? 1 : 0;
}

int getBitFromInt(unsigned source, int index) {
  return (int)((source >> index) & 1u);
}

int getBitsCount(long double src) {
  int length = 0;
  while ((long long)src != 0) {
    src /= 2;
    length++;
  }
  return length;
}
