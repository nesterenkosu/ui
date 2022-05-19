#include <form.h>

#define N_FIELDS 4

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
    
    //Объявление подписей для полей
    char *captions[N_FIELDS+1]={
	"",
	"Login",
	"Age",
	"City",
	"Email"
    };

    //Создание полей формы
    FIELD *fields[N_FIELDS];
    int i;
    for(i=0;i<N_FIELDS;i++){
	fields[i]=new_field(1,10,3+i*2,17,0,0);
	//назначение цветовой схемы данному полю
	set_field_back(fields[i],COLOR_PAIR(1));
    }
    fields[N_FIELDS]=NULL;

    //Валидация ввода
    set_field_type(fields[0],TYPE_ALPHA,2);//Login
    set_field_type(fields[1],TYPE_INTEGER,0,18,150);//Age
    char *cities[]={
	"Chelyabinsk",
	"Yekaterinburg",
	"Moscow",
	NULL
    };
    set_field_type(fields[2],TYPE_ENUM,cities);//City
    
    set_field_type(fields[3],TYPE_REGEXP,"^[A-Za-z0-9\\._-]+@[A-Za-z0-9_-]+\\.[A-Za-z0-9_-]+\\s*$");//Email
    
    //Создание собственно формы
    FORM *form;
    form=new_form(fields);

    //отображение формы
    post_form(form);
    

    //Вывод подписей полей
    for(i=1;i<=N_FIELDS;i++){
	mvprintw(3+(i-1)*2,2,"%s",captions[i]);
    }

    //перерисовка окна
    refresh();

    //Цикл обработки событий формы
    int ch;
    for(;;){
	ch=getch();
	switch(ch) {
	    /*case 'Q': {
		form_driver(form,REQ_NEXT_CHOICE);
		break;
	    }
	    case 'A': {
		form_driver(form,REQ_PREV_CHOICE);
		break;
	    }*/
	    case KEY_DOWN: {
		form_driver(form,REQ_NEXT_FIELD);
		break;
	    }
	    case KEY_UP: {
		form_driver(form,REQ_PREV_FIELD);
		break;
	    }
	    case KEY_RIGHT: {
		//Проверка, что активно поле City
		if(field_index(current_field(form))==2)
		    form_driver(form,REQ_NEXT_CHOICE);//Выбор сл.элемента списка
		else
		    form_driver(form,REQ_NEXT_CHAR);//Переход к сл.полю
		break;
	    }
	    case KEY_LEFT: {
		//Проверка, что активно поле City
		if(field_index(current_field(form))==2)
		    form_driver(form,REQ_PREV_CHOICE);//Выбор предыд.элемента списка
		else
		    form_driver(form,REQ_PREV_CHAR);//Переход к предыд.полю
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
