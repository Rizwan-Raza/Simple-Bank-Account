@echo off
prompt Rex:$g 
REM runs only if g++ command is added to the path variable
:label
cls
g++ -Irizzu Account.cpp -o Account
pause 
Account
echo Want to Run it again ? If Yes, Press any key else Ctrl+C or close this window
pause >nul
goto label