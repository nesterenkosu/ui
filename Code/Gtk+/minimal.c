# include <gtk/gtk.h>

GtkWidget *win;

int main(int argc, char *argv[]) {
    //Инициализация библиотеки Gtk+
    gtk_init(&argc,&argv);
    
    //Создание экземпляра окна
    win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    
    //Отображение окна
    gtk_widget_show(win);
    
    //Обработка события закрытия окна - завершение программы
    g_signal_connect_swapped(
	win, //Объект, для которого обрабатываем событие
	"destroy",//Событие, которое нужно обработать
	G_CALLBACK(gtk_main_quit),//Обработчик события
	NULL //Аргументы обработчика события
    );
    
    //Запуск главного цикла обработки событий
    gtk_main();
    
    return 0;
}
