OS := $(shell uname -s)
CC = g++
FLAG = 
FLAG_C = -c 
CL_11 = -std=c++17 -Wall -Wextra
PR_NAME = S21_containers
ALL_FILE = s21_list.cpp
ALL_FILE_O = s21_list.o

ifeq ($(OS), Darwin)
	FLAGS_PLATFORM = -lgtest
else
	FLAGS_PLATFORM = -lgtest -lsubunit -lrt -lm -lpthread -g
endif

all: clean $(PR_NAME).a test
# all: clean temp_test

temp_test:
	@$(CC) s21_list.cpp 
	@./a.out

$(PR_NAME).a:
	@$(CC) $(FLAG_C) $(ALL_FILE) 
	@ar rcs $(PR_NAME).a $(ALL_FILE_O)

test: $(PR_NAME).a
	@$(CC) $(CL_11) unit_test.cpp $(PR_NAME).a -o tests.o -lgtest
	@./tests.o

gcov_report:
	@$(CC) --coverage $(ALL_FILE) unit_test.cpp $(FLAGS_PLATFORM) -o gov_report.o
	@./gov_report.o
	@lcov -t $(PR_NAME)_tests -o $(PR_NAME)_tests.info -c -d .
	@genhtml -o report $(PR_NAME)_tests.info
	@open ./report/index.html

clean:
	@rm -f *.a
	@rm -f *.o
	@rm -f *.out
	@rm -f *.gcda
	@rm -f *.gcdo
	@rm -f *.gcno
	@rm -f *.info

style: $(ALL_FILE)
	@cp ../materials/linters/CPPLINT.cfg ./
	@python3 ./../materials/linters/cpplint.py --extensions=cpp $(ALL_FILE) unit_test.cpp
	@rm -f CPPLINT.cfg

cppcheck: $(ALL_FILE_O)
	@cppcheck --enable=all --suppress=missingIncludeSystem . $(ALL_FILE)

check: style cppcheck
