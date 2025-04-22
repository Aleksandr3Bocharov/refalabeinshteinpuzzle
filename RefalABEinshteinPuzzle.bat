@echo off

rem Copyright 2025 Aleksandr Bocharov
rem Distributed under the Boost Software License, Version 1.0.
rem See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
rem 2025-03-21
rem https://github.com/Aleksandr3Bocharov/RefalAB

%REFALABBIN%\RefalAB RefalABEinshteinPuzzle > RefalABEinshteinPuzzle.log
as -o RefalABEinshteinPuzzle.o RefalABEinshteinPuzzle.s >> RefalABEinshteinPuzzle.log
%REFALABBIN%\RefalAB Solver >> RefalABEinshteinPuzzle.log
as -o Solver.o Solver.s >> RefalABEinshteinPuzzle.log
clang -o RefalABEinshteinPuzzle.exe RefalABEinshteinPuzzle.o Solver.o %REFALABLIB%\mainrf.o -L%REFALABLIB% -lRefalAB >> RefalABEinshteinPuzzle.log
RefalABEinshteinPuzzle
