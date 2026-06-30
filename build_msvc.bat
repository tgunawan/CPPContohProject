@echo off
cd /d "c:\Users\Tedi Gunawan\MyDocuments\c++"
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
cl.exe /std:latest /EHsc "%1" /Fe"%~n1.exe"
