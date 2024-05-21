#include <ncurses.h>
#include <menu.h>

#define MAIN_WINDOW_HEIGHT 16
#define MAIN_WINDOW_WIDTH 40

MENU *Active_menu, *Main_menu, *Toolbar, *Itemlist;
WINDOW *Active_window, *Main_window, *Toolbar_window, *Itemlist_window;

void draw_main_window();
void draw_toolbar();
void draw_itemlist();

int main() {
    //Инициализация nCurses
    initscr();

    noecho();//не выводить на экран нажатые клавиши

    cbreak();//режим, при котором ввод не буферизуется

    keypad(stdscr,TRUE);//включение поддержки функциональных клавиш (стрелки, F1-F12)

    start_color();//включение цветного режима
    //-----------------

    //mvprintw(1,1,"LINES=[%d] COLS=[%d]",LINES,COLS);

    draw_main_window();
    
    Active_window = Main_window;
    Active_menu = Toolbar;
    //Цикл обработки событий
    int c;
    while((c=wgetch(Active_window))!=KEY_F(1)){
	//printf("[%d] [%d]\n",KEY_UP,c);
	switch(c){
	    case KEY_LEFT:
		menu_driver(Active_menu,REQ_LEFT_ITEM);
		break;
	    case KEY_RIGHT:
		menu_driver(Active_menu,REQ_RIGHT_ITEM);
		break;
	    case KEY_UP:
		menu_driver(Active_menu,REQ_UP_ITEM);
		break;
	    case KEY_DOWN:
		menu_driver(Active_menu,REQ_DOWN_ITEM);
		break;
	    case 116: //клавиша t (toolbar)
		Active_window=Main_window;
		Active_menu=Toolbar;
		break;
	    case 105: //клавиша i (items)
		//printf("Items!");
		Active_window=Itemlist_window;
		Active_menu=Itemlist;
		break;
	    case 10:
		printf("Enter!\n");
		exit(0);
	}
	wrefresh(Active_window);
    }
    /*int ch;
    for(;;){
	ch=wgetch();
	switch(ch) {
	}
    }*/
    //-----------------

    //Деактивация nCurses
    endwin();
    return 0;
}

WINDOW *draw_bordered_window(int height, int width, int startx, int starty, int color_pair){
    //Внешнее окно, содержащее рамку
    WINDOW *window_border = newwin(
	height,
	width,
	startx,
	starty
    );

    //Внутреннее окно с полезным содержимым
    WINDOW *window_main = derwin(
	window_border,
	height-2,
	width-2,
	1,
	1
    );
    
    init_pair(1,COLOR_WHITE,COLOR_CYAN);

    //Рисование рамки
    wattron(window_border,COLOR_PAIR(1));
    wborder(window_border,'|','|','-','-','+','+','+','+');
    wrefresh(window_border);

    //Заливка основного окна
    wattron(window_main,COLOR_PAIR(1));
    wbkgd(window_main,COLOR_PAIR(1));
    wclear(window_main);
    wrefresh(window_main);

    //wgetch(window_main);

    return window_main;
}

void draw_main_window() {

    int startx, starty;

    startx = (LINES - MAIN_WINDOW_HEIGHT)/2;
    starty = (COLS - MAIN_WINDOW_WIDTH)/2;

    //init_pair(1,COLOR_WHITE,COLOR_RED);    

    Main_window = draw_bordered_window(
	MAIN_WINDOW_HEIGHT,
	MAIN_WINDOW_WIDTH,
	startx,
	starty,
	1
    );
    //wgetch(main_window);
    draw_toolbar();
    draw_itemlist();
}

void draw_toolbar() {
    keypad(Main_window,TRUE);

    
    ITEM *items[4];

    items[0]=new_item("Add","");
    items[1]=new_item("Edit","");
    items[2]=new_item("Delete","");
    items[3]=(ITEM*)NULL;

    Toolbar=new_menu(items);


    set_menu_win(Toolbar,Main_window);

    init_pair(11,COLOR_BLACK,COLOR_WHITE);
    init_pair(12,COLOR_WHITE,COLOR_CYAN);

    set_menu_fore(Toolbar,COLOR_PAIR(11));
    set_menu_back(Toolbar,COLOR_PAIR(12));

    set_menu_format(Toolbar,1,3);

    post_menu(Toolbar);

    wrefresh(Main_window);
    
}

void draw_itemlist() {
    Itemlist_window = derwin(
	Main_window,
	MAIN_WINDOW_HEIGHT-5, MAIN_WINDOW_WIDTH-2,3,0);

    //Заливка основного окна
    /*init_pair(3,COLOR_WHITE,COLOR_RED);
    wattron(Itemlist_window,COLOR_PAIR(3));
    wbkgd(Itemlist_window,COLOR_PAIR(3));
    wclear(Itemlist_window);
    wrefresh(Itemlist_window);*/

    keypad(Itemlist_window,TRUE);

    ITEM *items[4];

    items[0]=new_item("1 One           ++","");
    items[1]=new_item("2 Two           -+","");
    items[2]=new_item("3 Three         +-","");
    items[3]=(ITEM *)NULL;

    Itemlist=new_menu(items);

    set_menu_win(Itemlist,Itemlist_window);

    init_pair(11,COLOR_BLACK,COLOR_WHITE);
    init_pair(12,COLOR_WHITE,COLOR_CYAN);

    set_menu_fore(Itemlist,COLOR_PAIR(11));
    set_menu_back(Itemlist,COLOR_PAIR(12));


    post_menu(Itemlist);

    wrefresh(Itemlist_window);

    
}
