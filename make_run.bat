@echo off

rem Copyright 2025 Aleksandr Bocharov
rem Distributed under the Boost Software License, Version 1.0.
rem See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
rem 2025-07-28
rem https://github.com/Aleksandr3Bocharov/RefalAB

if not exist bin mkdir bin
%REFALABBIN%\RefalAB src\RefalABEinshteinPuzzle > RefalABEinshteinPuzzle.log
as -o src\RefalABEinshteinPuzzle.o src\RefalABEinshteinPuzzle.s >> RefalABEinshteinPuzzle.log
%REFALABBIN%\RefalAB src\Solver >> RefalABEinshteinPuzzle.log
as -o src\Solver.o src\Solver.s >> RefalABEinshteinPuzzle.log
clang -o bin\RefalABEinshteinPuzzle.exe src\RefalABEinshteinPuzzle.o src\Solver.o %REFALABLIB%\mainrf.o -L%REFALABLIB% -lRefalAB >> RefalABEinshteinPuzzle.log
bin\RefalABEinshteinPuzzle
