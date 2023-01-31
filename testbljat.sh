#!/bin/bash

gcc -o sp -Wall -Wextra -Werror sprintf.c
# gcc -o s21_sp -Wall -Wextra -Werror s21vers2.c


./sp > logsp.txt
./s21_sp > logs21.txt

diff -s logs21.txt logsp.txt