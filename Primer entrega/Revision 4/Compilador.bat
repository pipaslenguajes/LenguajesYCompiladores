C:\GnuWin32\bin\flex lexico.l
pause
C:\GnuWin32\bin\bison -dyv sintactico.y
pause
C:\MinGW\bin\gcc.exe lex.yy.c y.tab.c -o Primera.exe
pause