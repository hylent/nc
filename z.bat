@echo off

taskkill /f /im php-cgi.exe
copy /y build\php_nc.dll e:\php\ext\
php --ri nc
