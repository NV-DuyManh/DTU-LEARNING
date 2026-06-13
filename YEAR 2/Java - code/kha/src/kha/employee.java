package kha;
import java.util.*;
import java.io.*;
class emp {
	private String id;
	private String name;
	private int salary;
	emp(){}
	public emp(String id, String name, int salary) {
		this.id = id;
		this.name = name;
		this.salary = salary;
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
	public int getSalary() {
		return salary;
	}
	public void setSalary(int salary) {
		this.salary = salary;
	}
	void input() throws IOException {
		File file = new File("C:\\nhap\\nhap.txt");
		FileWriter fw = new FileWriter(file);
		emp [] a = new emp[3];
		try {
			for(int i=0;i<a.length;i++) {
				Scanner o = new Scanner(System.in);
				System.out.println("Id : ");
				this.setId(o.nextLine());
				System.out.println("Name : ");
				this.setName(o.nextLine());
				System.out.println("Salary : ");
				this.setSalary(o.nextInt());
				o.nextLine();
				a[i] = new emp(id, name, salary);
			}
			for(int i=0;i<a.length-1;i++) {
				for(int j=i+1;j<a.length;j++) {
					if(a[i].getSalary()>a[j].getSalary()) {
						emp tam = a[i];
						a[i]=a[j];
						a[j]=tam;
					}
				}
			}
			for(int i=0;i<a.length;i++) {
				fw.write(a[i].getId()+" | "+a[i].getName()+" | "+a[i].getSalary()+" .\n");
			}
		}catch (FileNotFoundException e) {
			e.printStackTrace();
			fw.close();
		}fw.close();
	}
	void output() throws IOException {
		File file = new File("C:\\nhap\\nhap.txt");
		FileReader fr = new FileReader(file);
		BufferedReader bf = new BufferedReader(fr);
		String t;
		try {
			while((t = bf.readLine())!=null) {
				System.out.println(t);
			}
		}catch(FileNotFoundException e) {
			e.printStackTrace();
			bf.close();
		}bf.close();
		
	}
}

public class employee {
	public static void main(String[] args) throws IOException {
		emp a = new emp();
		a.input();
		a.output();
	}
}
