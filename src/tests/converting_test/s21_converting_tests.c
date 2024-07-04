#include "../s21_decimal_tests.h"

START_TEST(floatConverting_test) {
  s21_decimal source, target;

  float srcs[] = {1.333333333333333f, -1, 2147483647.0f,
                  -2147483647.0f,     0,  INFINITY};

  for (int i = 0; srcs[i] != INFINITY; i++) {
    initDecimal(&source);
    initDecimal(&target);
    s21_from_float_to_decimal(srcs[i], &source);
    float result = 0;
    s21_from_decimal_to_float(source, &result);
    ck_assert_float_ge_tol(result, srcs[i], 1e-6);
  }
}
END_TEST

START_TEST(intConverting_test_fn) {
  s21_decimal source;

  int number[] = {1, -1, 2147483647, -2147483647, 0, 1};

  for (int i = 0; i < 6; i++) {
    initDecimal(&source);
    s21_from_int_to_decimal(number[i], &source);
    int result = 0;
    s21_from_decimal_to_int(source, &result);
    ck_assert_int_eq(result, number[i]);
  }
}

Suite *getConvertingTestsSuite() {
  Suite *s;
  TCase *tc;
  s = suite_create("converting test");
  tc = tcase_create("test");

  tcase_add_test(tc, floatConverting_test);
  tcase_add_test(tc, intConverting_test_fn);
  suite_add_tcase(s, tc);
  return s;
}