#!/bin/bash
echo -e "-------------------------------------------------------------------------------\n"
BUILD_SCRIPT=scripts/build.sh
OUTPUT=$(bash ${BUILD_SCRIPT} part1)
printf 'Build output:\n %s\n' "$OUTPUT"
BUILD_RESULT=${OUTPUT: -1}
printf 'Build result: %s\n' "$BUILD_RESULT"
echo -e "-------------------------------------------------------------------------------\n"
echo -e "\n"

CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./s21_test
echo ""
echo ""
cat RESULT_VALGRIND.txt
