#include "prog.h"
#include <stdio.h>
#include <fcntl.h>
#include <QtDebug>

Prog::Prog(QWidget *parent):QMainWindow(parent)
{
	//Создание необходимых компоновочных виджетов
	vbox = new QVBoxLayout(this);//вертикального
	hbox = new QHBoxLayout(this);//и горизонтального
	
	//добавление горизонтального компоновочного виджета внутрь вертикального
	vbox->addLayout(hbox);
	
	//Создание формы для задания параметров игрового поля
	lb_h = new QLabel(tr("Высота"),this);
	hbox->addWidget(lb_h);
	
	ed_h = new QLineEdit(this);
	hbox->addWidget(ed_h);
	
	lb_w = new QLabel(tr("Ширина"),this);
	hbox->addWidget(lb_w);
	
	ed_w = new QLineEdit(this);
	hbox->addWidget(ed_w);
	
	btn_go = new QPushButton(tr("Ввод"),this);
	hbox->addWidget(btn_go);
	
	//Инициализация флага создания поля "в первый раз"
	is_first=1;
	
	//Сделать вертикальный компоновочный виджет основным
	//в данном окне
	QWidget *w = new QWidget();
	w->setLayout(vbox);
	setCentralWidget(w);
	
	//Назначение обработчика на кнопку создания поля
	connect(btn_go,SIGNAL(clicked()),this,SLOT(btn_go_clicked()));
}

void Prog::btn_go_clicked() {
	//Определение размеров создаваемого поля
	//на основе значений, введённых пользователем в форму
	qint32 h = ed_h->text().toInt();
	qint32 w = ed_w->text().toInt();
	
	//Если поле создаётся не в первый раз
	if(is_first!=1) {
	    delete(grid);//предварительно удалим старое поле
	}
	
	//Собственно создание поля
	//создание виджета табличной компоновки
	grid=new QGridLayout(this);
	grid->setSpacing(0);//убрать отступ между ячейками таблицы
	
	QPushButton *b;
	for(qint32 i=0;i<h;i++)
	    for(qint32 j=0;j<w;j++) {
		//создание клетки поля на основе кнопки
		b=new QPushButton(" ",this);
		//растянуть кнопку на всю ширину и высоту ячейки таблицы
		b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
		//добавить кнопку в ячейку таблицы
		grid->addWidget(b,i,j);
		//назначить обработчик нажатия на кнопку - клетку поля
		connect(b,SIGNAL(clicked()),this,SLOT(gameboard_clicked()));
	    }
	
	//добавить виджет табличной компоновки внутрь вертикального компоновочного виджета
	vbox->addLayout(grid);
	
	//сбросить флаг создания поля "в первый раз"
	is_first=0;
}

void Prog::gameboard_clicked() {
    //Обработка нажатия на кнопке - клетке игрового поля -
    //вывод знака * на нажатой кнопке
    ((QPushButton*)QObject::sender())->setText("*");
}


