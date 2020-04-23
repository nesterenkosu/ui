using System;
using Gtk;

public partial class MainWindow : Gtk.Window
{
	public ListStore liststore;
	public bool editing = false;
	public TreeIter active_tree_iter;
	
	public MainWindow () : base(Gtk.WindowType.Toplevel)
	{
		Build ();
		treeview1.AppendColumn("Поле 1", new CellRendererText(),"text",0); 
		treeview1.AppendColumn("Поле 2", new CellRendererText(),"text",1);
		liststore = new ListStore(typeof (string),typeof (string));
		treeview1.Model = liststore;		
	}

	protected void OnDeleteEvent (object sender, DeleteEventArgs a)
	{
		Application.Quit ();
		a.RetVal = true;
	}
	protected virtual void OnButton2Clicked (object sender, System.EventArgs e)
	{
		if(entry1.Text.Trim()=="" || entry2.Text.Trim()=="") return;
		
		if(!editing)
			liststore.AppendValues(entry1.Text,entry2.Text);
		else
		{	
			
			
			liststore.SetValues(active_tree_iter,entry1.Text,entry2.Text);
			
			entry1.Text ="";
			entry2.Text ="";
			editing = false;
		}
	}
	
	protected virtual void OnButton3Clicked (object sender, System.EventArgs e)
	{
		//Удаление выделенного элемента
		TreeIter iter;
		//TreePath p = new TreePath();
		//p.AppendIndex(1);
		//liststore.GetIter(out iter,p);
		//Метод GetSelected получает объект TreeIter, представляющий
		//выбранный в TreeView элемент. Возвращает false, если
		//например ничего не выбрано.
		if(treeview1.Selection.GetSelected(out iter))		
			liststore.Remove(ref iter);		
	}
	
	protected virtual void OnTreeview1RowActivated (object o, Gtk.RowActivatedArgs args)
	{
		editing = true;
		
		MessageDialog dlg = new MessageDialog(this,DialogFlags.DestroyWithParent,MessageType.Info,ButtonsType.Ok,"!");
		dlg.Run();
		dlg.Destroy();
		
		liststore.GetIter(out active_tree_iter,args.Path);
		entry1.Text = liststore.GetValue(active_tree_iter,0).ToString();
		entry2.Text = liststore.GetValue(active_tree_iter,1).ToString();
	}
	
	protected virtual void OnTreeview1CursorChanged (object sender, System.EventArgs e)
	{
		//editing = false;
	}
	
	protected virtual void OnTreeview1MoveCursor (object o, Gtk.MoveCursorArgs args)
	{
		//args.
	}
	
	protected virtual void OnButton4Clicked (object sender, System.EventArgs e)
	{
		liststore.Clear();
	}
	
	
	
	
	
	
	
}

