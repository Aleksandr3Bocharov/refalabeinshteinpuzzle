SET REFAL=F:\Programming\Projects\RefalAB

%REFAL%\bin\RefalAB RefalABTaskEinshtein > RefalABTaskEinshtein.log
as -o RefalABTaskEinshtein.o RefalABTaskEinshtein.asm >> RefalABTaskEinshtein.log
gcc -o RefalABTaskEinshtein.exe %REFAL%\lib\mainrf.o RefalABTaskEinshtein.o -Wl,-L%REFAL%\lib -Wl,-lRefalAB >> RefalABTaskEinshtein.log
RefalABTaskEinshtein
