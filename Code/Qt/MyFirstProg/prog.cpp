#include "prog.h"

Prog::Prog(QWidget *parent):QMainWindow(parent)
{	
	//Создание объекта виджета кнопки
	btn=new QPushButton(tr("Нажми сюда"),this);
	//Задание координат и размеров кнопки
	btn->setGeometry(10,10,200,100);
	
	//Назначение обработчика события нажатия на кнопку
	connect(btn,SIGNAL(clicked()),this,SLOT(btn_onclick()));
}

void Prog::btn_onclick() {
    //Вывод текста на кнопке
    btn->setText(tr("Поздравляем! Вы сделали это!!!"));
}

