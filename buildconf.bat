rmdir /S /Q build
if exist build (goto error)
mkdir build
cd build
cmake -G"NMake Makefiles" ..
if errorlevel 1 goto error

goto success
:error
echo "buildconf failed!"
goto end
:success
echo "buildconf success!"
goto end
:end