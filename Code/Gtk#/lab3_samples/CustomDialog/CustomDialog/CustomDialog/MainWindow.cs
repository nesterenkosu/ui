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
		dlg.Title = "Новые данные"; //Заголовок окна
		dlg.Modal = true; //Окно будет модальным
		//Вывод диалогового окна и получение
		//ответа пользователя.
		ResponseType resp = (ResponseType)dlg.Run();
		//Закрытие диалогового окна
		dlg.Destroy();
		if(resp==ResponseType.Ok) //Если пользователь нажал "ОК"
		{
			MessageDialog md = new MessageDialog(this,DialogFlags.DestroyWithParent,MessageType.Warning,ButtonsType.Close,dlg.myproperty);
			md.Title="Данные, полученные из диалогового окна";
			md.Run();
			md.Destroy();
		}
		
		//Редактирование
		CustomDialog.MyDialog dlg2 = new CustomDialog.MyDialog("Эти данные нужно отредактировать");
		dlg2.Title = "Редактирование";
		dlg2.Modal = true;
		resp = (ResponseType)dlg2.Run();
		dlg2.Destroy();
		if(resp==ResponseType.Ok)
		{
			MessageDialog md = new MessageDialog(this,DialogFlags.DestroyWithParent,MessageType.Warning,ButtonsType.Close,dlg2.myproperty);
			md.Title="Данные, полученные из диалогового окна";
			md.Run();
			md.Destroy();
		}
		
	}
	
	
}

