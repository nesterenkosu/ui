# include <gtk/gtk.h>

GtkWidget *win, *btn;

//Обработчик события нажатия на кнопке
void btn_click() {
    //Вывод текста на кнопке
    gtk_button_set_label(GTK_BUTTON(btn),"Hello, world!");
}

int main(int argc, char *argv[]) {
    //Инициализация библиотеки Gtk+
    gtk_init(&argc,&argv);
    
    //Создание экземпляра окна
    win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    
    //Создание экземпляра кнопки
    btn=gtk_button_new_with_label("Click here");
    
    //Добавление кнопки в окно
    gtk_container_add(GTK_CONTAINER(win),btn);
    
    //Отображение окна
    gtk_widget_show_all(win);
    
    //Обработка события нажатия на кнопку
    g_signal_connect(
	btn,
	"clicked",
	G_CALLBACK(btn_click),
	NULL
    );
    
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
