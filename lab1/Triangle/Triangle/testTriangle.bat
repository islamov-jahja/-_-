REM equilateral triangle
Triangle.exe 1 1 1
REM isosceles triangle
Triangle.exe 2 3 3
REM simple triangle
Triangle.exe 3 4 5
REM there is no such triangle
Triangle.exe 1 2 3
REM incorrect count of argument
Triangle.exe 1 2 3 4
IF NOT ERRORLEVEL 1 GOTO err
ECHO Program testing succeeded :-)
EXIT

:ERR
ECHO Program testing failed :-(