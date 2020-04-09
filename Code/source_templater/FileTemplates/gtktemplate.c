# include <gtk/gtk.h>

GtkWidget *window;

int main(int argc, char *argv[])
{
    gtk_init(&argc,&argv);
    
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_show_all(window);
    
    g_signal_connect_swapped(
	G_OBJECT(window),
	"destroy",
	G_CALLBACK(gtk_main_quit),
	NULL);
    
    gtk_main();
    return 0;
}