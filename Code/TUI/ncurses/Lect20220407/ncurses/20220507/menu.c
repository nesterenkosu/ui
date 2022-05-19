#include <ncurses.h>
//#include <menu.h>
//#include <form.h>
//#inclide <panel.h>

WINDOW *new_centered_window(int height, int width, int color_pair, char *title);
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);

int main() {
    //Инициализация nCurses
    initscr();

    noecho();//не выводить на экран нажатые клавиши

    cbreak();//режим, при котором ввод не буферизуется

    keypad(stdscr,TRUE);//включение поддержки функциональных клавиш (стрелки, F1-F12)

    start_color();//включение цветного режима
    
    //-----------------

    WINDOW *w = new_centered_window(20,70,1," My Pretty Window ");
    
    wprintw(w,"Hello");
    wgetch(w);
    //-----------------

    //Деактивация nCurses
    endwin();
    return 0;
}

WINDOW *new_centered_window(int height, int width, int color_pair, char *title) {
    int starty = (LINES - height) / 2;  /* Calculating for a center placement */
    int startx = (COLS - width) / 2; 
    
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_RED,COLOR_WHITE);
    
    WINDOW *w = newwin(height,width,starty,startx);
    WINDOW *dw = derwin(w,height-2,width-2,1,1);

    //WINDOW *w = newwin(20,15,1,1);
    //WINDOW *dw = derwin(w,18,13,1,1);


    wattron(w,COLOR_PAIR(1));

    //box(w,'|','-');
    wborder(w,'|','|','-','-','+','+','+','+');
    if(title!=NULL) {
	wattron(w,COLOR_PAIR(2));
	print_in_middle(w,0,0,width,title);
	wattroff(w,COLOR_PAIR(2));
    }
    
    
    wrefresh(w);

    //Цвет фона окна
    wbkgd(dw,COLOR_PAIR(1));
    //Цвет текста и фона под текстом
    wattron(dw,COLOR_PAIR(1));
    wclear(dw);
    wrefresh(dw);
    //wprintw(dw,"%d %d",starty,startx);
    //wgetch(dw);
    /*WINDOW *w,*dw;
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
    wgetch(dw);*/
    return dw;
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{       int length, x, y;
        float temp;

        if(win == NULL)
                win = stdscr;
        getyx(win, y, x);
        if(startx != 0)
                x = startx;
        if(starty != 0)
                y = starty;
        if(width == 0)
                width = 80;

        length = strlen(string);
        temp = (width - length)/ 2;
        x = startx + (int)temp;
        mvwprintw(win, y, x, "%s", string);
        refresh();
}