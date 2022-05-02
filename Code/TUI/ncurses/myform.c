#include <form.h>

#define N_FIELDS 3

int main() {
    //Инициализация nCurses
    initscr();

    noecho();//не выводить на экран нажатые клавиши

    cbreak();//режим, при котором ввод не буферизуется

    keypad(stdscr,TRUE);//включение поддержки функциональных клавиш (стрелки, F1-F12)

    start_color();//включение цветного режима
    //-----------------
    
    //Задание цветовой схемы для полей ввода
    init_pair(1,COLOR_RED,COLOR_WHITE);

    //Создание полей формы
    FIELD *fields[N_FIELDS];
    int i;
    for(i=0;i<N_FIELDS;i++){
	fields[i]=new_field(1,10,3+i*2,12,0,0);
	//назначение цветовой схемы данному полю
	set_field_back(fields[i],COLOR_PAIR(1));
    }
    fields[N_FIELDS]=NULL;

    //Создание собственно формы
    FORM *form;
    form=new_form(fields);

    //отображение формы
    post_form(form);
    
    //перерисовка окна
    refresh();

    //Цикл обработки событий формы
    int ch;
    for(;;){
	ch=getch();
	switch(ch) {
	    case KEY_DOWN: {
		form_driver(form,REQ_NEXT_FIELD);
		break;
	    }
	    case KEY_UP: {
		form_driver(form,REQ_PREV_FIELD);
		break;
	    }
	    case KEY_RIGHT: {
		form_driver(form,REQ_NEXT_CHAR);
		break;
	    }
	    case KEY_LEFT: {
		form_driver(form,REQ_PREV_CHAR);
		break;
	    }
	    case KEY_BACKSPACE: {
		form_driver(form,REQ_DEL_PREV);
		break;
	    }
	    default: {
		//вывод нажатых символов в текущее текстовое поле
		form_driver(form,ch);
		break;
	    }
	}
    }
    //-----------------

    //Деактивация nCurses
    endwin();
    return 0;
}
