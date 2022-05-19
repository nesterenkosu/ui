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
    
    int i,values[3],*cur_item;
    for(i=0;i<3;i++) {
	values[i]=i;
	set_item_userptr(items[i],&values[i]);
    }
    
    //Создание собственно меню
    menu=new_menu(items);
    
    start_color();
    init_pair(1,COLOR_YELLOW,COLOR_BLUE);
    init_pair(2,COLOR_WHITE,COLOR_RED);
    set_menu_back(menu,COLOR_PAIR(1));
    set_menu_fore(menu,COLOR_PAIR(2));

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
		menu_driver(menu,REQ_UP_ITEM);
		break;
	    }
	    
	    case KEY_DOWN: {
		menu_driver(menu,REQ_DOWN_ITEM);
		break;
	    }
	    
	    case 10: { //нажатие на клавишу Enter
		move(LINES-1,0);clrtoeol();
		cur_item=item_userptr(current_item(menu));
		mvprintw(
		    LINES-1,
		    0,
		    "Selected menu item [%s] [%d]",
		    item_name(current_item(menu)),
		    *cur_item
		);
		break;
	    }
	    
	    case KEY_MOUSE: {
		menu_driver(menu,KEY_MOUSE);
		break;
	    }
	}
	wrefresh(stdscr);
    }
    
    //Деактивация библиотеки
    endwin();
    return 0;
}
