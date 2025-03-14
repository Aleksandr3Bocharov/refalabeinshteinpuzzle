#!/bin/sh 

# Copyright 2025 Aleksandr Bocharov
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
# 2024-03-14
# https://github.com/Aleksandr3Bocharov/RefalAB

$REFALABBIN/RefalAB RefalABEinshteinPuzzle > RefalABEinshteinPuzzle.log
as -o RefalABEinshteinPuzzle.o RefalABEinshteinPuzzle.s >> RefalABEinshteinPuzzle.log
clang -o RefalABEinshteinPuzzle RefalABEinshteinPuzzle.o $REFALABLIB/mainrf.o -L$REFALABLIB -lRefalAB >> RefalABEinshteinPuzzle.log
./RefalABEinshteinPuzzle
