#include "../s21_decimal.h"
#include "s21_decimal_tests.h"

void getEpsilonTest(s21_decimal number, int expected) {
  int epsilon = getScale(&number);
  ck_assert_int_eq(epsilon, expected);
}

START_TEST(getEpsilon_test) {
  s21_decimal number;
  initDecimal(&number);
  setBit(&number, 112, 1);
  setBit(&number, 113, 1);
  setBit(&number, 114, 1);
  getEpsilonTest(number, 7);
}
END_TEST

void setEpsilonTest(s21_decimal number, int expected) {
  setScale(&number, expected);
  ck_assert_int_eq(getScale(&number), expected);
}

START_TEST(setEpsilon_test) {
  s21_decimal number;
  s21_decimal expected;
  initDecimal(&number);
  initDecimal(&expected);
  int epsilon = 28;
  setScale(&expected, epsilon);
  setEpsilonTest(number, epsilon);
  initDecimal(&number);
  initDecimal(&expected);
  epsilon = 0;
  setScale(&expected, epsilon);
  setEpsilonTest(number, epsilon);
}
END_TEST

void setBitToIntTest(int bit, int index, int expected) {
  int number = 0;
  setBitToInt(&number, index, bit);
  ck_assert_int_eq(number, expected);
}

START_TEST(setBitToInt_test) {
  setBitToIntTest(1, 0, 1);
  setBitToIntTest(1, 1, 2);
  setBitToIntTest(1, 2, 4);
  setBitToIntTest(0, -1, 0);
  setBitToIntTest(0, 9999, 0);
}
END_TEST

void setBitTest(s21_decimal number, int index, int bit, s21_decimal expected) {
  setBit(&number, index, bit);
  ck_assert_int_eq(number.bits[0], expected.bits[0]);
  ck_assert_int_eq(number.bits[1], expected.bits[1]);
  ck_assert_int_eq(number.bits[2], expected.bits[2]);
  ck_assert_int_eq(number.bits[3], expected.bits[3]);
}

START_TEST(setBit_test) {
  s21_decimal number;
  s21_decimal expected;
  initDecimal(&number);
  initDecimal(&expected);
  expected.bits[0] = 1;
  setBitTest(number, 0, 1, expected);
  initDecimal(&number);
  initDecimal(&expected);
  expected.bits[3] = -2147483648;
  setBitTest(number, 127, 1, expected);
  initDecimal(&number);
  initDecimal(&expected);
  expected.bits[1] = 1;
  setBitTest(number, 32, 1, expected);
  initDecimal(&number);
  initDecimal(&expected);
  expected.bits[0] = 1;
  setBitTest(number, 0, 1, expected);
}
END_TEST

void getBitTest(s21_decimal number, int expectedBit, int index) {
  int bit = getBit(&number, index);
  ck_assert_int_eq(bit, expectedBit);
}

START_TEST(getBit_test) {
  s21_decimal number;
  initDecimal(&number);
  getBitTest(number, 0, 0);
  initDecimal(&number);
  setBit(&number, 127, 1);
  getBitTest(number, 1, 127);
}
END_TEST

Suite *getBitsTestsSuite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("decimalBits Test");
  tc = tcase_create("test");

  tcase_add_test(tc, getBit_test);
  tcase_add_test(tc, setBit_test);
  tcase_add_test(tc, setBitToInt_test);
  tcase_add_test(tc, getEpsilon_test);
  tcase_add_test(tc, setEpsilon_test);
  suite_add_tcase(s, tc);
  return s;
}
