# include <stdio.h>
# include <ncurses.h>
# include <menu.h>

int main(int argc, char *argv[])
{
    //Инициализация библиотеки
    initscr();
    
    //Сообщаем системе, что нужно
    //кроме алф.циф. символов
    //принимать управляющие символы
    //F1-F12, стрелки, backspace и т.д.
    keypad(stdscr,TRUE);
    
    //Активация мыши
    mousemask(ALL_MOUSE_EVENTS,NULL);
    
    MENU *menu;
    ITEM *items[4];
    
    //Создание элементов меню
    items[0]=new_item("One","");
    items[1]=new_item("Two","");
    items[2]=new_item("Three","");
    items[3]=(ITEM *)NULL;

    //Связывание с пунктом меню некоторых данных
    int i,values[3],*cur_item;
    for(i=0;i<3;i++){
	values[i]=i;
	set_item_userptr(items[i],&values[i]);
    }
    
    //Создание собственно меню
    menu=new_menu(items);

    start_color();//включение цветного режима
    //инициализация используемых в программе
    //цветовых пар - "цвет текста"-"цвет фона"
    init_pair(1,COLOR_YELLOW,COLOR_BLUE);
    init_pair(2,COLOR_WHITE,COLOR_RED);

    //применение цветовых пар к меню
    set_menu_back(menu,COLOR_PAIR(1));//цветовая схема для невыделенного пункта меню
    set_menu_fore(menu,COLOR_PAIR(2));//цветовая схема для выделенного пункта меню
    
    //Отображение меню
    post_menu(menu);
    
    //Перерисовка окна
    wrefresh(stdscr);
    
    int ch;
    
    //Цикл обработки событий
    for(;;){
	//Получение нажатой клавиши
	ch=getch();
	
	switch(ch) {
	    //Нажата "стрелка вверх"
	    case KEY_UP: {
		//выделить пункт меню, находящийся выше текущего
		//сдвинуть "планку" вверх
		menu_driver(menu,REQ_UP_ITEM);
		break;
	    }
	    
	    case KEY_DOWN: {
		//сдвинуть "планку" вниз
		menu_driver(menu,REQ_DOWN_ITEM);
		break;
	    }
	    
	    case 10: {//Если нажата клавиша Enter
		//Получение выбранного пункта меню
		//и вывод его в статусную строку
		
		//считывание значения, связанного с 
		//выбранным пунктом меню
		cur_item=item_userptr(current_item(menu));
		
		//вывод считанного значения
		mvprintw(
		    LINES-1,//последняя строка на экране
		    0, //вывод текста начиная с позиции первого символа
		    "You selected: [%d]",
		    *cur_item
		);
		break;
	    }
	    case KEY_MOUSE: {
		//обработать событие мыши 
		//(сдвинуть "планку" на тот пункт меню,
		//по которому щёлкнули)
		menu_driver(menu,KEY_MOUSE);
		break;
	    }
	}
	
	//Перерисовка экрана
	wrefresh(stdscr);
    }
    
    //Деактивация библиотеки
    endwin();
    return 0;
}
