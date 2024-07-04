#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef C5_S21_DECIMAL_2_S21_DECIMAL_H

#define C5_S21_DECIMAL_2_S21_DECIMAL_H

#define NEGATIVE 1
#define POSITIVE 0

#define UNSIGNED_LONG_LEN 64

#define SIGN_INDEX 127

#define SCALE_START_INDEX 112
#define SCALE_LEN 7

#define MANTISSA_START_INDEX 0
#define MANTISSA_LEN 95

#define OK 0
#define ERROR_TOO_BIG 1
#define ERROR_TOO_SMALL 2
#define ERROR_DIVIDE_BY_ZERO 3
#define ERROR_CONVERTING 1

#define MAX_DECIMAL 79228162514264337593543950335.0f
#define MIN_DECIMAL 1e-28

#define MAX_INT 2147483647
#define MIN_INT -2147483648

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

#include "decimal_api/s21_boolean.h"
#include "decimal_api/s21_decimal_bits.h"
#include "decimal_api/s21_decimal_utils.h"

void initDecimal(s21_decimal *number);

int getSignBig(const s21_big_decimal *value);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_truncate(s21_decimal value, s21_decimal *result);

int s21_negate(s21_decimal value, s21_decimal *result);

uint32_t getBitBig(const s21_big_decimal *value, int index);

s21_big_decimal toBigDecimal(s21_decimal value);

s21_decimal toNormalDecimal(s21_big_decimal value);

void clearDecimal(s21_decimal *value);

void clearBigDecimal(s21_big_decimal *value);

s21_big_decimal returnCode(s21_big_decimal value);

int baseUnsignAddBig(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *result);

s21_decimal intToDecimal(int val, int bit);

int baseAddBig(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result);

void setBitBig(s21_big_decimal *value, int index, unsigned int bit);

void writeDecimalInFile(s21_decimal value, const char *fileName);

void setSignBig(s21_big_decimal *value, unsigned int sign);

int baseMulBig(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result);

int baseDivBig(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result, s21_big_decimal *mod);

int baseCompareBig(s21_big_decimal value_1, s21_big_decimal value_2);

s21_big_decimal selectOptimalTermBig(s21_big_decimal value,
                                     s21_big_decimal term,
                                     s21_big_decimal *res);

int baseSubBig(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result);

int normalizeToBigDecimal(s21_decimal val1, s21_decimal val2,
                          s21_big_decimal *scaledVal1,
                          s21_big_decimal *scaledVal2, int *scale);

void setEpsilonBig(s21_big_decimal *number, int epsilon);

int getEpsilonBig(s21_big_decimal *number);

int findHighestBitBig(s21_big_decimal value);

int roundBig(s21_big_decimal *value, int scale);

int equalZeroBig(s21_big_decimal value);

void printDecimalBig(s21_big_decimal value);

void readDecimalsFromFile(s21_decimal *v1, s21_decimal *v2, s21_decimal *res,
                          const char *fName, int *errorCode, int line);

int equalZero(s21_decimal value);

int cutZeroes(s21_big_decimal *value, int scale);

int s21_round(s21_decimal value, s21_decimal *result);

int normalizeToBigDecimal(s21_decimal val1, s21_decimal val2,
                          s21_big_decimal *scaledVal1,
                          s21_big_decimal *scaledVal2, int *scale);

void setEpsilonBig(s21_big_decimal *number, int epsilon);

int getEpsilonBig(s21_big_decimal *number);

int findHighestBitBig(s21_big_decimal value);

int roundBig(s21_big_decimal *value, int scale);

int equalZeroBig(s21_big_decimal value);

void printDecimalBig(s21_big_decimal value);

void readDecimalsFromFile(s21_decimal *v1, s21_decimal *v2, s21_decimal *res,
                          const char *fName, int *errorCode, int line);

int s21_from_int_to_decimal(int src, s21_decimal *dst);

int s21_from_float_to_decimal(float src, s21_decimal *dst);

int s21_from_decimal_to_int(s21_decimal src, int *dst);

int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_is_less(s21_decimal, s21_decimal);

int s21_is_less_or_equal(s21_decimal, s21_decimal);

int s21_is_greater(s21_decimal, s21_decimal);

int s21_is_greater_or_equal(s21_decimal, s21_decimal);

int s21_is_equal(s21_decimal, s21_decimal);

int s21_is_not_equal(s21_decimal, s21_decimal);

void printDecimal(s21_decimal *number);

int s21_floor(s21_decimal value, s21_decimal *result);

int isIntInRange(int value, int min, int max);

int getBitFromInt(unsigned int source, int index);

int getScale(s21_decimal *number);

void setScale(s21_decimal *number, int epsilon);

void setNum(s21_decimal *number, long double src);

long double getNum(s21_decimal *src);

long double getDoubleFromBitsRange(s21_decimal *number, int start, int end);

int optiFineBaseDivBig(s21_big_decimal value_1, s21_big_decimal value_2,
                       s21_big_decimal *result, s21_big_decimal *mod);
void setBitsToRange(s21_decimal *number, long double source, int start,
                    int end);

int getBitsCount(long double src);

int getFractionPartLength(double number);

float roundFloat(float number, int scale);

// rossettek

int s21_is_less(s21_decimal first, s21_decimal second);

int s21_is_greater(s21_decimal first, s21_decimal second);

int s21_is_less_or_equal(s21_decimal first, s21_decimal second);

int s21_is_greater_or_equal(s21_decimal first, s21_decimal second);

int s21_is_equal(s21_decimal first, s21_decimal second);

int s21_is_not_equal(s21_decimal first, s21_decimal second);

int s21_truncate(s21_decimal value, s21_decimal *result);

void copyDecimal(s21_decimal *first, s21_decimal *second);

#endif  // C5_S21_DECIMAL_2_S21_DECIMAL_H
