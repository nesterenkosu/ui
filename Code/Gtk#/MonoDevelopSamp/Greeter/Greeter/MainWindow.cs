using System;
using Gtk;

public partial class MainWindow : Gtk.Window
{
	public MainWindow () : base(Gtk.WindowType.Toplevel)
	{
		Build ();
	}

	protected void OnDeleteEvent (object sender, DeleteEventArgs a)
	{
		Application.Quit ();
		a.RetVal = true;
	}
	//Обработка события нажатия на кнопку "Ввод"
	protected virtual void OnButton1Clicked (object sender, System.EventArgs e)
	{
		lb_Result.Text="Здравствуй,"+ent_Name.Text+"!";
	}
	
	
}

