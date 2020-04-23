using System;
using System.IO;

namespace Lab3
{
	public class FileHandler
	{
		public string id, Text, Flags;
		private FileStream fs;
		private int id_len,Text_len,Flags_len,total_len; 
		
		public void Open(string filepath)
		{
			fs = new FileStream(filepath,FileMode.Open);
		}
		
		public void OpenClear(string filepath)
		{
			fs = new FileStream(filepath,FileMode.Create);
		}
		
		public void Readrec(int rec_n)
		{
			if(rec_n > CountRec()-1) return;
			
			fs.Seek(total_len*rec_n,SeekOrigin.Begin);			
			byte[] bytes = new byte[id_len+Text_len+Flags_len+1];
			fs.Read(bytes,0,id_len+Text_len+Flags_len+1);
			id=System.Text.Encoding.UTF8.GetString(bytes,0,id_len);
			Text=System.Text.Encoding.UTF8.GetString(bytes,id_len,Text_len);
			Flags=System.Text.Encoding.UTF8.GetString(bytes,id_len+Text_len,Flags_len);
		}
		
		public void Writerec(int rec_n,string id, string Text, string Flags)
		{
			this.id = id;
			this.Text = Text;
			this.Flags = Flags;
			Writerec(rec_n);
		}
		
		public void Writerec(int rec_n)
		{
			id=id.PadRight(id_len);
			Text=Text.PadRight(Text_len);
			Flags=Flags.PadRight(Flags_len)+"\n";			
			
			fs.Seek(total_len*rec_n,SeekOrigin.Begin);
			byte[] bytes = System.Text.Encoding.UTF8.GetBytes(id.ToCharArray(),0,id_len);
		    fs.Write(bytes,0,id_len);
			
			bytes = System.Text.Encoding.UTF8.GetBytes(Text.ToCharArray(),0,Text_len);
		    fs.Write(bytes,0,Text_len);
			
			bytes = System.Text.Encoding.UTF8.GetBytes(Flags.ToCharArray(),0,Flags_len+1);
		    fs.Write(bytes,0,Flags_len+1);
		}
		
		public long CountRec()
		{
			return fs.Seek(0,SeekOrigin.End)/total_len;
		}
		
		public void Close()
		{
			fs.Close();
		}
		
		public FileHandler ()
		{
			id_len = 3;
			Text_len = 12;
			Flags_len = 2;
			total_len = id_len + Text_len + Flags_len + 1;
		}
	}
}

