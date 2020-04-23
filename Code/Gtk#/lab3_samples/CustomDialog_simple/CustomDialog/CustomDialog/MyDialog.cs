using System;
using Gtk;
namespace CustomDialog
{
	public partial class MyDialog : Gtk.Dialog
	{
		private string mypropertydata="";
		public string myproperty
		{
			//Read-only-свойство для получения
			//значения, введённого в поле.
			get{return	mypropertydata;}			
		}		
		
		public MyDialog ()
		{
			//Конструктор без параметров - если нужно ввести
			//новые данные
			this.Build ();			
		}
		
		protected virtual void OnEntry1FocusOutEvent (object o, 
		                              Gtk.FocusOutEventArgs args)
		{
			//При потере фокуса присваиваем введёное значение
			//закрытой переменной mypropertydata.
			mypropertydata=entry1.Text;
		}
	}
}

