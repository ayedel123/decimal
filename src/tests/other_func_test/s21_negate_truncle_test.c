#include "../s21_decimal_tests.h"

START_TEST(negate_test) {
  s21_decimal firstDc, secondDc;
  float firstAr[] = {0.0f,        1.0f,       -95.0f,     -999.1654f,
                     12316846.1f, 9999.9999f, 0.00009f,   0.99998f,
                     0.18f,       -0.19f,     -0.001984f, 1.00984f};
  float secondAr[] = {-0.0f,        -1.0f,       95.0f,     999.1654f,
                      -12316846.1f, -9999.9999f, -0.00009f, -0.99998f,
                      -0.18f,       0.19f};  //, 0.001984f,
                                             //-1.00984f};//, 1.0953f,
  int fourAr[] = {0, 1, -1, 95, -95, -0, 12316846, 10000, 17};
  int fifthAr[] = {-0, -1, 1, -95, 95, 0, -12316846, -10000, -17};
  initDecimal(&firstDc);
  initDecimal(&secondDc);
  for (int i = 0; i < 11; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    //     s21_from_float_to_decimal(firstAr[i] ,&secondDc);
    s21_negate(firstDc, &secondDc);
    ck_assert_int_eq(getSign(&firstDc), !getSign(&secondDc));
    ck_assert_int_eq(firstDc.bits[0], secondDc.bits[0]);
    ck_assert_int_eq(firstDc.bits[1], secondDc.bits[1]);
    ck_assert_int_eq(firstDc.bits[2], secondDc.bits[2]);
  }
  for (int i = 0; i < 10; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    // s21_from_float_to_decimal(firstAr[i] ,&secondDc);
    s21_negate(firstDc, &secondDc);
    ck_assert_int_eq(getSign(&firstDc), !getSign(&secondDc));
    ck_assert_int_eq(firstDc.bits[0], secondDc.bits[0]);
    ck_assert_int_eq(firstDc.bits[1], secondDc.bits[1]);
    ck_assert_int_eq(firstDc.bits[2], secondDc.bits[2]);
  }

  for (int i = 0; i < 9; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    // s21_from_float_to_decimal(firstAr[i] ,&secondDc);
    s21_negate(firstDc, &secondDc);
    ck_assert_int_eq(getSign(&firstDc), !getSign(&secondDc));
    ck_assert_int_eq(firstDc.bits[0], secondDc.bits[0]);
    ck_assert_int_eq(firstDc.bits[1], secondDc.bits[1]);
    ck_assert_int_eq(firstDc.bits[2], secondDc.bits[2]);
  }

  for (int i = 0; i < 9; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    // s21_from_float_to_decimal(firstAr[i] ,&secondDc);
    s21_negate(firstDc, &secondDc);
    ck_assert_int_eq(getSign(&firstDc), !getSign(&secondDc));
    ck_assert_int_eq(firstDc.bits[0], secondDc.bits[0]);
    ck_assert_int_eq(firstDc.bits[1], secondDc.bits[1]);
    ck_assert_int_eq(firstDc.bits[2], secondDc.bits[2]);
  }
}
END_TEST

START_TEST(truncate_test) {
  // FILE *f = fopen("tests/manual_test_py/test_data.txt", "w");
  // fclose(f);

  s21_decimal firstDc, secondDc;
  float firstAr[] = {0.0f,        1.0f,     -95.0f,   -999.1654f,
                     12316846.1f, 9999.99f, 0.00009f, 0.99998f,
                     0.18f,       0.19f};  //  -0.001984f, 1.00984f};
  float secondAr[] = {0.0f, 1.0f, -95.0f, -999.0f, 12316846.0f, 9999.0f,
                      0.0f, 0.0f, 0.0f,   0.0f};  //  -0.001984f, 1.00984f};
  int fourAr[] = {0, 1, -1, 95, -95, -0, 12316846, 10000, 17};
  initDecimal(&firstDc);
  initDecimal(&secondDc);
  for (int i = 0; i < 10; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);

    s21_truncate(firstDc, &secondDc);
    s21_from_int_to_decimal((int)firstAr[i], &firstDc);
    // writeDecimalInFile(firstDc, "tests/manual_test_py/test_data.txt");
    // writeDecimalInFile(secondDc, "tests/manual_test_py/test_data.txt");
    ASSERT_DECIMAL_EQ(firstDc, secondDc);
  }
  // for (int i = 0; i < 9; i++) {
  //   s21_from_int_to_decimal(fourAr[i], &firstDc);
  //   s21_truncate(firstDc, &secondDc);
  //   float tmp;
  //   s21_from_decimal_to_float(secondDc, &tmp);
  //   ck_assert_float_eq(tmp, fourAr[i]);
  //   initDecimal(&firstDc);
  //   initDecimal(&secondDc);
  // }
}
END_TEST

Suite *negate_truncle_test(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("OTHER_FUNCTION");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, negate_test);
  tcase_add_test(tc_core, truncate_test);

  suite_add_tcase(s, tc_core);
  return s;
}
