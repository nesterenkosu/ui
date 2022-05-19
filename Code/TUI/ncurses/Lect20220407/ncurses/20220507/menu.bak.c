#include <ncurses.h>
//#include <menu.h>
//#include <form.h>
//#inclide <panel.h>

WINDOW *new_centered_window(int height, int width, int color_pair);

int main() {
    //Инициализация nCurses
    initscr();

    noecho();//не выводить на экран нажатые клавиши

    cbreak();//режим, при котором ввод не буферизуется

    keypad(stdscr,TRUE);//включение поддержки функциональных клавиш (стрелки, F1-F12)

    start_color();//включение цветного режима
    //-----------------
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    
    WINDOW *w = new_centered_window(5,15,1);
    
    //Цикл обработки событий
    /*int ch;
    for(;;){
	ch=getch();
	break;
	switch(ch) {
	}
    }*/
    //-----------------

    //Деактивация nCurses
    endwin();
    return 0;
}

WINDOW *new_centered_window(int height, int width, int color_pair) {
    int starty = (LINES - height) / 2;  /* Calculating for a center placement */
    int startx = (COLS - width) / 2; 
    
    WINDOW *w,*dw;
    w = newwin(height,width,starty,startx);
    dw = derwin(w,height-2,width-2,starty+1,startx+1);

    wattron(w,COLOR_PAIR(color_pair));
    wborder(w,0,0,0,0,0,0,0,0);
    wrefresh(w);

    wbkgd(dw,COLOR_PAIR(color_pair));
    wattron(dw,COLOR_PAIR(color_pair));
    wclear(dw);
    wrefresh(dw);
    wprintw(dw,"Hi");
    wgetch(dw);
    return dw;
}

