#include "prog.h"


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	//Необходимо для поддержки русского шрифта
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

	Prog win;

	//Здесь можно настроить параметры окна
	//win.setWindowTitle(QObject::tr("Заголовок"));

	win.show();

	return app.exec();
}
