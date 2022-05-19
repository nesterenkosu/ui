#include <ncurses.h>
#include <menu.h>
#include "ncurses_helper.h"

char *choices[] = {
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
                        "Exit",
                        (char *)NULL,
                  };



int main() {
    //Инициализация nCurses
    initscr();

    noecho();//не выводить на экран нажатые клавиши

    cbreak();//режим, при котором ввод не буферизуется

    keypad(stdscr,TRUE);//включение поддержки функциональных клавиш (стрелки, F1-F12)

    start_color();//включение цветного режима
    
    //-----------------
    MENU *menu;
    ITEM *items[4];

    //Создание элементов меню
    items[0]=new_item("One","");
    items[1]=new_item("Two","");
    items[2]=new_item("Three","");
    items[3]=(ITEM *)NULL;

    menu=new_menu(items);

    
    

    WINDOW *w = new_centered_window(20,70,1," My Pretty Window ");
    
    set_menu_win(menu,w);
    post_menu(menu);
    //wprintw(w,"Hello");
    wgetch(w);
    
    //destroy_win(w);
    getch();
    //-----------------

    //Деактивация nCurses
    endwin();
    return 0;
}
