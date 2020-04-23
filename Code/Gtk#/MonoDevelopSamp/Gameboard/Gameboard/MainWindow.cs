using System;
using Gtk;

public partial class MainWindow : Gtk.Window
{
	//Флаг, определяющий, создаётся ли поле в первый раз
	public bool is_first = true;
	
	//Объект "таблица", необходимый для создания игрового поля.
	//Объявляется глобально, так как должен быть доступен из
	//разных методов.
	public Table t;
	
	public MainWindow () : base(Gtk.WindowType.Toplevel)
	{
		Build ();
	}

	protected void OnDeleteEvent (object sender, DeleteEventArgs a)
	{
		Application.Quit ();
		a.RetVal = true;
	}
	
	//Обработчик нажатия на кнопку "Создать"
	protected virtual void OnButton1Clicked (object sender, System.EventArgs e)
	{
		//Если создаём игровое поле не в первый раз
		if(!is_first) 
			t.Destroy();//Удаляем игровое поле, созданное ранее
		
		//Получение размеров игрового поля из полей формы
		//и преобразование их в число
		uint h = Convert.ToUInt32(ent_H.Text);
		uint w = Convert.ToUInt32(ent_W.Text);
		
		//Создание игрового поля:
		//Создание компоновочного виджета "Таблица"
		t = new Table(h,w,true);
		
		for(uint i=0;i<h;i++)
			for(uint j=0;j<w;j++) {
			//Создание кнопки - клетки поля
			Button btn = new Button("");
			//размещение кнопки в ячейке виджета "Таблица"
			t.Attach(btn,j,j+1,i,i+1);
			//Всем кнопкам - клеткам поля назначим один обработчик
			//события "clicked"
			btn.Clicked+=gameboard_clicked;
		}
		
		//Добавление созданного игрового поля
		//в вертикальный компоновочный виджет
		vbox1.Add(t);
		
		//Перерисовка окна
		vbox1.ShowAll();
		//Сброс флага "создания поля в первый раз"
		is_first=false;
	}
	
	//Обработчик нажатия в клетке игрового поля
	protected void gameboard_clicked(object sender, EventArgs e) {
		((Button)sender).Label="*";
	}
}

