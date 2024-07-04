#include "s21_decimal_tests.h"

int less(float a, float b) { return a < b; }

START_TEST(less_test) {
  s21_decimal firstDc, secondDc;
  float firstAr[] = {0.0f,       1.0f,       -95.0f,   -999.1654f, 12316846.1f,
                     9999.9999f, 0.000009f,  0.99998f, 0.18f,      -0.19f,
                     -1.00953f,  -0.001984f, 1.00984f};
  float secondAr[] = {0.09f,     1.09f,      -95.01f,  -1000.1654f, 123162.0f,
                      10000.0f,  0.000010f,  1.00000f, 1.18f,       -0.29f,
                      -1.00954f, -1.001984f, 1.00974f};
  float thirdAr[] = {0.0f,       1.0f,       -95.0f,   -999.1654f, 12316846.1f,
                     9999.9999f, 0.000009f,  0.99998f, 0.18f,      -0.19f,
                     -1.00953f,  -0.001984f, 1.00984f};
  int fourAr[] = {0, 1, -1, 95, -95, -0, 12316846, 10000, -17};
  int fifthAr[] = {0, 3, -2, 96, -94, -11213, 12316845, 9999, 17};
  float first = 12.45f, second = 56.5f;
  initDecimal(&firstDc);
  initDecimal(&secondDc);
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    s21_from_float_to_decimal(secondAr[i], &secondDc);
    ck_assert_int_eq(s21_is_less(firstDc, secondDc),
                     less(firstAr[i], secondAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(secondAr[i], &firstDc);
    s21_from_float_to_decimal(firstAr[i], &secondDc);
    ck_assert_int_eq(s21_is_less(firstDc, secondDc),
                     less(secondAr[i], firstAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    s21_from_float_to_decimal(thirdAr[i], &secondDc);
    ck_assert_int_eq(s21_is_less(firstDc, secondDc),
                     less(firstAr[i], thirdAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int j = 0; j < 13; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_float_to_decimal(secondAr[j], &secondDc);
      ck_assert_int_eq(s21_is_less(firstDc, secondDc),
                       less(firstAr[i], secondAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_int_to_decimal(fourAr[j], &secondDc);
      ck_assert_int_eq(s21_is_less(firstDc, secondDc),
                       less(firstAr[i], (float)fourAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_int_to_decimal(fourAr[j], &secondDc);
      if (firstAr[i] != 0.000009f)
        ck_assert_int_eq(s21_is_less(secondDc, firstDc),
                         less((float)fourAr[j], firstAr[i]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 9; i++) {
      s21_from_int_to_decimal(fourAr[i], &firstDc);
      s21_from_int_to_decimal(fifthAr[j], &secondDc);
      //      if ( s21_is_less(firstDc, secondDc) !=  less((float)fourAr[j],
      //      (float)fifthAr[i]))
      //        printf("%d\t%d\n", fourAr[i], fifthAr[i]);
      ck_assert_int_eq(s21_is_less(firstDc, secondDc),
                       less((float)fourAr[i], (float)fifthAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }
}
END_TEST

int less_or_equal(float a, float b) { return a <= b; }

START_TEST(less_or_equal_test) {
  s21_decimal firstDc, secondDc;
  float firstAr[] = {0.0f,       1.0f,       -95.0f,   -999.1654f, 12316846.1f,
                     9999.9999f, 0.00009f,   0.99998f, 0.18f,      -0.19f,
                     -1.00953f,  -0.001984f, 1.00984f};
  float secondAr[] = {0.09f,     1.09f,      -95.01f,  -1000.1654f, 123162.0f,
                      10000.0f,  0.000010f,  1.00000f, 1.18f,       -0.29f,
                      -1.00954f, -1.001984f, 1.00974f};
  float thirdAr[] = {0.0f,       1.0f,       -95.0f,   -999.1654f, 12316846.1f,
                     9999.9999f, 0.00009f,   0.99998f, 0.18f,      -0.19f,
                     -1.00953f,  -0.001984f, 1.00984f};
  int fourAr[] = {0, 1, -1, 95, -95, -0, 12316846, 10000, -17};
  int fifthAr[] = {0, 3, -2, 96, -94, -11213, 12316845, 9999, 17};
  float first = 12.45f, second = 56.5f;
  initDecimal(&firstDc);
  initDecimal(&secondDc);
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    s21_from_float_to_decimal(secondAr[i], &secondDc);
    ck_assert_int_eq(s21_is_less_or_equal(firstDc, secondDc),
                     less_or_equal(firstAr[i], secondAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(secondAr[i], &firstDc);
    s21_from_float_to_decimal(firstAr[i], &secondDc);
    ck_assert_int_eq(s21_is_less_or_equal(firstDc, secondDc),
                     less_or_equal(secondAr[i], firstAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    s21_from_float_to_decimal(thirdAr[i], &secondDc);
    ck_assert_int_eq(s21_is_less_or_equal(firstDc, secondDc),
                     less_or_equal(firstAr[i], thirdAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int j = 0; j < 13; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_float_to_decimal(secondAr[j], &secondDc);
      ck_assert_int_eq(s21_is_less_or_equal(firstDc, secondDc),
                       less_or_equal(firstAr[i], secondAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_int_to_decimal(fourAr[j], &secondDc);
      ck_assert_int_eq(s21_is_less_or_equal(firstDc, secondDc),
                       less_or_equal(firstAr[i], (float)fourAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_int_to_decimal(fourAr[j], &secondDc);
      if (firstAr[i] != 0.000009f)
        ck_assert_int_eq(s21_is_less_or_equal(secondDc, firstDc),
                         less_or_equal((float)fourAr[j], firstAr[i]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 9; i++) {
      s21_from_int_to_decimal(fourAr[i], &firstDc);
      s21_from_int_to_decimal(fifthAr[j], &secondDc);
      ck_assert_int_eq(s21_is_less_or_equal(firstDc, secondDc),
                       less_or_equal((float)fourAr[i], (float)fifthAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }
}
END_TEST

int greater(float a, float b) { return a > b; }

START_TEST(greater_test) {
  s21_decimal firstDc, secondDc;
  float firstAr[] = {0.0f,       1.0f,       -95.0f,   -999.1654f, 12316846.1f,
                     9999.9999f, 0.00009f,   0.99998f, 0.18f,      -0.19f,
                     -1.00953f,  -0.001984f, 1.00984f};
  float secondAr[] = {0.09f,     1.09f,      -95.01f,  -1000.1654f, 123162.0f,
                      10000.0f,  0.000010f,  1.00000f, 1.18f,       -0.29f,
                      -1.00954f, -1.001984f, 1.00974f};
  float thirdAr[] = {0.0f,       1.0f,       -95.0f,   -999.1654f, 12316846.1f,
                     9999.9999f, 0.00009f,   0.99998f, 0.18f,      -0.19f,
                     -1.00953f,  -0.001984f, 1.00984f};
  int fourAr[] = {0, 1, -1, 95, -95, -0, 12316846, 10000, -17};
  int fifthAr[] = {0, 3, -2, 96, -94, -11213, 12316845, 9999, 17};
  float first = 12.45f, second = 56.5f;
  initDecimal(&firstDc);
  initDecimal(&secondDc);
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    s21_from_float_to_decimal(secondAr[i], &secondDc);
    ck_assert_int_eq(s21_is_greater(firstDc, secondDc),
                     greater(firstAr[i], secondAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(secondAr[i], &firstDc);
    s21_from_float_to_decimal(firstAr[i], &secondDc);
    ck_assert_int_eq(s21_is_greater(firstDc, secondDc),
                     greater(secondAr[i], firstAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    s21_from_float_to_decimal(thirdAr[i], &secondDc);
    ck_assert_int_eq(s21_is_greater(firstDc, secondDc),
                     greater(firstAr[i], thirdAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int j = 0; j < 13; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_float_to_decimal(secondAr[j], &secondDc);
      ck_assert_int_eq(s21_is_greater(firstDc, secondDc),
                       greater(firstAr[i], secondAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_int_to_decimal(fourAr[j], &secondDc);
      ck_assert_int_eq(s21_is_greater(firstDc, secondDc),
                       greater(firstAr[i], (float)fourAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_int_to_decimal(fourAr[j], &secondDc);
      ck_assert_int_eq(s21_is_greater(secondDc, firstDc),
                       greater((float)fourAr[j], firstAr[i]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 9; i++) {
      s21_from_int_to_decimal(fourAr[i], &firstDc);
      s21_from_int_to_decimal(fifthAr[j], &secondDc);
      ck_assert_int_eq(s21_is_greater(firstDc, secondDc),
                       greater((float)fourAr[i], (float)fifthAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }
}
END_TEST

int greater_or_equal(float a, float b) { return a >= b; }

START_TEST(greater_or_equal_test) {
  s21_decimal firstDc, secondDc;
  float firstAr[] = {0.0f,       1.0f,       -95.0f,   -999.1654f, 12316846.1f,
                     9999.9999f, 0.00009f,   0.99998f, 0.18f,      -0.19f,
                     -1.00953f,  -0.001984f, 1.00984f};
  float secondAr[] = {0.09f,     1.09f,      -95.01f,  -1000.1654f, 123162.0f,
                      10000.0f,  0.000010f,  1.00000f, 1.18f,       -0.29f,
                      -1.00954f, -1.001984f, 1.00974f};
  float thirdAr[] = {0.0f,       1.0f,       -95.0f,   -999.1654f, 12316846.1f,
                     9999.9999f, 0.00009f,   0.99998f, 0.18f,      -0.19f,
                     -1.00953f,  -0.001984f, 1.00984f};
  int fourAr[] = {0, 1, -1, 95, -95, -0, 12316846, 10000, -17};
  int fifthAr[] = {0, 3, -2, 96, -94, -11213, 12316845, 9999, 17};
  float first = 12.45f, second = 56.5f;
  initDecimal(&firstDc);
  initDecimal(&secondDc);
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    s21_from_float_to_decimal(secondAr[i], &secondDc);
    ck_assert_int_eq(s21_is_greater_or_equal(firstDc, secondDc),
                     greater_or_equal(firstAr[i], secondAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(secondAr[i], &firstDc);
    s21_from_float_to_decimal(firstAr[i], &secondDc);
    ck_assert_int_eq(s21_is_greater_or_equal(firstDc, secondDc),
                     greater_or_equal(secondAr[i], firstAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    s21_from_float_to_decimal(thirdAr[i], &secondDc);
    ck_assert_int_eq(s21_is_greater_or_equal(firstDc, secondDc),
                     greater_or_equal(firstAr[i], thirdAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int j = 0; j < 13; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_float_to_decimal(secondAr[j], &secondDc);
      ck_assert_int_eq(s21_is_greater_or_equal(firstDc, secondDc),
                       greater_or_equal(firstAr[i], secondAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_int_to_decimal(fourAr[j], &secondDc);
      ck_assert_int_eq(s21_is_greater_or_equal(firstDc, secondDc),
                       greater_or_equal(firstAr[i], (float)fourAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_int_to_decimal(fourAr[j], &secondDc);
      ck_assert_int_eq(s21_is_greater_or_equal(secondDc, firstDc),
                       greater_or_equal((float)fourAr[j], firstAr[i]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 9; i++) {
      s21_from_int_to_decimal(fourAr[i], &firstDc);
      s21_from_int_to_decimal(fifthAr[j], &secondDc);
      ck_assert_int_eq(s21_is_greater_or_equal(firstDc, secondDc),
                       greater_or_equal((float)fourAr[i], (float)fifthAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }
}
END_TEST

int equal(float a, float b) { return a == b; }

START_TEST(equal_test) {
  s21_decimal firstDc, secondDc;
  float firstAr[] = {0.0f,       1.0f,       -95.0f,   -999.1654f, 12316846.1f,
                     9999.9999f, 0.00009f,   0.99998f, 0.18f,      -0.19f,
                     -1.00953f,  -0.001984f, 1.00984f};
  float secondAr[] = {0.09f,     1.09f,      -95.01f,  -1000.1654f, 123162.0f,
                      10000.0f,  0.000010f,  1.00000f, 1.18f,       -0.29f,
                      -1.00954f, -1.001984f, 1.00974f};
  float thirdAr[] = {0.0f,       1.0f,       -95.0f,   -999.1654f, 12316846.1f,
                     9999.9999f, 0.00009f,   0.99998f, 0.18f,      -0.19f,
                     -1.00953f,  -0.001984f, 1.00984f};
  int fourAr[] = {0, 1, -1, 95, -95, -0, 12316846, 10000, -17};
  int fifthAr[] = {0, 3, -2, 96, -94, -11213, 12316845, 9999, 17};
  float first = 12.45f, second = 56.5f;
  initDecimal(&firstDc);
  initDecimal(&secondDc);
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    s21_from_float_to_decimal(secondAr[i], &secondDc);
    ck_assert_int_eq(s21_is_equal(firstDc, secondDc),
                     equal(firstAr[i], secondAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(secondAr[i], &firstDc);
    s21_from_float_to_decimal(firstAr[i], &secondDc);
    ck_assert_int_eq(s21_is_equal(firstDc, secondDc),
                     equal(secondAr[i], firstAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    s21_from_float_to_decimal(thirdAr[i], &secondDc);
    ck_assert_int_eq(s21_is_equal(firstDc, secondDc),
                     equal(firstAr[i], thirdAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int j = 0; j < 13; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_float_to_decimal(secondAr[j], &secondDc);
      ck_assert_int_eq(s21_is_equal(firstDc, secondDc),
                       equal(firstAr[i], secondAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_int_to_decimal(fourAr[j], &secondDc);
      ck_assert_int_eq(s21_is_equal(firstDc, secondDc),
                       equal(firstAr[i], (float)fourAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_int_to_decimal(fourAr[j], &secondDc);
      ck_assert_int_eq(s21_is_equal(secondDc, firstDc),
                       equal((float)fourAr[j], firstAr[i]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 9; i++) {
      s21_from_int_to_decimal(fourAr[i], &firstDc);
      s21_from_int_to_decimal(fifthAr[j], &secondDc);
      ck_assert_int_eq(s21_is_equal(firstDc, secondDc),
                       equal((float)fourAr[i], (float)fifthAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }
}
END_TEST

int not_equal(float a, float b) { return a != b; }

START_TEST(not_equal_test) {
  s21_decimal firstDc, secondDc;
  float firstAr[] = {0.0f,       1.0f,       -95.0f,   -999.1654f, 12316846.1f,
                     9999.9999f, 0.00009f,   0.99998f, 0.18f,      -0.19f,
                     -1.00953f,  -0.001984f, 1.00984f};
  float secondAr[] = {0.09f,     1.09f,      -95.01f,  -1000.1654f, 123162.0f,
                      10000.0f,  0.000010f,  1.00000f, 1.18f,       -0.29f,
                      -1.00954f, -1.001984f, 1.00974f};
  float thirdAr[] = {0.0f,       1.0f,       -95.0f,   -999.1654f, 12316846.1f,
                     9999.9999f, 0.00009f,   0.99998f, 0.18f,      -0.19f,
                     -1.00953f,  -0.001984f, 1.00984f};
  int fourAr[] = {0, 1, -1, 95, -95, -0, 12316846, 10000, -17};
  int fifthAr[] = {0, 3, -2, 96, -94, -11213, 12316845, 9999, 17};
  float first = 12.45f, second = 56.5f;
  initDecimal(&firstDc);
  initDecimal(&secondDc);
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    s21_from_float_to_decimal(secondAr[i], &secondDc);
    ck_assert_int_eq(s21_is_not_equal(firstDc, secondDc),
                     not_equal(firstAr[i], secondAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(secondAr[i], &firstDc);
    s21_from_float_to_decimal(firstAr[i], &secondDc);
    ck_assert_int_eq(s21_is_not_equal(firstDc, secondDc),
                     not_equal(secondAr[i], firstAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int i = 0; i < 13; i++) {
    s21_from_float_to_decimal(firstAr[i], &firstDc);
    s21_from_float_to_decimal(thirdAr[i], &secondDc);
    ck_assert_int_eq(s21_is_not_equal(firstDc, secondDc),
                     not_equal(firstAr[i], thirdAr[i]));
    initDecimal(&firstDc);
    initDecimal(&secondDc);
  }
  for (int j = 0; j < 13; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_float_to_decimal(secondAr[j], &secondDc);
      ck_assert_int_eq(s21_is_not_equal(firstDc, secondDc),
                       not_equal(firstAr[i], secondAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_int_to_decimal(fourAr[j], &secondDc);
      ck_assert_int_eq(s21_is_not_equal(firstDc, secondDc),
                       not_equal(firstAr[i], (float)fourAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 13; i++) {
      s21_from_float_to_decimal(firstAr[i], &firstDc);
      s21_from_int_to_decimal(fourAr[j], &secondDc);
      ck_assert_int_eq(s21_is_not_equal(secondDc, firstDc),
                       not_equal((float)fourAr[j], firstAr[i]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }

  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 9; i++) {
      s21_from_int_to_decimal(fourAr[i], &firstDc);
      s21_from_int_to_decimal(fifthAr[j], &secondDc);
      ck_assert_int_eq(s21_is_not_equal(firstDc, secondDc),
                       not_equal((float)fourAr[i], (float)fifthAr[j]));
      initDecimal(&firstDc);
      initDecimal(&secondDc);
    }
}
END_TEST

Suite *compare_test(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("COMPARE");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, less_test);
  tcase_add_test(tc_core, less_or_equal_test);
  tcase_add_test(tc_core, greater_test);
  tcase_add_test(tc_core, greater_or_equal_test);
  tcase_add_test(tc_core, equal_test);
  tcase_add_test(tc_core, not_equal_test);
  suite_add_tcase(s, tc_core);
  return s;
}
