#include <form.h>

#define N_FIELDS 3

int main() {
    //инициализация ncurses
    initscr();
    
    //включение цветного режима (по умолчанию
    //режим монохромный)
    start_color();
    
    //выключение отображения нажатых клавиш на экране
    noecho();
    
    cbreak();
    
    keypad(stdscr,TRUE);
    
    
    //Активация мыши
    mousemask(ALL_MOUSE_EVENTS,NULL);
    
    //определение цветовых пар (комбинаций "цвет текста" - "цвет фона")
    init_pair(1,COLOR_RED,COLOR_WHITE);
    
    FIELD *fields[N_FIELDS];
    
    int i;
    for(i=0;i<N_FIELDS;i++) {
	//создание собственно поля
	fields[i]=new_field(1,10,3+i*2,12,0,0);
	//определение цвета для поля
	set_field_back(fields[i],COLOR_PAIR(1));
    }
    
    fields[N_FIELDS]=NULL;
    
    //создание собственно формы
    FORM *form;
    form=new_form(fields);
    
    //отображение формы
    post_form(form);
    
    //перерисовка окна
    refresh();
    
    for(i=0;i<N_FIELDS;i++) {
	//создание подписи к полю
	mvprintw(3+i*2,2,"Field # %d",i);
    }
    
    //цикл обработки событий
    int ch;
    for(;;){
	ch=getch();
	switch(ch) {
	    case KEY_F1: {
		form_driver(form,REQ_NEXT_CHOICE);
		break;
	    }
	    case KEY_F2: {
		form_driver(form,REQ_PREV_CHOICE);
		break;
	    }
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
	    case 10: {
		form_driver(form,REQ_NEXT_FIELD);
		mvprintw(LINES-1,0,"You entered [%s]",field_buffer(fields[2],0));
		break;
	    }
	    case KEY_MOUSE: {
		form_driver(form,KEY_MOUSE);
		break;
	    }
	    default: {
		//ввод символа в текущее поле
		form_driver(form,ch);
		break;
	    }
	}
    }
    
    //Деактивация ncurses
    endwin();
    return 0;
}
