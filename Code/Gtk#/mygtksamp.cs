using System;
using Gtk;

public class MyGtkSharpSample
{
    //Объявление переменных всех необходимых виджетов
    static Label lb_Result;
    static Entry ent_Name;
    
    public static void Main()
    {
	//Инициализация библиотеки Gtk#
	Application.Init();
	
	//Создание экземпляра окна
	Window mywin=new Window("Hello from Gtk#");
	
	//Создание экземпляра компоновочного виджета (контейнера)
	VBox vbox = new VBox();
	
	//Создание экземпляра текстовой метки
	Label label = new Label("Введите ваше имя:");
	vbox.Add(label);//помещение его в контейнер
	
	//Создание экземпляра текстового поля ввода
	ent_Name = new Entry();
	vbox.Add(ent_Name);//помещение его в контейнер
	
	//Создание экземпляра кнопки
	Button btn = new Button("Ввод");
	vbox.Add(btn);//помещение его в контейнер
	
	//Создание экземпляра текстового поля для вывода приветствия
	lb_Result = new Label("");
	vbox.Add(lb_Result);//помещение его в контейнер
	
	//Обработка события нажатия на кнопку
	btn.Clicked += OnBtnClick;
	
	//Помещение компоновочного виджета в окно
	mywin.Add(vbox);
	
	//Отображение окна
	mywin.ShowAll();
	//Чтобы при закрытии окна приложение корректно завершилось
	//обработаем событие Window.DeleteEvent
	mywin.DeleteEvent += delegate {Application.Quit();};
	//Запуск главного цикла обработки событий
	Application.Run();
    }
    
    //Обработчик события нажатия на кнопку
    static void OnBtnClick(object sender, EventArgs e) {
	lb_Result.Text="Здравствуй,"+ent_Name.Text+"!";
    }
}
