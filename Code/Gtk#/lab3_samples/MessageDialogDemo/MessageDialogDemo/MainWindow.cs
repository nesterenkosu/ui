using System;
using Gtk;

public partial class MainWindow : Gtk.Window
{
	string default_button1,default_button2,default_button3,default_button4;
	public MainWindow () : base(Gtk.WindowType.Toplevel)
	{
		Build ();
		
		default_button1 = button1.Label+"\n";
		default_button2 = button2.Label+"\n";
		default_button3 = button3.Label+"\n";
		default_button4 = button4.Label+"\n";
	}

	protected void OnDeleteEvent (object sender, DeleteEventArgs a)
	{
		Application.Quit ();
		a.RetVal = true;
	}
	protected virtual void OnButton1Clicked (object sender, System.EventArgs e)
	{
		MessageDialog md = new MessageDialog(this,DialogFlags.DestroyWithParent,MessageType.Info,ButtonsType.OkCancel,"Текст сообщения");
		ResponseType response = (ResponseType)md.Run();
		md.Destroy();
		
		string answer ="";
		if(response == ResponseType.Ok)
		{
			answer="Была нажата кнопка ОК";
		}
		else if(response == ResponseType.Cancel)
		{
			answer="Была нажата кнопка Cancel";
		}
		else if(response == ResponseType.DeleteEvent)
		{
			answer="Диалоговое окно было закрыто";
		}
		
		button1.Label = default_button1 + answer;
	}
	
	protected virtual void OnButton2Clicked (object sender, System.EventArgs e)
	{
		MessageDialog md = new MessageDialog(this,DialogFlags.DestroyWithParent,MessageType.Info,ButtonsType.OkCancel,"Текст сообщения");
		
		//Сделаем окно немодальным
		md.Modal = false;
		
		ResponseType response = (ResponseType)md.Run();
		md.Destroy();
		
		string answer="";
		if(response == ResponseType.Ok)
		{
			answer="Была нажата кнопка ОК";
		}
		else if(response == ResponseType.Cancel)
		{
			answer="Была нажата кнопка Cancel";
		}
		else if(response == ResponseType.DeleteEvent)
		{
			answer="Диалоговое окно было закрыто";
		}
		
		button2.Label = default_button2 + answer;
	}
	
	protected virtual void OnButton3Clicked (object sender, System.EventArgs e)
	{
		MessageDialog md = new MessageDialog(this,DialogFlags.DestroyWithParent,MessageType.Info,ButtonsType.OkCancel,"Текст сообщения");
		
		//Добавление заголовка
		md.Title = "Заголовок окна";
		
		//Добавление пользовательских команд
		md.AddButton("Пользовательская команда 1",ResponseType.Yes);
		md.AddButton("Пользовательская команда 2",ResponseType.No);
		
		ResponseType response = (ResponseType)md.Run();
		md.Destroy();
		
		string answer="";
		if(response == ResponseType.Ok)
		{
			answer="Была нажата кнопка ОК";
		}
		else if(response == ResponseType.Cancel)
		{
			answer="Была нажата кнопка Cancel";
		}
		else if(response == ResponseType.Yes)
		{
			answer="Была нажата кнопка \"Пользовательская команда 1\"";
		}
		else if(response == ResponseType.No)
		{
			answer="Была нажата кнопка \"Пользовательская команда 2\"";
		}
		else if(response == ResponseType.DeleteEvent)
		{
			answer="Диалоговое окно было закрыто";
		}
		
		button3.Label = default_button3 + answer;
	}
	
	protected virtual void OnButton4Clicked (object sender, System.EventArgs e)
	{
		MessageDialog md = new MessageDialog(this,DialogFlags.DestroyWithParent,MessageType.Warning,ButtonsType.None,"Текст сообщения");
		
		//Добавление заголовка
		md.Title = "Заголовок окна";
		
		//Добавление пользовательских команд
		md.AddButton("Да",ResponseType.Yes);
		md.AddButton("Нет",ResponseType.No);
		md.AddButton("Отмена",ResponseType.Cancel);
		
		ResponseType response = (ResponseType)md.Run();
		md.Destroy();
		
		string answer="";
		if(response == ResponseType.Cancel)
		{
			answer="Была нажата кнопка \"Отмена\"";
		}
		else if(response == ResponseType.Yes)
		{
			answer="Была нажата кнопка \"Да\"";
		}
		else if(response == ResponseType.No)
		{
			answer="Была нажата кнопка \"Нет\"";
		}
		else if(response == ResponseType.DeleteEvent)
		{
			answer="Диалоговое окно было закрыто";
		}
		
		button4.Label = default_button4 + answer;
	}
	
	
	
	
	
}

