#include <form.h>

#define N_FIELDS 6

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

    //Создание подписей полей
    char *captions[N_FIELDS]={
	"TYPE_ALPHA",
	"TYPE_ALNUM",
	"TYPE_ENUM",
	"TYPE_INTEGER",
	"TYPE_NUMERIC",
	"TYPE_REGEXP"
    };

    mvprintw(1,1,"HELLO");

    for(i=0;i<N_FIELDS;i++) {
	//Создание поля
	fields[i]=new_field(1,10,3+i*2,22,0,0);
	//назначение данному полю цветовой схемы
	set_field_back(fields[i],COLOR_PAIR(1));
    }
    fields[N_FIELDS]=NULL;

    //Назначение полям валидаторов
    set_field_type(fields[0],TYPE_ALPHA,4);
    set_field_type(fields[1],TYPE_ALNUM,4);

    char *enum_list[]={"One","Two","Three",NULL};
    set_field_type(fields[2],TYPE_ENUM,enum_list,1);
    set_field_type(fields[3],TYPE_INTEGER,5,1,99999);
    set_field_type(fields[4],TYPE_NUMERIC,5,0.001,99999);
    set_field_type(fields[5],TYPE_REGEXP,"^[A-Za-z0-9\\._-]+@[A-Za-z0-9_-]+\\.[A-Za-z0-9_-]+\\s*$");
    //set_field_type(fields[5],TYPE_REGEXP,"^abc\\w{7}$");


    //Создание собственно формы
    FORM *form;
    form=new_form(fields);
    //mvprintw(0,0,"HELLO BEFORE REFRESH");
    //отображение формы
    post_form(form);
    
    for(i=0;i<N_FIELDS;i++) {
	//Создание подписи
	mvprintw(3+i*2,2,captions[i]);
    }
    //перерисовка окна
    refresh();
    
    //Цикл обработки событий формы
    int ch;
    for(;;){
	ch=getch();
	switch(ch) {
	    case KEY_F(1): {
                form_driver(form,REQ_NEXT_CHOICE);
                break;
            }
            case 'A': {
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
		if(field_index(current_field(form))==2)
		    form_driver(form,REQ_NEXT_CHOICE);
		else
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
