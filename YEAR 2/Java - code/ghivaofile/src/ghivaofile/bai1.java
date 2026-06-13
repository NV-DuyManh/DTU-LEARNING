package ghivaofile;

import java.util.*;

import java.io.*;

class nhanvien{
	String id;
	String salary;
	String name;
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getSalary() {
		return salary;
	}
	public void setSalary(String salary) {
		this.salary = salary;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public nhanvien(String id, String salary, String name) {
	
		this.id = id;
		this.salary = salary;
		this.name = name;
	}
	public nhanvien() {
		
	}
	void input() throws IOException{
		File a = new File("D:\\cmutpm2.txt");
		FileWriter b = new FileWriter(a);
		try {
			Scanner q = new Scanner(System.in);
			for(int i=0;i<10;i++) {
				System.out.println("Nhập nv thứ "+(i+1)+" là: ");
				System.out.println("Enter id: ");
				id =q.nextLine();
				System.out.println("Enter salary: ");
				salary =q.nextLine();
				System.out.println("Enter name: ");
				name =q.nextLine();
				b.write("Nhan vien thu "+(i+1)+" la: "+this.id+", "+this.salary+", "+this.name+"\n");
			}
		}catch(FileNotFoundException e) {
			e.printStackTrace();
			b.close();
		}b.close();
	}
	void output() throws IOException{
		File a = new File("D:\\cmutpm2.txt");
		FileReader b = new FileReader(a);
		BufferedReader c= new BufferedReader(b);
		String d=null;
		try {
			while((d=c.readLine()) != null) {
				System.out.println(d);
			}
		}catch(FileNotFoundException e ) {
			e.printStackTrace();
			c.close();
		}c.close();
	}
}

public class bai1 {

	public static void main(String[] args) throws IOException {
		
		nhanvien nv = new nhanvien();
		nv.input();
		nv.output();
}
}