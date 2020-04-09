#ifndef PROG_H
#define PROG_H


#include <QMainWindow>
#include <QApplication>
#include <QTextCodec>
#include <QPushButton>

class Prog: public QMainWindow
{		
	Q_OBJECT
	public:	
		Prog(QWidget *parent=0);		
		QPushButton *btn;
	private slots:	//Обработчики событий	
		void btn_onclick();
		
};
#endif
