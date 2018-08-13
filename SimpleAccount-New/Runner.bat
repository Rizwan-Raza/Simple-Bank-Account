@echo off
prompt Nakki:$g 
REM runs only if g++ command is added to the path variable
:label
cls
g++ -Imantasha SimpleAccount.cpp -o SimpleAccount
pause 
SimpleAccount
echo Want to Run it again ? If Yes, Press any key else Ctrl+C or close this window
pause >nul
goto label