@echo off
cd "%~dp0"
set Path=C:\cygwin64\bin;%Path%
python3 setupwin.py
IF %ERRORLEVEL% NEQ 0 (
	echo Environment Setup Incomplete -- Cannot find manifest file.
	exit /b 1
)
call settmp.bat
del settmp.bat
@REM python3 CreatePackFile.py -f SAIL.SI.1.2_rtos.txt
@REM @echo on
@REM @echo "Generated Pack file for freertos"
@REM @echo off
echo Environment Setup Completed -- Run Make.