# include <gtk/gtk.h>

//Объявление переменных всех необходимых виджетов
GtkWidget *win, //Окно приложения
	*vbox,  //Горизонтальный компоновочный виджет
	*label, //Текстовая метка
	*entry, //Поле ввода текста
	*btn, //Кнопка
	*lb_result; //Текстовая метка для вывода приветствия

//Обработчик события нажатия на кнопке
void btn_click() {
    //Получить значение, введённое в текствое поле, и сформировать приветствие
    gchar buf[255];    
    g_sprintf(buf,"Здравствуйте, %s!",gtk_entry_get_text(GTK_ENTRY(entry)));
    //Вывод приветствия в текстовой метке
    gtk_label_set_text(GTK_LABEL(lb_result),buf);
}

int main(int argc, char *argv[]) {
    //Инициализация библиотеки Gtk+
    gtk_init(&argc,&argv);
    
    //Создание экземпляра окна
    win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    
    //Создание экземпляра компоновочного виджета
    vbox=gtk_vbox_new(TRUE,1);
    
    //Создание экземпляра текстовой метки
    label=gtk_label_new("Введите ваше имя");
    
    //Создание экземпляра текстового поля ввода
    entry=gtk_entry_new();
    
    //Создание экземпляра кнопки
    btn=gtk_button_new_with_label("Click here");
    
    //Создание экземпляра текстового поля для вывода приветствия
    lb_result=gtk_label_new("");
    
    //Помещение элементов управления в контейнер (вертикальный компоновочный виджет)
    gtk_container_add(GTK_CONTAINER(vbox),label);
    gtk_container_add(GTK_CONTAINER(vbox),entry);
    gtk_container_add(GTK_CONTAINER(vbox),btn);
    gtk_container_add(GTK_CONTAINER(vbox),lb_result);    

    //Помещение компоновочного виджета в окно
    gtk_container_add(GTK_CONTAINER(win),vbox);
    
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
