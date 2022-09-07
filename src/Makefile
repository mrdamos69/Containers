CC := gcc
CFLAGS := -ggdb -std=c++20 -Wall -Werror -Wextra -lstdc++
C_LIBS :=
TST_LIBS := -lgtest -lgmock -pthread

all: rebuild

build:

rebuild: clean build

s21_array.o: array/array.cc array/array.h
	@$(CC) -c array/array.cc -o s21_array.o $(C_LIBS) $(CFLAGS) -DUSE_EXPORT

s21_list.o: list/list.cc list/list.h
	@$(CC) -c list/list.cc -o s21_list.o $(C_LIBS) $(CFLAGS) -DUSE_EXPORT

s21_map.o: map/map.cc map/map.h
	@$(CC) -c map/map.cc -o s21_map.o $(C_LIBS) $(CFLAGS) -DUSE_EXPORT

s21_multiset.o: multiset/multiset.cc multiset/multiset.h
	@$(CC) -c multiset/multiset.cc -o s21_multiset.o $(C_LIBS) $(CFLAGS) -DUSE_EXPORT

s21_queue.o: queue/queue.cc queue/queue.h
	@$(CC) -c queue/queue.cc -o s21_queue.o $(C_LIBS) $(CFLAGS) -DUSE_EXPORT

s21_set.o: set/set.cc set/set.h
	@$(CC) -c set/set.cc -o s21_set.o $(C_LIBS) $(CFLAGS) -DUSE_EXPORT

s21_stack.o: stack/stack.cc stack/stack.h
	@$(CC) -c stack/stack.cc -o s21_stack.o $(C_LIBS) $(CFLAGS) -DUSE_EXPORT

s21_vector.o: vector/vector.cc vector/vector.h
	@$(CC) -c vector/vector.cc -o s21_vector.o $(C_LIBS) $(CFLAGS) -DUSE_EXPORT

s21_test.o: s21_test.cc s21_containers.h s21_containersplus.h
	@$(CC) -c s21_test.cc -o s21_test.o $(C_LIBS) $(CFLAGS)

s21_containers.a: s21_list.o s21_map.o s21_queue.o s21_set.o s21_stack.o s21_vector.o
	@ar rc s21_containers.a s21_list.o s21_map.o s21_queue.o s21_set.o s21_stack.o s21_vector.o
	@ranlib s21_containers.a

s21_containersplus.a: s21_array.o s21_multiset.o
	@ar rc s21_containersplus.a s21_array.o s21_multiset.o
	@ranlib s21_containersplus.a

test: s21_test
	@clang-format -i ./*.cc ./*.h *.cc *.h
	@./s21_test

s21_test:  clean s21_test.o s21_containers.a s21_containersplus.a
	@$(CC) s21_test.o s21_containers.a s21_containersplus.a -o s21_test $(TST_LIBS) $(CFLAGS) -g

gcov_test: clean s21_test.o s21_containers.a s21_containersplus.a
	@$(CC) --coverage s21_test.o */*.cc -o gcov_test $(TST_LIBS) $(CFLAGS)

gcov_test.gcda: gcov_test
	@chmod +x *
	@./gcov_test

gcov_test.info: gcov_test gcov_test.gcda
	@lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .

gcov_report: clean gcov_test.info
	@genhtml -o report/ gcov_test.info
	@open report/index.html

report_open: gcov_report
	@open report/index.html

clean: clean_test
	@rm -rf ./*.o
	@rm -rf ./*.a
	@rm -rf ./*.dSYM
	@rm -rf ./s21_test
	@rm -rf ./gcov_test
	@rm -rf ./RESULT_VALGRIND.txt

clean_test:
	@rm -rf report/ gcov_test exe *.gcda *.gcno *.info CPPLINT.cfg

check:
	@cp ../materials/linters/.clang-format ./
	@clang-format -n ./*.cc ./*.h ./*/*.cc ./*/*.h
#	@rm -rf .clang-format

git: clean
	@git add *.cc *.h Makefile Dockerfile *.sh scripts/* ./*/*.cc ./*/*.h
	@git commit -m "add changes ${m}"
	@git push origin brittabu

valgrind:
	@./run.sh

leaks: $(ALL_FILE_O)
	@CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./s21_test

