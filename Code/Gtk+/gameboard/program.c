# include <gtk/gtk.h>
# include <stdio.h>

//Объявление переменных объектов интерфейса
GtkWidget *window;
GtkWidget *ent_h,*ent_w,*vbox,*board;

//Обработчик нажатия в клетке игрового поля
void on_field_click(GtkWidget *sender) {
    gtk_button_set_label(GTK_BUTTON(sender),"*");
}


gboolean is_first=TRUE; //Флаг, определяющий, создаётся ли поле в первый раз
void on_btn_Go_clicked() { //Обработчик нажатия на кнопку "Ввод"
    int h,w;

    //Если создаём игровое поле не в первый раз
    if(is_first==FALSE) {
	//Удаляем игровое поле, созданное ранее
        gtk_widget_destroy(GTK_WIDGET(board));
    }

    /*h=g_ascii_digit_value(
                gtk_entry_get_text(GTK_ENTRY(ent_h))
    );*/
    
    //Получение размеров игрового поля из полей формы
    //и преобразование их в число
    h=atoi(gtk_entry_get_text(GTK_ENTRY(ent_h)));
    w=atoi(gtk_entry_get_text(GTK_ENTRY(ent_w)));

    //Создание игрового поля
    int i,j;
    GtkWidget *btn;
    board=gtk_table_new(h,w,TRUE);//Создание компоновочного виджета "Таблица"
    for(i=0;i<w;i++)
        for(j=0;j<h;j++) {
    	    //Создание кнопки - клетки поля
            btn=gtk_button_new_with_label("");
            //размещение кнопки в ячейке виджета "Таблица"
            gtk_table_attach_defaults(
                        GTK_TABLE(board),
                        btn,
                        j,j+1,i,i+1
            );
	    //Всем кнопкам - клеткам поля назначим один обработчик
	    //события "clicked"
            g_signal_connect(
                        G_OBJECT(btn),
                        "clicked",
                        G_CALLBACK(on_field_click),
                        NULL
            );
    }

    //Добавление созданного игрового поля
    //в вертикальный компоновочный виджет
    gtk_container_add(GTK_CONTAINER(vbox),board);
    //Перерисовка окна
    gtk_widget_show_all(GTK_WIDGET(window));

    is_first=FALSE;//Сброс флага "создания поля в первый раз"
}

int main(int argc, char *argv[])
{
    gtk_init(&argc,&argv);//Инициализация библиотеки Gtk+
    
    //Подгрузка интерфейса пользователя из Glade-Файла
    GtkBuilder *builder=gtk_builder_new();
    GError *error=NULL;
    if(!gtk_builder_add_from_file(builder,"gui.glade",&error)) {
	//Если при загрузке интерфейса произошла ошибка
	//выведем её описание и завершим программу
	g_warning("%s",error->message);
	return 1;
    }
    
    //Получение доступа к объекту окна, объявленному в Glade-файле
    window=GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    gtk_widget_show(window);
    
    //Получения доступа к объектам интерфейса, объявленным в Glade
    ent_h=GTK_WIDGET(gtk_builder_get_object(builder,"ent_h"));
    ent_w=GTK_WIDGET(gtk_builder_get_object(builder,"ent_w"));
    vbox=GTK_WIDGET(gtk_builder_get_object(builder,"vbox"));

    //Связывание обработчиков событий, назначенных в Glade
    //с функциями в C-коде
    gtk_builder_connect_signals(builder,NULL);

    //Завершение процесса при закрытии окна
    g_signal_connect_swapped(
	G_OBJECT(window),
	"destroy",
	G_CALLBACK(gtk_main_quit),
	NULL);
    
    gtk_main();//Запуск главного цикла обработки событий
    return 0;
}
