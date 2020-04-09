#ifndef PROG_H
#define PROG_H


#include <QMainWindow>
#include <QApplication>
#include <QTextCodec>

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Prog: public QMainWindow
{		
	Q_OBJECT
	public:
		Prog(QWidget *parent=0);		
		QLineEdit *ed_Name;
		QLabel *lb_Greeting;
		QPushButton *btn;
	private slots:	//Обработчики событий	
		void btn_clicked();
		
};
#endif
