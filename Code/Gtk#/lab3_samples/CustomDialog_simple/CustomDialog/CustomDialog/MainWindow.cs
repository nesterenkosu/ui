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
	protected virtual void OnButton1Clicked (object sender, System.EventArgs e)
	{
		//Создание
		CustomDialog.MyDialog dlg = new CustomDialog.MyDialog();		
		
		//Вывод диалогового окна и получение
		//ответа пользователя.
		ResponseType resp = (ResponseType)dlg.Run();
		
		if(resp==ResponseType.Ok) //Если пользователь нажал "ОК"
		{						
			Console.WriteLine("Данные, полученные из диалогового окна:"+dlg.myproperty);
		}
		
		//Завершение диалога
		dlg.Destroy();
	}
	
	
}

