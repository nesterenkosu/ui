#!/bin/tcsh

#Пример окна подтверждения действия

set user_name = `(whiptail \
 --title "Демонстрация окна подтвержения дейсвтия" \
 --yesno  "Действительно выполнить это действие?" \
 --ok-button "ОК" \
 --cancel-button "Отмена"\
 --defaultno \
 10 60 > /dev/tty) >& /dev/stdout`

if($? == 0) then
    echo "Вы согласились"
else
    echo "Вы отказались"
endif
