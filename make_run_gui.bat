@echo off

rem Copyright 2025 Aleksandr Bocharov
rem Distributed under the Boost Software License, Version 1.0.
rem See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
rem 2025-07-28
rem https://github.com/Aleksandr3Bocharov/RefalAB

set RAYLIB=F:\Programming\raylib-5.5_win64_mingw-w64
set RAYLIBCFLAGS=-Wall -O2 -I%RAYLIB%\include
set RAYLIBLFLAGS=-L%RAYLIB%\lib -lraylib -lgdi32 -lwinmm

if not exist bin mkdir bin
%REFALABBIN%\RefalAB src\RefalABEinshteinPuzzle_gui > RefalABEinshteinPuzzle_gui.log
as -o src\RefalABEinshteinPuzzle_gui.o src\RefalABEinshteinPuzzle_gui.s >> RefalABEinshteinPuzzle_gui.log
%REFALABBIN%\RefalAB src\Solver >> RefalABEinshteinPuzzle_gui.log
as -o src\Solver.o src\Solver.s >> RefalABEinshteinPuzzle_gui.log
clang %REFALABCFLAGS% -I%REFALABINCLUDE% -c src\RefalABEinshteinPuzzlec_gui.c -o src\RefalABEinshteinPuzzlec_gui.o >> RefalABEinshteinPuzzle_gui.log
clang %RAYLIBCFLAGS% -c src\gui.c -o src\gui.o >> RefalABEinshteinPuzzle_gui.log
clang -o bin\RefalABEinshteinPuzzle_gui.exe src\RefalABEinshteinPuzzle_gui.o src\RefalABEinshteinPuzzlec_gui.o src\Solver.o %REFALABLIB%\mainrf.o -L%REFALABLIB% -lRefalAB src\gui.o %RAYLIBLFLAGS% >> RefalABEinshteinPuzzle_gui.log
bin\RefalABEinshteinPuzzle_gui
