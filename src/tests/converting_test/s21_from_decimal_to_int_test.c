#include "../s21_decimal_tests.h"

START_TEST(s21_from_decimal_to_int_test1) {
  s21_decimal test_dec = {{20, 0, 0, 0}};
  int param = 0, need_param = 20, error = 0;
  int func_error = s21_from_decimal_to_int(test_dec, &param);
  ck_assert_int_eq(param, need_param);
  ck_assert_int_eq(error, func_error);
}

END_TEST

START_TEST(s21_from_decimal_to_int_test2) {
  s21_decimal test_dec = {{20, 0, 0, 2147483648}};
  int param;
  s21_from_decimal_to_int(test_dec, &param);
  ck_assert_int_eq(param, -20);
}

END_TEST

START_TEST(s21_from_decimal_to_int_test3) {
  s21_decimal test_dec = {{2147483648, 0, 0, 2147483648}};
  int param, need_param = -2147483648;
  s21_from_decimal_to_int(test_dec, &param);
  ck_assert_int_eq(param, need_param);
}

END_TEST

START_TEST(s21_from_decimal_to_int_test4) {
  s21_decimal test_dec = {{2147483647, 0, 1, 2147483648}};
  int param;
  int error = s21_from_decimal_to_int(test_dec, &param);
  ck_assert_int_eq(error, 1);
}

END_TEST

START_TEST(s21_from_decimal_to_int_test5) {
  s21_decimal test_dec = {{2147483647, 1, 0, 2147483648}};
  int param;
  int error = s21_from_decimal_to_int(test_dec, &param);
  ck_assert_int_eq(error, 1);
}

END_TEST

START_TEST(s21_from_decimal_to_int_test6) {
  s21_decimal test_dec = {{2147483647, 1, 0, 0x30000}};  // exp = 3
  int param;
  s21_from_decimal_to_int(test_dec, &param);
  ck_assert_int_eq(param, 6442450);
}

END_TEST

START_TEST(s21_from_decimal_to_int_test7) {
  int temp = 0;
  s21_decimal number_1 = {{0, 0, 1, 0}};
  int return_number = s21_from_decimal_to_int(number_1, &temp);
  ck_assert_int_eq(return_number, 1);
}

END_TEST

START_TEST(s21_from_decimal_to_int_test8) {
  int src = 0;
  int temp = 100;
  s21_decimal number_1 = {{0, 0, 0, 0}};
  s21_from_decimal_to_int(number_1, &temp);
  int return_number = (src == temp);
  ck_assert_int_eq(return_number, 1);
}

END_TEST

START_TEST(s21_from_decimal_to_int_test9) {
  int src = 0;
  int temp = 0;
  s21_decimal number_1 = {{0x80000000, 0, 0, 0}};
  s21_from_decimal_to_int(number_1, &temp);
  int return_number = (src == temp);
  ck_assert_int_eq(return_number, 1);
}

END_TEST

START_TEST(s21_from_decimal_to_int_test10) {
  int src = 133;
  int temp = 0;
  s21_decimal number_1 = {{0x85, 0, 0, 0}};
  s21_from_decimal_to_int(number_1, &temp);
  int return_number = (src == temp);
  ck_assert_int_eq(return_number, 1);
}

END_TEST

START_TEST(s21_from_decimal_to_int_test11) {
  s21_decimal number = {{49135648, 0, 0, 0}};
  setSign(&number, 1);
  setScale(&number, 1);
  int array;
  int check = -4913564;
  int return_number = s21_from_decimal_to_int(number, &array);
  ck_assert_int_eq(array, check);
  ck_assert_int_eq(return_number, OK);
}

END_TEST

START_TEST(s21_from_decimal_to_int_test12) {
  s21_decimal number = {{49135648, 0, 0, 0}};
  setScale(&number, 1);
  int array;
  int check = 4913564;
  int return_number = s21_from_decimal_to_int(number, &array);
  ck_assert_int_eq(array, check);
  ck_assert_int_eq(return_number, OK);
}

END_TEST

START_TEST(s21_from_decimal_to_int_test13) {
  s21_decimal number = {{2, 3, 0, 0}};
  int array = 0;
  int check = 0;
  int return_number = s21_from_decimal_to_int(number, &array);
  ck_assert_int_eq(array, check);
  ck_assert_int_eq(return_number, ERROR_CONVERTING);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test14) {
  int expected = INT_MAX, result;
  s21_decimal src = {{INT_MAX, 0, 0, 0}};
  int status = s21_from_decimal_to_int(src, &result);

  ck_assert_int_eq(result, expected);
  ck_assert_int_eq(status, 0);
}

START_TEST(s21_from_decimal_to_int_test15) {
  int expected = INT_MIN, result = 0;

  s21_decimal src = {{INT_MIN, 0, 0, 0}};
  setSign(&src, 1);
  //  add_four_trailing_zeros(&src);
  int status = s21_from_decimal_to_int(src, &result);

  ck_assert_int_eq(result, expected);
  ck_assert_int_eq(status, 0);
}

START_TEST(s21_from_decimal_to_int_test16) {
  s21_decimal src = {{INT_MIN, 0, 0}};
  int result;

  //  add_four_trailing_zeros(&src);
  int status = s21_from_decimal_to_int(src, &result);

  ck_assert_int_eq(status, 1);
}

START_TEST(s21_from_decimal_to_int_test17) {
  int sign = rand() % 2, result;
  int expected = rand() % (sign ? INT_MIN : INT_MAX);
  if (sign) expected = -expected;
  s21_decimal src = {{sign ? -expected : expected, 0, 0, 0}};
  setSign(&src, sign);
  //  add_four_trailing_zeros(&src);
  int status = s21_from_decimal_to_int(src, &result);

  ck_assert_int_eq(result, expected);
  ck_assert_int_eq(status, 0);
}

Suite *from_decimal_to_int_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("from_decimal_to_int");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_from_decimal_to_int_test1);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test2);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test3);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test4);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test5);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test6);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test7);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test8);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test9);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test10);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test11);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test12);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test13);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test14);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test15);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test16);
  tcase_add_loop_test(tc_core, s21_from_decimal_to_int_test17, 0, 20);
  suite_add_tcase(s, tc_core);
  return s;
}
