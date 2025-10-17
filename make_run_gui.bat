@echo off

rem Copyright 2025 Aleksandr Bocharov
rem Distributed under the Boost Software License, Version 1.0.
rem See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
rem 2025-10-17
rem https://github.com/Aleksandr3Bocharov/refalabeinshteinpuzzle

set RAYLIB=F:\Programming\raylib-5.5_win64_mingw-w64
set RAYLIBCFLAGS=-Wall -O2 -I%RAYLIB%\include
set RAYLIBLFLAGS=-L%RAYLIB%\lib -lraylib -lgdi32 -lwinmm

if not exist bin mkdir bin
%REFALABBIN%\refalabc src\refalabeinshteinpuzzle_gui -a,"-o src\refalabeinshteinpuzzle_gui.o" > refalabeinshteinpuzzle_gui.log
%REFALABBIN%\refalabc src\solver -a,"-o src\solver.o" >> refalabeinshteinpuzzle_gui.log
clang %REFALABCFLAGS% -I%REFALABINCLUDE% -c src\refalabeinshteinpuzzlec_gui.c -o src\refalabeinshteinpuzzlec_gui.o >> refalabeinshteinpuzzle_gui.log
clang %RAYLIBCFLAGS% -c src\gui.c -o src\gui.o >> refalabeinshteinpuzzle_gui.log
clang -o bin\refalabeinshteinpuzzle_gui.exe src\refalabeinshteinpuzzle_gui.o src\refalabeinshteinpuzzlec_gui.o src\solver.o %REFALABLIB%\obj\mainrf.o -L%REFALABLIB% -lrefalab src\gui.o %RAYLIBLFLAGS% >> refalabeinshteinpuzzle_gui.log
bin\refalabeinshteinpuzzle_gui
