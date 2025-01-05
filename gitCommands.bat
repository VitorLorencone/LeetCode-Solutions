echo Do you want to execute the commands? (y/n)
set /p confirm=
if /i not "%confirm%"=="y" (
    echo Canceling.
    exit /b
)

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

git tag archieve/%message% %message%
git branch -d %message%
git push
git push --tags

echo Commands executed with success