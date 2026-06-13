package EmployeeList;

import java.util.*;
import java.io.IOException;

class Employee {
	public String id, name, code;

	public double getPayment() {
		return 0;
	}

	public double getBasicSalary() {
		return 0;
	}

	public Employee() {

	}

	public Employee(String id, String name, String code) {
		this.id = id;
		this.name = name;
		this.code = code;
	}

	public String getid() {
		return this.id;
	}

	public String getname() {
		return this.name;
	}

	public String getcode() {
		return this.code;
	}

	public void setid(String id) {
		this.id = id;
	}

	public void setname(String name) {
		this.name = name;
	}

	public void setcode(String code) {
		this.code = code;
	}

	public void input() {
		Scanner qq = new Scanner(System.in);
		System.out.println("Nhập ID: ");
		id = qq.nextLine();
		System.out.println("Nhập name: ");
		name = qq.nextLine();
		System.out.println("Nhập code: ");
		code = qq.nextLine();

	}
}

class SoftwarePM extends Employee {
	public double bonus;

	public SoftwarePM() {

	}

	public SoftwarePM(String id, String name, String code, double bonus) {
		super(id, name, code);
		this.bonus = bonus;
	}

	public String getbonus() {
		return this.bonus;
	}

	public void setbonus(double bonus) {
		this.bonus = bonus;
	}

	public void input() {
		super.input();
		Scanner ww = new Scanner(System.in);
		System.out.println("Nhập bonus: ");
		bonus = ww.nextDouble();
	}
	public double getBasicSalary() {
		double salary =0;
		if(this.getcode()==1) {
			salary=30000000;
		}else if(th)
	}

}

public class EmployeeList {

	public static void main(String[] args) {

	}

}
