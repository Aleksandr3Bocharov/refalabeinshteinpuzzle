@echo off

rem Copyright 2024 Aleksandr Bocharov
rem Distributed under the Boost Software License, Version 1.0.
rem See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
rem 2024-10-23
rem https://github.com/Aleksandr3Bocharov/RefalAB

%REFALABBIN%\RefalAB RefalABEinshteinPuzzle > RefalABEinshteinPuzzle.log
as -o RefalABEinshteinPuzzle.o RefalABEinshteinPuzzle.asm >> RefalABEinshteinPuzzle.log
clang -o RefalABEinshteinPuzzle.exe RefalABEinshteinPuzzle.o %REFALABLIB%\mainrf.o -L%REFALABLIB% -lRefalAB >> RefalABEinshteinPuzzle.log
RefalABEinshteinPuzzle
