#include "../s21_decimal_tests.h"

START_TEST(from_decimal_to_float_test1) {
  s21_decimal decimalNumber = {{5, 0, 0, 2147483648}};
  float convertNumber = 0.0f;

  s21_from_decimal_to_float(decimalNumber, &convertNumber);
  ck_assert_float_eq(convertNumber, -5.0);
}
END_TEST

START_TEST(from_decimal_to_float_test2) {
  s21_decimal decimalNumber = {{5, 0, 0, 0}};
  float convertNumber = 0;

  s21_from_decimal_to_float(decimalNumber, &convertNumber);
  ck_assert_float_eq(convertNumber, 5.0);
}
END_TEST

START_TEST(from_decimal_to_float_test3) {
  s21_decimal decimalNumber = {{5, 0, 0, 131072}};
  float convertNumber = 0;

  s21_from_decimal_to_float(decimalNumber, &convertNumber);
  ck_assert_float_eq(convertNumber, 0.05);
}
END_TEST

START_TEST(from_decimal_to_float_test4) {
  s21_decimal decimalNumber = {{5, 0, 0, 262144}};
  float convertNumber = 0;

  s21_from_decimal_to_float(decimalNumber, &convertNumber);
  ck_assert_float_eq(convertNumber, 0.0005);
}
END_TEST

START_TEST(from_decimal_to_float_test5) {
  s21_decimal decimalNumber = {{5, 0, 0, 2147549184}};
  float convertNumber = 0;

  s21_from_decimal_to_float(decimalNumber, &convertNumber);
  ck_assert_float_eq(convertNumber, -0.5);
}
END_TEST

START_TEST(from_decimal_to_float_test6) {
  s21_decimal decimalNumber = {{5, 0, 0, 0b10000000000000110000000000000000}};
  float convertNumber = 0;

  s21_from_decimal_to_float(decimalNumber, &convertNumber);
  ck_assert_float_eq(convertNumber, -0.005);
}
END_TEST

START_TEST(from_decimal_to_float_test7) {
  s21_decimal decimalNumber = {{5, 1, 0, 2147614720}};
  float convertNumber = 0;

  s21_from_decimal_to_float(decimalNumber, &convertNumber);
  ck_assert_float_eq(convertNumber, -42949672);
}
END_TEST
START_TEST(from_decimal_to_float_test8) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = 0;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test9) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = 34904134189576704.0;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000111100011111111001000000000;
  src.bits[1] = 0b00000000011111000000000100100000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test10) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = 4797149878494552330677518384.0f;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000001111110000000000000110000;
  src.bits[1] = 0b00000000000001111100000111001110;
  src.bits[2] = 0b00001111100000000001110000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test11) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = -393521882706865627597773856.0;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000000011100001110000100000;
  src.bits[1] = 0b00000001111100000000001000000000;
  src.bits[2] = 0b00000001010001011000001110000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test12) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = -9108633310992923625263104.0;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00001111000111000001000000000000;
  src.bits[1] = 0b00000000010011110010010001111000;
  src.bits[2] = 0b00000000000001111000100011010100;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST
START_TEST(from_decimal_to_float_test14) {}
END_TEST
START_TEST(from_decimal_to_float_test15) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = 1363063872823827967.09968961;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000000000000011110001000001;
  src.bits[1] = 0b00001111100011100000000000000000;
  src.bits[2] = 0b00000000011100001100000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test16) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = 5261245167433.773804376204256;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000001000100101010001111100000;
  src.bits[1] = 0b00000110100010010000000000000000;
  src.bits[2] = 0b00010001000000000000000000000000;
  src.bits[3] = 0b00000000000011110000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test17) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = 56609.69882341710923195780728;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00101111000111001000111001111000;
  src.bits[1] = 0b00111101100100010000111100001000;
  src.bits[2] = 0b00010010010010101010010100000000;
  src.bits[3] = 0b00000000000101110000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test18) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = 4.0708159123947745298861779463;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00101010100111111110101000000111;
  src.bits[1] = 0b00000000111001001001001001000000;
  src.bits[2] = 0b10000011100010010000000000000000;
  src.bits[3] = 0b00000000000111000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test19) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = 23725169413499.8007108015104;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00000000000001110001010000000000;
  src.bits[1] = 0b00011100010000000000000000000000;
  src.bits[2] = 0b00000000110001000100000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test20) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = -1518959805.3962457861114052012;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b01110001011100000011110110101100;
  src.bits[1] = 0b01110110111000011110010010111100;
  src.bits[2] = 0b00110001000101001000101010000000;
  src.bits[3] = 0b10000000000100110000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test21) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = -1481684277.941851392;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00100000000000010101010100000000;
  src.bits[1] = 0b00010100100100000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010010000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test23) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = -7003226049228.9212930415302656;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b00011100100010101001100000000000;
  src.bits[1] = 0b01111101100100111100101000111000;
  src.bits[2] = 0b11100010010010010101010000000000;
  src.bits[3] = 0b10000000000100000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test24) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = -1881943803254996.7908496299504;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b01010101000010010101010111110000;
  src.bits[1] = 0b11111110000010101010100001101000;
  src.bits[2] = 0b00111100110011110001001100000011;
  src.bits[3] = 0b10000000000011010000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test25) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = -20665389400527754396439297.4;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b11110000101000001011111000001110;
  src.bits[1] = 0b00001010101010011111000000111000;
  src.bits[2] = 0b00000000101010101111000010101010;
  src.bits[3] = 0b10000000000000010000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test26) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = -3300634434855034222975468124.0;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b11111111000010010100001001011100;
  src.bits[1] = 0b00111110000101010111000011100010;
  src.bits[2] = 0b00001010101010100011100010000111;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test27) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = 69737472270073788779167306064.0;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b11111110001001010101000101010000;
  src.bits[1] = 0b11110001011011011100010101010100;
  src.bits[2] = 0b11100001010101010111110000101010;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test28) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = -79228162514264337593543950335.0;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b11111111111111111111111111111111;
  src.bits[2] = 0b11111111111111111111111111111111;
  src.bits[3] = 0b10000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test29) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = 79228162514264337593543950335.0;
  int s21_output = 0;
  int origin_output = 0;
  // 79228162514264337593543950335.0
  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b11111111111111111111111111111111;
  src.bits[2] = 0b11111111111111111111111111111111;
  src.bits[3] = 0b00000000000000000000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test30) {
  s21_decimal src = {0};
  float dest = 0;
  float origin = 777777.777777;
  int s21_output = 0;
  int origin_output = 0;
  src.bits[0] = 0b11100111101011100111110001110001;
  src.bits[1] = 0b00000000000000000000011100010010;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001110000000000000000;
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(dest, origin);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test31) {
  s21_decimal src = {0};
  float *dest = NULL;
  int s21_output = 0;
  int origin_output = ERROR_CONVERTING;
  src.bits[0] = 0b11100111101011100111110001110001;
  src.bits[1] = 0b00000000000000000000011100010010;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001110000000000000000;
  s21_output = s21_from_decimal_to_float(src, dest);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

START_TEST(from_decimal_to_float_test32) {
  s21_decimal src = {0};
  float dest = 0;
  int s21_output = 0;
  int origin_output = ERROR_CONVERTING;
  src.bits[0] = 0b11100111101011100111110001110001;
  src.bits[1] = 0b00000000000000000000011100010010;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001110000000000000000;
  setScale(&src, 30);
  s21_output = s21_from_decimal_to_float(src, &dest);
  ck_assert_int_eq(s21_output, origin_output);
}
END_TEST

Suite *from_decimal_to_float_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("from_decimal_to_float");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, from_decimal_to_float_test1);
  tcase_add_test(tc_core, from_decimal_to_float_test2);
  tcase_add_test(tc_core, from_decimal_to_float_test3);
  tcase_add_test(tc_core, from_decimal_to_float_test4);
  tcase_add_test(tc_core, from_decimal_to_float_test5);
  tcase_add_test(tc_core, from_decimal_to_float_test6);
  tcase_add_test(tc_core, from_decimal_to_float_test7);
  tcase_add_test(tc_core, from_decimal_to_float_test8);
  tcase_add_test(tc_core, from_decimal_to_float_test9);
  tcase_add_test(tc_core, from_decimal_to_float_test10);
  tcase_add_test(tc_core, from_decimal_to_float_test11);
  tcase_add_test(tc_core, from_decimal_to_float_test12);
  tcase_add_test(tc_core, from_decimal_to_float_test14);
  tcase_add_test(tc_core, from_decimal_to_float_test15);
  tcase_add_test(tc_core, from_decimal_to_float_test16);
  tcase_add_test(tc_core, from_decimal_to_float_test17);
  tcase_add_test(tc_core, from_decimal_to_float_test18);
  tcase_add_test(tc_core, from_decimal_to_float_test19);
  tcase_add_test(tc_core, from_decimal_to_float_test20);
  tcase_add_test(tc_core, from_decimal_to_float_test21);
  tcase_add_test(tc_core, from_decimal_to_float_test23);
  tcase_add_test(tc_core, from_decimal_to_float_test24);
  tcase_add_test(tc_core, from_decimal_to_float_test25);
  tcase_add_test(tc_core, from_decimal_to_float_test26);
  tcase_add_test(tc_core, from_decimal_to_float_test27);
  tcase_add_test(tc_core, from_decimal_to_float_test28);
  tcase_add_test(tc_core, from_decimal_to_float_test29);
  tcase_add_test(tc_core, from_decimal_to_float_test30);
  tcase_add_test(tc_core, from_decimal_to_float_test31);
  tcase_add_test(tc_core, from_decimal_to_float_test32);
  suite_add_tcase(s, tc_core);
  return s;
}
