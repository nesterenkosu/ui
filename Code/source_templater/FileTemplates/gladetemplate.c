# include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    gtk_init(&argc,&argv);
    
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
    gtk_widget_show(window);
    
    
    g_signal_connect_swapped(
	G_OBJECT(window),
	"destroy",
	G_CALLBACK(gtk_main_quit),
	NULL);
    
    gtk_main();
    return 0;
}