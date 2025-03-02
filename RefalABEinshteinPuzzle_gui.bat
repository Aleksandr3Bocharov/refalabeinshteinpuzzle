@echo off

rem Copyright 2025 Aleksandr Bocharov
rem Distributed under the Boost Software License, Version 1.0.
rem See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
rem 2025-03-03
rem https://github.com/Aleksandr3Bocharov/RefalAB

set RAYLIB=F:\Programming\raylib-5.5_win64_mingw-w64
set RAYLIBCFLAGS=-Wall -O2 -I%RAYLIB%\include
set RAYLIBLFLAGS=-L%RAYLIB%\lib -lraylib -lgdi32 -lwinmm

%REFALABBIN%\RefalAB RefalABEinshteinPuzzle_gui > RefalABEinshteinPuzzle_gui.log
as -o RefalABEinshteinPuzzle_gui.o RefalABEinshteinPuzzle_gui.asm >> RefalABEinshteinPuzzle_gui.log
clang %REFALABCFLAGS% -I%REFALABINCLUDE% -c RefalABEinshteinPuzzlec_gui.c -o RefalABEinshteinPuzzlec_gui.o >> RefalABEinshteinPuzzle_gui.log
clang %RAYLIBCFLAGS% -c gui.c -o gui.o >> RefalABEinshteinPuzzle_gui.log
clang -o RefalABEinshteinPuzzle_gui.exe RefalABEinshteinPuzzle_gui.o RefalABEinshteinPuzzlec_gui.o %REFALABLIB%\mainrf.o -L%REFALABLIB% -lRefalAB gui.o %RAYLIBLFLAGS% >> RefalABEinshteinPuzzle_gui.log
RefalABEinshteinPuzzle_gui
