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

void destroy_win(WINDOW *local_win)
{       
        /* box(local_win, ' ', ' '); : This won't produce the desired
         * result of erasing the window. It will leave its four corners 
         * and so an ugly remnant of window. 
         */
        wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
        /* The parameters taken are 
         * 1. win: the window on which to operate
         * 2. ls: character to be used for the left side of the window 
         * 3. rs: character to be used for the right side of the window 
         * 4. ts: character to be used for the top side of the window 
         * 5. bs: character to be used for the bottom side of the window 
         * 6. tl: character to be used for the top left corner of the window 
         * 7. tr: character to be used for the top right corner of the window 
         * 8. bl: character to be used for the bottom left corner of the window 
         * 9. br: character to be used for the bottom right corner of the window
         */
        wrefresh(local_win);
        delwin(local_win);
}
