#!/bin/tcsh

#Пример вывода содержимого текстового файла

whiptail \
--scrolltext \
--title "Просмотр файла file.txt " \
--textbox file.txt 10 30
