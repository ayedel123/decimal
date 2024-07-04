CC = gcc -std=c11
CFLAGS = -Wall -Wextra -Werror -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
SOURCES = s21*.c s21*.h
SOURCES_API = decimal_api/s21*.h decimal_api/s21*.c
OBJECT = $(patsubst %*.c, %*.o, $(SOURCES))
SOURCES_TEST = tests/*.c tests/arithmetic_tests/*.c tests/other_func_test/*.c tests/converting_test/*.c
OS = $(shell uname -s)

ifeq ($(OS), Linux)
  CFLAGS += -D OS_LINUX
  CHECK_FLAGS = -lpthread -lcheck -pthread -lrt -lm -lsubunit
endif
ifeq ($(OS), Darwin)
  CFLAGS += -D OS_MAC
  CHECK_FLAGS = -lcheck
endif

all: clean s21_decimal.a

s21_decimal.a:
	$(CC) $(CFLAGS) -c $(SOURCES) $(SOURCES_API)
	@ar rcs s21_decimal.a $(OBJECT)
	@rm -rf ./*.o

build_test: rebuild_lib
	$(CC) $(SOURCES_TEST)  s21_decimal.a $(CHECK_FLAGS) -o test


test: build_test
	./test


valgrind: build_test
	valgrind -s  --track-origins=yes --tool=memcheck --leak-check=yes ./test

gcov_report: rebuild_lib
	@gcc $(GCOV_FLAGS) $(SOURCES_TEST) $(SOURCES) $(SOURCES_API) $(CHECK_FLAGS) -o GcovReport
	@./GcovReport
	@lcov -t "GcovReport" -o GcovReport.info -c -d .
	@genhtml -o report GcovReport.info
	@open ./report/index-sort-f.html
	@rm -rf ./*.gcno ./*gcda ./GcovReport.*

clang:
	@cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c  $(SOURCES_API) $(SOURCES) $(SOURCES_TEST)
	clang-format -i *.c $(SOURCES_API) $(SOURCES) $(SOURCES_TEST)
	@rm .clang-format

cppcheck:
	cppcheck --enable=all --force *.c  $(SOURCES_API) $(SOURCES)


leaks: test
	leaks -atExit -- ./test

rebuild_lib: clean s21_decimal.a

manual_test: rebuild_lib
	gcc s21_decimal.a tests/manual_test.c && ./a.out

arithmetic_test: clean s21_decimal.a 
	$(CC)  tests/arithmetic_test.c -lcheck s21_decimal.a -o arithmetic_test.out
	./arithmetic_test.out

py_arithmetic_test: arithmetic_test
	python tests/manual_test_py/test.py

s21_add_test: clean s21_decimal.a
	$(CC) -Wall -Wextra tests/arithmetic_tests/add_test.c -lcheck s21_decimal.a -o add_test.out
	./add_test.out
s21_div_test: clean s21_decimal.a
	$(CC) -Wall -Wextra tests/arithmetic_tests/div_test.c -lcheck s21_decimal.a -o div_test.out
	./div_test.out
s21_sub_test: clean s21_decimal.a
	$(CC) -Wall -Wextra tests/arithmetic_tests/sub_test.c -lcheck s21_decimal.a -o sub_test.out
	./sub_test.out
s21_mul_test: clean s21_decimal.a
	$(CC) -Wall -Wextra tests/arithmetic_tests/mul_test.c -lcheck s21_decimal.a -o mul_test.out
	./mul_test.out

s21_arithmetic_test: clean s21_decimal.a
	$(CC) -Wall -Wextra tests/arithmetic_tests/arithmetic_tests.c -lcheck s21_decimal.a -o arithmetic_test.out
	./arithmetic_test.out
	python tests/manual_test_py/test.py

asya_add_test: clean s21_decimal.a
	$(CC) -Wall -Wextra tests/AsyaTest/s21_add_test.c -lcheck s21_decimal.a -o asya_add_test.out
	./asya_add_test.out
asya_mul_test: clean s21_decimal.a
	$(CC) -Wall -Wextra tests/AsyaTest/s21_mul_test.c -lcheck s21_decimal.a -o asya_mul_test.out
	./asya_mul_test.out
asya_div_test: clean s21_decimal.a
	$(CC) tests/AsyaTest/s21_div_test.c -lcheck s21_decimal.a -o asya_div_test.out
	./asya_div_test.out

rassim_arithmetic_tests:
	$(CC) tests/Rusim/test.c tests/Rusim/arithmetic_tests.c -lcheck s21_decimal.a -o rasim_arithmetic_test.out
	./rasim_arithmetic_test.out

clean:
	@rm -rf ./a.out ./*.o ./*.a ./test ./GcovReport ./report ./*.info ./*.gcno ./*gcda ./*.gch tests/.out ./*.out decimal_api/*.gch

