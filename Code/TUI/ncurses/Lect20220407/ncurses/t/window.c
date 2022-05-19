#include <ncurses.h>

int main() {
    initscr();
    keypad(stdscr,TRUE);
    start_color();
    
    WINDOW *w = newwin(20,15,1,1);
    WINDOW *dw = derwin(w,18,13,1,1);
    
    init_pair(1,COLOR_WHITE,COLOR_RED);
    init_pair(2,COLOR_YELLOW,COLOR_BLUE);
    
    wattron(w,COLOR_PAIR(1));
    
    //box(w,'|','-');
    wborder(w,'|','|','-','-','+','+','+','+');
    wrefresh(w);
    
    //Цвет фона окна
    wbkgd(dw,COLOR_PAIR(1));
    //Цвет текста и фона под текстом
    wattron(dw,COLOR_PAIR(2));
    wclear(dw);
    wrefresh(dw);
    wprintw(dw,"Hi");
    wgetch(dw);
    endwin();
    return 0;
}
