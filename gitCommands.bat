REM Commands Automated

@echo off

SET choice=
SET /p choice=What do you want to execute? (y/n/d): 

IF NOT '%choice%'=='' SET choice=%choice:~0,1%
IF '%choice%'=='Y' GOTO yes
IF '%choice%'=='y' GOTO yes
IF '%choice%'=='N' GOTO no
IF '%choice%'=='n' GOTO no
IF '%choice%'=='D' GOTO dat
IF '%choice%'=='d' GOTO dat
IF '%choice%'=='' GOTO no
ECHO "%choice%" is not valid
exit

:no
ECHO Canceling
EXIT

:yes

REM cd /d C:\path if needed

set message=%1

git add .
git commit -m "Done %message%"
git push

echo Commands executed with success

:dat

REM cd /d C:\path if needed

set message=%1
set date=%2

git add .
git commit --date="%date%" -m "Done %message%"
git push

echo Commands executed with success