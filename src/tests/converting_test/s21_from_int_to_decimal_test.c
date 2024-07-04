#include "../s21_decimal_tests.h"

START_TEST(s21_from_int_to_decimal_test1) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  int param = 5;
  s21_from_int_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 5);
  ck_assert_float_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test2) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  int param = 2147483647;
  s21_from_int_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 2147483647);
  ck_assert_float_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test3) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  int param = -2147483648;
  s21_from_int_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 2147483648);
  ck_assert_float_eq(test_dec.bits[3], 2147483648);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test4) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  int param = -5;
  s21_from_int_to_decimal(param, &test_dec);
  ck_assert_float_eq(test_dec.bits[0], 5);
  ck_assert_float_eq(test_dec.bits[3], 2147483648);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test5) {
  int src = -2147483648;
  int temp = 0;
  s21_decimal number_1 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(src, &number_1);
  s21_from_decimal_to_int(number_1, &temp);
  ck_assert_int_eq(src, temp);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test6) {
  int src = -0;
  int temp = 0;
  s21_decimal number_1 = {{1, 0, 0, 0}};
  s21_from_int_to_decimal(src, &number_1);
  s21_from_decimal_to_int(number_1, &temp);
  ck_assert_int_eq(src, temp);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test7) {
  int src = 101;
  int temp = 0;
  s21_decimal number_1 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(src, &number_1);
  s21_from_decimal_to_int(number_1, &temp);
  ck_assert_int_eq(src, temp);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test8) {
  int src = -31325;
  int temp = 0;
  int return_number = 0;
  s21_decimal number_1 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(src, &number_1);
  s21_from_decimal_to_int(number_1, &temp);
  return_number = (src == temp);
  ck_assert_int_eq(return_number, 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test9) {
  int src = 49135648;
  s21_decimal check = {{49135648, 0, 0, 0}};
  s21_decimal result;
  initDecimal(&result);
  int return_number = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(check, result), 1);
  ck_assert_int_eq(return_number, OK);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test10) {
  int src = -49135648;
  s21_decimal check = {{49135648, 0, 0, 0}};
  setSign(&check, 1);
  s21_decimal result;
  initDecimal(&result);
  int return_number = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_number, OK);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test11) {
  int src = -49135648;
  s21_decimal check = {{49135648, 0, 0, 0}};
  setSign(&check, 1);
  s21_decimal result;
  initDecimal(&result);
  int return_number = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_number, OK);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test12) {
  int src = INT_MIN;
  s21_decimal expected = {{INT_MIN, 0, 0, 0}};
  setSign(&expected, 1);
  s21_decimal result;
  initDecimal(&result);

  int status = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test13) {
  int src = INT_MAX;
  s21_decimal expected = {{INT_MAX, 0, 0, 0}};
  s21_decimal result;
  initDecimal(&result);

  int status = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_is_equal(result, expected), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test14) {
  int src = 0;
  s21_decimal expected = {{0}};
  s21_decimal result;
  initDecimal(&result);

  int status = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(s21_is_equal(result, expected), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test15) {
  int src = rand() % INT_MAX;
  int sign = rand() % 2;
  s21_decimal expected = {{src, 0, 0, 0}};
  setSign(&expected, sign);
  s21_decimal result;
  initDecimal(&result);

  if (sign) src = -src;
  int status = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(result, expected), 1);
  ck_assert_int_eq(status, 0);
}
END_TEST

Suite *from_int_to_decimal_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("from_int_to_decimal");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_from_int_to_decimal_test1);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test2);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test3);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test4);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test5);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test6);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test7);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test8);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test9);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test10);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test11);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test12);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test13);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test14);
  tcase_add_loop_test(tc_core, s21_from_int_to_decimal_test15, 0, 20);
  suite_add_tcase(s, tc_core);
  return s;
}
