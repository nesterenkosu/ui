#ifndef PROG_H
#define PROG_H


#include <QMainWindow>
#include <QApplication>
#include <QTextCodec>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


class Prog: public QMainWindow
{		
	Q_OBJECT
	public:
		QVBoxLayout *vbox;
		QHBoxLayout *hbox;
		QGridLayout *grid;
		QLabel *lb_w,*lb_h;
		QLineEdit *ed_w,*ed_h;
		QPushButton *btn_go;
		qint32 is_first;
		
		Prog(QWidget *parent=0);
		
	private slots:	//Обработчики событий	
		void btn_go_clicked();
		void gameboard_clicked();
};
#endif
