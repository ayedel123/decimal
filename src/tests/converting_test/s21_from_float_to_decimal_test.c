#include "../s21_decimal_tests.h"
#define EXP_TO_COMPARE 1e-6

void checkFloatTest(s21_decimal number, float should) {
  float res = 0.0f;
  s21_from_decimal_to_float(number, &res);
  ck_assert_msg(fabsf(should - res) < EXP_TO_COMPARE, "%.7f %.7f", should, res);
}

START_TEST(s21_from_float_to_decimal_test1) {
  float zero = 0.0f, val = zero;
  s21_decimal dec_1;
  initDecimal(&dec_1);
  s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(val, 0.0);
  ck_assert_int_eq(dec_1.bits[0], 0);
  ck_assert_int_eq(dec_1.bits[1], 0);
  ck_assert_int_eq(dec_1.bits[2], 0);
  ck_assert_int_eq(dec_1.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test2) {
  float zero = 0.0, val = (0 / zero);
  s21_decimal dec_1;
  int res = s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test3) {
  float zero = 0.0, val = (1.0 / zero);
  s21_decimal dec_1;
  int res = s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test4) {
  float val = 1e-29;
  s21_decimal dec_1;
  int res = s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test5) {
  float val = 79228162514264337593543950336.0f;
  s21_decimal dec_1;
  int res = s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test6) {
  float val = -79228162514264337593543950336.0;
  s21_decimal dec_1;
  int res = s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test7) {
  float val = 792281625142643.3;
  s21_decimal dec_1;
  s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(dec_1.bits[0], 1879048192);
  ck_assert_int_eq(dec_1.bits[1], 184467);
  ck_assert_int_eq(dec_1.bits[2], 0);
  ck_assert_int_eq(dec_1.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test8) {
  float val = -792281625142643.3;
  s21_decimal dec_1;
  s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(dec_1.bits[0], 1879048192);
  ck_assert_int_eq(dec_1.bits[1], 184467);
  ck_assert_int_eq(dec_1.bits[2], 0);
  ck_assert_int_eq(dec_1.bits[3], 2147483648);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test9) {
  float val = 0.7922816251426433;
  s21_decimal dec_1;
  s21_from_float_to_decimal(val, &dec_1);
  checkFloatTest(dec_1, val);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test10) {
  float val = -0.7922816251426433;
  s21_decimal dec_1;
  s21_from_float_to_decimal(val, &dec_1);
  checkFloatTest(dec_1, val);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test11) {
  float val = 0.0000000000000001;
  s21_decimal dec_1;
  s21_from_float_to_decimal(val, &dec_1);
  checkFloatTest(dec_1, val);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test12) {
  float val = 10000000000000000.0;
  s21_decimal dec_1;
  s21_from_float_to_decimal(val, &dec_1);
  checkFloatTest(dec_1, val);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test13) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 5.0, need_param = 5.0;
  int need_3_bit = 0;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], need_param);
  ck_assert_int_eq(test_dec.bits[3], need_3_bit);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test14) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 0.05;

  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 5);
  ck_assert_int_eq(test_dec.bits[3], 131072);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test15) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 0.005;

  s21_from_float_to_decimal(param, &test_dec);
  float param_res = 0;
  s21_from_decimal_to_float(test_dec, &param_res);
  ck_assert_float_ge_tol(param_res, param, EXP_TO_COMPARE);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test16) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = -0.5;

  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 5);
  ck_assert_int_eq(test_dec.bits[3], 2147549184);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test17) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = -0.05;

  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 5);
  ck_assert_int_eq(test_dec.bits[3], 2147614720);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test18) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 50;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 50);
  ck_assert_int_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test19) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 5000;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 5000);
  ck_assert_int_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test20) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 2147483;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 2147483);
  ck_assert_int_eq(test_dec.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test21) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = 0.2147483;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 2147483);
  ck_assert_int_eq(test_dec.bits[3], 458752);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test22) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = -0.2147483;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 2147483);
  ck_assert_int_eq(test_dec.bits[3], 458752 + 2147483648);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test23) {
  s21_decimal test_dec = {{0, 0, 0, 0}};
  float param = -2147483;
  s21_from_float_to_decimal(param, &test_dec);
  ck_assert_int_eq(test_dec.bits[0], 2147483);
  ck_assert_int_eq(test_dec.bits[3], 2147483648);
}
END_TEST

Suite *from_float_to_decimal_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("from_float_to_decimal");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_from_float_to_decimal_test1);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test2);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test3);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test4);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test5);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test6);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test7);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test8);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test9);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test10);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test11);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test12);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test13);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test14);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test15);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test16);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test17);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test18);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test19);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test20);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test21);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test22);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test23);
  suite_add_tcase(s, tc_core);
  return s;
}
