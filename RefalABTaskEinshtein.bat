SET REFAL=F:\Programming\Projects\RefalAB

%REFAL%\bin\RefalAB RefalABEinshteinPuzzle > RefalABEinshteinPuzzle.log
as -o RefalABEinshteinPuzzle.o RefalABEinshteinPuzzle.asm >> RefalABEinshteinPuzzle.log
gcc -o RefalABEinshteinPuzzle.exe %REFAL%\lib\mainrf.o RefalABEinshteinPuzzle.o -Wl,-L%REFAL%\lib -Wl,-lRefalAB >> RefalABEinshteinPuzzle.log
RefalABEinshteinPuzzle
