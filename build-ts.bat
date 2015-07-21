@echo off
pushd %~dp0
set protots=protogx

del /Q /S "*.ts"
%protots% typescript ./

if "%1"=="" pause
