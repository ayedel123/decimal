#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_decimal_tests.h"

#endif

START_TEST(s21_mul_test) {
  // FILE *f = fopen("tests/manual_test_py/test_data.txt", "w");
  // fclose(f);
  s21_decimal a, b, truRes, myRes;
  int expectedCode = 0;
  readDecimalsFromFile(&a, &b, &truRes,
                       "tests/arithmetic_tests/test_data/mul_test_data.txt",
                       &expectedCode, 0);
  int testCount = 17;
  int functionReturned = 0;
  for (int i = 0; i < testCount; i++) {
    readDecimalsFromFile(&a, &b, &truRes,
                         "tests/arithmetic_tests/test_data/mul_test_data.txt",
                         &expectedCode, i);
    functionReturned = s21_mul(a, b, &myRes);
    // writeDecimalInFile(truRes, "tests/manual_test_py/test_data.txt");
    // writeDecimalInFile(myRes, "tests/manual_test_py/test_data.txt");
    if (!expectedCode) ASSERT_DECIMAL_EQ(myRes, truRes);
    ck_assert_int_eq(functionReturned, expectedCode);
    // ck_assert_msg(myRes.bits[0] != truRes.bits[0], "case %d ", i);
    // ck_assert_msg(myRes.bits[1] != truRes.bits[1], "case %d ", i);
    // ck_assert_msg(myRes.bits[2] != truRes.bits[2], "case %d ", i);
    // ck_assert_msg(myRes.bits[3] != truRes.bits[3], "case %d ", i);
    // ck_assert_msg(functionReturned != expectedCode, "case %d ", i);
  }
}
END_TEST

Suite *s21_mul_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_mul_test");
  tc = tcase_create("test");

  tcase_add_test(tc, s21_mul_test);
  suite_add_tcase(s, tc);
  return s;
}
