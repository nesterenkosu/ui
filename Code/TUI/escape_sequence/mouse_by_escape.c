#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct my_mouse {
    char offset[3];
    char button;
    char x,y;
};

int main() {
    char c;
    struct termios tty, savetty;

    //Если stdin - не терминал, то работать смысла нет
    if(!isatty(0)){
	printf("stdin is not a tty!\n");
	return -1;
    }
    
    printf("Нажимайте на что-нибудь у мышки. \
	    \nПрограмма обработает 100 нажатий и завершится\n");

    //Вывод ESCAPE-последовательности, активирующей работу мыши
    printf("\e[?1000h");
    //getchar();

    fflush(stdout);//вывели буфер
    tcgetattr(0,&tty);//получили структуру termios
    savetty = tty;//сохранили
    tty.c_lflag &= ~(ISIG | ICANON);
    tty.c_cc[VMIN]=1;
    
    int i;
    for(i=0;i<100;i++){
	tty.c_lflag=0;
	//Настраиваем терминал таким образом, чтобы
	//нажатия на клавиши обрабатывались сразу же
	//(без ожидания нажатия на клавишу ENTER)
	tcsetattr(0,TCSAFLUSH, &tty);

	//Считывание символов с информацией о событиях мыши
	struct my_mouse m = {{0},0,0,0};
	read(0,&m,sizeof(struct my_mouse));

	//Возврат терминала в обычный режим
	//(когда клавиатурный ввод обрабатывается
	//при нажатии на ENTER)
	tcsetattr(0,TCSANOW,&savetty);
	
	//Вывод считанных координат курсора и нажатых кнопок мыши
	printf("btn[%d] x=[%d] y=[%d]\n",m.button,m.x-33,m.y-33);fflush(stdout);
    }
    
    return 0;
}
