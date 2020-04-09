#include "prog.h"

Prog::Prog(QWidget *parent):QMainWindow(parent)
{	
	//Создание виджета вертикальной компоновки
	QVBoxLayout *vbox;
	vbox=new QVBoxLayout(this);
	
	//Создание текстовой метки
	QLabel *lb_Hint = new QLabel(tr("Введите ваше имя:"),this);
	vbox->addWidget(lb_Hint); //Добавление виджета текстовой метки к вертикальной компновке (добавление на форму)
	
	//Создание поля ввода текста
	ed_Name = new QLineEdit(this);
	vbox->addWidget(ed_Name);//Добавление его на форму
	
	//Создание кнопки
	btn=new QPushButton(tr("Ввод"),this);
	vbox->addWidget(btn);
	
	//Создание текстовой метки для вывода приветствия
	lb_Greeting=new QLabel("",this);
	vbox->addWidget(lb_Greeting);
	
	//Назначение vbox в качестве основного компоновочного виджета окна
	QWidget *w=new QWidget();
	w->setLayout(vbox);
	setCentralWidget(w);
	
	//Назначение обработчика события нажатия на кнопку
	connect(btn,SIGNAL(clicked()),this,SLOT(btn_clicked()));
}

void Prog::btn_clicked() {
    //Вывод приветствия
    lb_Greeting->setText(tr("Здравствуйте, ")+ed_Name->text()+"!");
}



