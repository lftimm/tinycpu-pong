#!/bin/sh
g++ -std=c++20 -O0\
    -Wall -Werror -Weffc++ -Wextra -Wconversion -Wsign-conversion -ggdb \
    main.cpp TinyCpu.cpp -o tinyCpu
