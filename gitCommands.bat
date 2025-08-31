REM Commands Automated

@echo off

SET choice=
SET /p choice=Do you want to execute the commands? (y/n): 

IF NOT '%choice%'=='' SET choice=%choice:~0,1%
IF '%choice%'=='Y' GOTO yes
IF '%choice%'=='y' GOTO yes
IF '%choice%'=='N' GOTO no
IF '%choice%'=='n' GOTO no
IF '%choice%'=='' GOTO no
ECHO "%choice%" is not valid
exit

:no
ECHO Canceling
EXIT

:yes

REM cd /d C:\path if needed

set message=%1

git branch %message%
git checkout %message%

git add .
git commit -m "Done %message%"
git push --set-upstream origin %message%

git checkout main
git merge %message%
git push

git branch -d %message%
git push

echo Commands executed with success