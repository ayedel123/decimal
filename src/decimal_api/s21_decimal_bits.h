//
// Created by Turnip Sharee on 10/17/23.
//

#ifndef MANUAL_S21_DECIMAL_BITS_H
#define MANUAL_S21_DECIMAL_BITS_H

#include "../s21_decimal.h"

int getSign(s21_decimal *number);

void setSign(s21_decimal *number, int sign);

int getBit(s21_decimal *number, int index);

void setBit(s21_decimal *number, int index, int value);

void setBitToInt(unsigned int *number, int index, int bit);

#endif  // MANUAL_S21_DECIMAL_BITS_H
