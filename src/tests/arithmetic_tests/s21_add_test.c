#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_decimal_tests.h"

#endif

void printFull(s21_decimal val) {
  for (int i = 127; i <= 0; i--) {
    printf("%d", getBit(&val, i));
  }
  printf("\n");
}

START_TEST(s21_add_test1) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 0);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);

  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST

START_TEST(s21_add_test2) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 1);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST

START_TEST(s21_add_test3) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 2);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST

START_TEST(s21_add_test4) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 3);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST

START_TEST(s21_add_test5) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 4);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST

START_TEST(s21_add_test6) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 5);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST

START_TEST(s21_add_test7) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 6);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST

START_TEST(s21_add_test8) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 7);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST

START_TEST(s21_add_test9) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 8);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test10) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 9);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test11) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 10);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test12) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 11);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test13) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 12);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test14) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 13);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test15) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 14);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test16) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 15);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test17) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 16);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test18) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 17);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test19) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 18);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test20) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 19);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test21) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 20);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test22) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 21);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test23) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 22);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test24) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 23);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, errorCodeToLargeOrInfinity);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test25) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 24);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, errorCodeTooSmallOrNegativeInfinity);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test26) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 25);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test27) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 26);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test28) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 27);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test29) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 28);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test30) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 29);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test31) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 30);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test32) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 31);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test33) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 32);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test34) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 33);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test35) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 34);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test36) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 35);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test37) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 36);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test38) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 37);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST
START_TEST(s21_add_test39) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 38);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST

START_TEST(s21_add_test40) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 39);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST

START_TEST(s21_add_test41) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 40);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST

START_TEST(s21_add_test42) {
  s21_decimal val1 = {{1, 0, 0, 0}}, val2 = {{1, 0, 0, 0}},
              truResult = {{1, 0, 0, 0}}, myResult = {{1, 0, 0, 0}};
  int expectedCode = 0;
  readDecimalsFromFile(&val1, &val2, &truResult,
                       "tests/arithmetic_tests/test_data/add_test_data.txt",
                       &expectedCode, 41);
  int function_returned = s21_add(val1, val2, &myResult);
  ck_assert_uint_eq(function_returned, expectedCode);
  if (expectedCode == errorCodeNoError) ASSERT_DECIMAL_EQ(myResult, truResult);
}
END_TEST

Suite *s21_add_suite() {
  Suite *suite;
  TCase *test_case;

  suite = suite_create("s21 add test");

  test_case = tcase_create("Core");

  tcase_add_test(test_case, s21_add_test1);
  tcase_add_test(test_case, s21_add_test2);
  tcase_add_test(test_case, s21_add_test3);
  tcase_add_test(test_case, s21_add_test4);
  tcase_add_test(test_case, s21_add_test5);
  tcase_add_test(test_case, s21_add_test6);
  tcase_add_test(test_case, s21_add_test7);
  tcase_add_test(test_case, s21_add_test8);
  tcase_add_test(test_case, s21_add_test9);
  tcase_add_test(test_case, s21_add_test10);
  tcase_add_test(test_case, s21_add_test11);
  tcase_add_test(test_case, s21_add_test12);
  tcase_add_test(test_case, s21_add_test13);
  tcase_add_test(test_case, s21_add_test14);
  tcase_add_test(test_case, s21_add_test15);
  tcase_add_test(test_case, s21_add_test16);
  tcase_add_test(test_case, s21_add_test17);
  tcase_add_test(test_case, s21_add_test18);
  tcase_add_test(test_case, s21_add_test19);
  tcase_add_test(test_case, s21_add_test20);
  tcase_add_test(test_case, s21_add_test21);
  tcase_add_test(test_case, s21_add_test22);
  tcase_add_test(test_case, s21_add_test23);
  tcase_add_test(test_case, s21_add_test24);
  tcase_add_test(test_case, s21_add_test25);
  tcase_add_test(test_case, s21_add_test26);
  tcase_add_test(test_case, s21_add_test27);
  tcase_add_test(test_case, s21_add_test28);
  tcase_add_test(test_case, s21_add_test29);
  tcase_add_test(test_case, s21_add_test30);
  tcase_add_test(test_case, s21_add_test31);
  tcase_add_test(test_case, s21_add_test32);
  tcase_add_test(test_case, s21_add_test33);
  tcase_add_test(test_case, s21_add_test34);
  tcase_add_test(test_case, s21_add_test35);
  tcase_add_test(test_case, s21_add_test36);
  tcase_add_test(test_case, s21_add_test37);
  tcase_add_test(test_case, s21_add_test38);
  tcase_add_test(test_case, s21_add_test39);
  tcase_add_test(test_case, s21_add_test40);
  tcase_add_test(test_case, s21_add_test41);
  tcase_add_test(test_case, s21_add_test42);

  suite_add_tcase(suite, test_case);

  return suite;
}
