package docfile;

import java.io.*;


import java.util.*;


class nv {
	int id;
	String name;
	float salary;

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public float getSalary() {
		return salary;
	}

	public void setSalary(float salary) {
		this.salary = salary;
	}

	void input() throws IOException {
		Scanner q = new Scanner(System.in);

		System.out.println("Nhap id: ");
		id = q.nextInt();
		q.nextLine();
		System.out.println("Nhap name: ");
		name = q.nextLine();
		System.out.println("Nhap salary: ");
		salary = q.nextFloat();
	}

	String output() {
		return this.id + ", " + this.name + ", " + this.salary + "\n";
	}

}

public class DocNhanVien {

	public static void main(String[] args) throws IOException {
		File b = new File("D:\\cmutpm2.txt");
		FileWriter c = new FileWriter(b);
		nv a[] = new nv[10];
		for (int i = 0; i < a.length; i++) {
			System.out.println("Nhap nhan vien thu " + (i + 1) + " la: ");
			a[i] = new nv();
			a[i].input();
		}
		for (int i = 0; i < a.length - 1; i++) {
			for (int j = i + 1; j < a.length; j++) {
				if (a[i].salary > a[j].salary) {
					nv tam = a[i];
					a[i] = a[j];
					a[j] = tam;
				}
			}
		}
		for (int i = 0; i < a.length; i++) {
			try {
				c.write(a[i].output() + " \n");
			} catch (FileNotFoundException e) {
				e.printStackTrace();
				c.close();
			}
		}
		c.close();
		FileReader d = new FileReader(b);
		BufferedReader r = new BufferedReader(d);
		String w = null;
		try {
			while ((w = r.readLine()) != null) {
				System.out.println(w);
			}
		} catch (FileNotFoundException t) {
			t.printStackTrace();
			r.close();
		}
		r.close();
	}

}



