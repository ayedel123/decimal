#include <check.h>
#include <limits.h>

#include "../s21_decimal.h"

#define TEST_CASES                                                             \
  getBitsTestsSuite(), getConvertingTestsSuite(), compare_test(),              \
      negate_truncle_test(), s21_floor_suite(), s21_round_suite(),             \
      s21_add_suite(), s21_div_suite(), s21_mul_suite(), s21_sub_suite()

#define ARSENIY_TEST_CASES                                                     \
  from_int_to_decimal_suite(), from_decimal_to_float_suite(),                  \
      from_float_to_decimal_suite(), from_decimal_to_int_suite()

Suite *compare_test(void);
Suite *negate_truncle_test(void);

Suite *getBitsTestsSuite();
Suite *getConvertingTestsSuite();
Suite *from_int_to_decimal_suite(void);
Suite *from_decimal_to_float_suite(void);
Suite *from_float_to_decimal_suite(void);
Suite *from_decimal_to_int_suite(void);
Suite *s21_add_suite();
Suite *s21_div_suite();
Suite *s21_mul_suite();
Suite *s21_sub_suite();
Suite *s21_floor_suite();
Suite *s21_round_suite();

void getDecimalFromString(s21_decimal *number, char *bitsString);
int is_equals_bits(s21_decimal *source, s21_decimal *target);
void getStringOfDecimal(s21_decimal *number, char *target);

typedef enum {
  errorCodeNoError = 0,
  errorCodeToLargeOrInfinity = 1,
  errorCodeTooSmallOrNegativeInfinity = 2,
  errorCodeDivisionByZero = 3,
} errorCodes;

#define ASSERT_DECIMAL_EQ(RESULT, EXPECTED)                                    \
  for (size_t i = 0; i < 4; i++) {                                             \
    ck_assert_msg(RESULT.bits[i] == EXPECTED.bits[i], "[%zu] %#x != %#x", i,   \
                  RESULT.bits[i], EXPECTED.bits[i]);                           \
  }
