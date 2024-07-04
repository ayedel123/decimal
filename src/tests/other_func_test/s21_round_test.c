#include "../s21_decimal_tests.h"

START_TEST(s21_round_test) {
  s21_decimal a, b, truRes, myRes;
  int expectedCode = 0;
  readDecimalsFromFile(&a, &b, &truRes,
                       "tests/arithmetic_tests/test_data/round_test_data.txt",
                       &expectedCode, 0);
  int testCount = 11;
  int functionReturned = 0;
  for (int i = 0; i < testCount; i++) {
    readDecimalsFromFile(&a, &b, &truRes,
                         "tests/arithmetic_tests/test_data/round_test_data.txt",
                         &expectedCode, i);
    functionReturned = s21_round(a, &myRes);
    writeDecimalInFile(truRes, "tests/manual_test_py/tsest_data.txt");
    writeDecimalInFile(myRes, "tests/manual_test_py/test_data.txt");
    if (!expectedCode) ASSERT_DECIMAL_EQ(myRes, truRes);

    ck_assert_int_eq(functionReturned, expectedCode);
  }
}
END_TEST

Suite *s21_round_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_round_test");
  tc = tcase_create("test");

  tcase_add_test(tc, s21_round_test);
  suite_add_tcase(s, tc);
  return s;
}
