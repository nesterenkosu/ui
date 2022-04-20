#!/bin/tcsh

#Пример получения значения, введённого в текстовое поле

set user_name = `(whiptail \
 --title "Демонстрация окна inputbox" \
 --inputbox  "Введите ваше имя" \
 --ok-button "ОК" \
 --cancel-button "Отмена"\
 10 60 > /dev/tty) >& /dev/stdout`

if($? == 0) then
    echo "Здравствуй, $user_name ! Спасибо, что нажал ОК"
else
    echo "Прощай, аноним! Зря ты нажал на Отмена"
endif


