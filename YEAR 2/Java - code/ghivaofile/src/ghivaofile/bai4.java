package ghivaofile;
import java.util.*;
import java.io.*;


class nv{
	private String id,name,luong;

	public nv() {
	}

	public nv(String id, String name, String luong) {
	
		this.id = id;
		this.name = name;
		this.luong = luong;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getLuong() {
		return luong;
	}

	public void setLuong(String luong) {
		this.luong = luong;
	}
	public void nhap() {
		Scanner q = new Scanner(System.in);
		System.out.println("Enter id: ");
		id =q.nextLine();
		System.out.println("Enter salary: ");
		luong =q.nextLine();
		System.out.println("Enter name: ");
		name =q.nextLine();
	}
	public void input() throws IOException{
		File a = new File("D:\\bai3.txt");
		FileWriter b= new FileWriter(a);
		try {
			
			for(int i=0;i<3;i++) {
				System.out.println("Nhập nv thứ "+(i+1)+" là: ");
				nhap();
				b.write("Nhan vien thu "+(i+1)+" la: "+this.id+", "+this.luong+", "+this.name+"\n");
			}
		}catch(FileNotFoundException e) {
			e.printStackTrace();
			b.close();
		}b.close();
	}
	
	public void output() throws IOException{
		File a = new File("D:\\bai3.txt");
		FileReader b= new FileReader(a);
		BufferedReader c = new BufferedReader(b);
		String d;
		try {
			while((d=c.readLine())!=null) {
				System.out.println(d);
			}
		}catch(FileNotFoundException e) {
			e.printStackTrace();
			c.close();
		}c.close();
		
	}
	
}
public class bai4 {

	public static void main(String[] args) throws IOException {
nv a = new nv();
a.input();
a.output();
	}

}
