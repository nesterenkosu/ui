# include <gtk/gtk.h>

//Объявление переменных объектов
GtkWidget *ent_Name, *btn_Go, *lb_Result;

void on_btn_Go_clicked(){
    gchar *buf[255];
    //Формирование строки приветствия
    //типы данных и функции, начинающиеся с g_ являются переносимыми (кроссплатформенными)
    g_sprintf(
                buf,
                "Здравствуй, %s!",
                gtk_entry_get_text(GTK_ENTRY(ent_Name))
    );
    //Вывод приветствия
    gtk_label_set_text(GTK_LABEL(lb_Result),buf);
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
    GtkWidget *window;
    window=GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    gtk_widget_show(window); //Отображение окна
    
    //Получение доступа к объектам интерфейса, объявленным в Glade
    ent_Name = GTK_WIDGET(gtk_builder_get_object(builder,"ent_Name"));
    btn_Go = GTK_WIDGET(gtk_builder_get_object(builder,"btn_Go"));
    lb_Result = GTK_WIDGET(gtk_builder_get_object(builder,"lb_Result"));

    g_signal_connect_swapped(
	G_OBJECT(window),
	"destroy",
	G_CALLBACK(gtk_main_quit),
	NULL);
    
    //Связывание обработчиков, назначенных в Glade 
    //с одноимёнными функциями в C-коде
    gtk_builder_connect_signals(builder,NULL);

    gtk_main();//Запуск главного цикла обработки событий
    return 0;
}
