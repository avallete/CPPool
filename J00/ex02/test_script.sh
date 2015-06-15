#!/bin/bash

g++ -Wall -Wextra -Werror Account.class.cpp Account.class.hpp test.cpp;
cat 19920104_091532.log | cut -c 19- > us;
./a.out | cut -c 19- > our;
diff -c us our;
