#!/bin/sh
set -ex
clear
flags="-std=c11 -Wall -Wextra -Wpedantic -Werror -g"
cc main.c $flags -o main.out
