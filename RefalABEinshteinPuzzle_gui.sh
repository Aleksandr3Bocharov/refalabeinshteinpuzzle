#!/bin/sh 

# Copyright 2025 Aleksandr Bocharov
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
# 2025-03-03
# https://github.com/Aleksandr3Bocharov/RefalAB

RAYLIBCFLAGS="-Wall -O2"
RAYLIBLFLAGS="-lraylib -lm"

$REFALABBIN/RefalAB RefalABEinshteinPuzzle_gui > RefalABEinshteinPuzzle_gui.log
as -o RefalABEinshteinPuzzle_gui.o RefalABEinshteinPuzzle_gui.asm >> RefalABEinshteinPuzzle_gui.log
clang $REFALABCFLAGS -I$REFALABINCLUDE -c RefalABEinshteinPuzzlec_gui.c -o RefalABEinshteinPuzzlec_gui.o >> RefalABEinshteinPuzzle_gui.log
clang $RAYLIBCFLAGS -c gui.c -o gui.o >> RefalABEinshteinPuzzle_gui.log
clang -o RefalABEinshteinPuzzle_gui RefalABEinshteinPuzzle_gui.o RefalABEinshteinPuzzlec_gui.o $REFALABLIB/mainrf.o -L$REFALABLIB -lRefalAB gui.o $RAYLIBLFLAGS >> RefalABEinshteinPuzzle_gui.log
./RefalABEinshteinPuzzle_gui
