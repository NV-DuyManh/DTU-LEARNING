package onthi;

import java.util.*;
import java.io.*;

interface IEMPLOYEE {
	final static int BASIC_SALARY = 234000;

	double calSalary();
}

abstract class EMPLOYEE implements IEMPLOYEE {
	private String empID, name, startDate;

	public EMPLOYEE() {
	}

	public EMPLOYEE(String empID, String name, String startDate) {
		this.empID = empID;
		this.name = name;
		this.startDate = startDate;
	}

	public String getEmpID() {
		return empID;
	}

	public void setEmpID(String empID) {
		this.empID = empID;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getStartDate() {
		return startDate;
	}

	public void setStartDate(String startDate) {
		this.startDate = startDate;
	}

	public abstract double calSalary();

	public void input() {
		Scanner a = new Scanner(System.in);
		System.out.println("Enter empID: ");
		this.setEmpID(a.nextLine());
		System.out.println("Enter name: ");
		this.setName(a.nextLine());
		System.out.println("Enter startDate: ");
		this.setStartDate(a.nextLine());
	}

	public void output() {

		System.out.println(" empID: " + getEmpID());

		System.out.println(" name: " + getName());

		System.out.println(" startDate: " + getStartDate());

	}

}

class EMP_FULLTIME extends EMPLOYEE {

	private double coefficientSalary;

	public EMP_FULLTIME() {
	}

	public EMP_FULLTIME(String empID, String name, String startDate, double coefficientSalary) {
		super(empID, name, startDate);
		this.coefficientSalary = coefficientSalary;
	}

	public double getCoefficientSalary() {
		return coefficientSalary;
	}

	public void setCoefficientSalary(double coefficientSalary) {
		this.coefficientSalary = coefficientSalary;
	}

	public void input() {
		super.input();
		Scanner a = new Scanner(System.in);
		System.out.println("Enter coefficientSalary: ");
		this.setCoefficientSalary(a.nextDouble());
	}

	public void output() {
		super.output();
		System.out.println(" coefficientSalary: " + getCoefficientSalary());
	}

	public double calSalary() {
		double salary = this.BASIC_SALARY * this.coefficientSalary;
		return salary;
	}

}

class EMP_PARTTIME extends EMPLOYEE {

	public float numberOfWorkdays;

	public EMP_PARTTIME() {

	}

	public EMP_PARTTIME(String empID, String name, String startDate, float numberOfWorkdays) {
		super(empID, name, startDate);
		this.numberOfWorkdays = numberOfWorkdays;
	}

	public float getNumberOfWorkdays() {
		return numberOfWorkdays;
	}

	public void setNumberOfWorkdays(float numberOfWorkdays) {
		this.numberOfWorkdays = numberOfWorkdays;
	}

	public void input() {
		super.input();
		Scanner a = new Scanner(System.in);
		System.out.println("Enter numberOfWorkdays: ");
		this.setNumberOfWorkdays(a.nextFloat());
	}

	public void output() {
		super.output();
		System.out.println(" numberOfWorkdays: " + getNumberOfWorkdays());
	}

	public double calSalary() {
		double salary = this.BASIC_SALARY * this.numberOfWorkdays / 26;
		return salary;
	}

}

class EMP_LIST{
	ArrayList<EMPLOYEE> list = new ArrayList<EMPLOYEE>();
	int n=0;
	char chon,loai;
	void input() throws IOException{
		do {
			EMPLOYEE a[]= new EMPLOYEE[100];
			System.out.println("1. EMP_FULLTIME");
			System.out.println("2. EMP_PARTTIME");
			System.out.println("3. EXIT");
			chon = (char)System.in.read();
			if(chon =='1') {
				a[n]= new EMP_FULLTIME();
			}else if(chon=='2') {
				a[n]= new EMP_PARTTIME();
			}else {
				return;
			}
			System.in.skip(chon);
			a[n].input();
			list.add(a[n++]);
			System.out.println("Tiep tuc(C/K)");
			loai = (char)System.in.read();
			System.in.skip(loai);
			if((n==100)||(loai=='k')||(loai=='K')) {
				break;
			}
		}while(true);
	}
	void update() {
		for(int i=0;i<list.size();i++) {
			list.get(i).output();
		}
	}
	void find() {
		Scanner a = new Scanner(System.in);
		System.out.println("Nhap id can tim: ");
		String b = a.nextLine();
		int k=-1;
		for(int i=0;i<list.size();i++) {
			if(list.get(i).getEmpID().contains(b)) {
				k=i;
				list.get(i).output();
				break;
			}
		}
		if(k==-1) {
			System.out.println("Khong tim thay id " +b);
		}
	}
	void delete() {
		Scanner a = new Scanner(System.in);
		System.out.println("Nhap id can xoa: ");
		String b = a.nextLine();
		
		for(int i=0;i<list.size();i++) {
			if(list.get(i).getEmpID().contains(b)) {
				list.remove(i);
			}
		}
	}
	void max() {
		EMPLOYEE max = list.get(0);
		for(int i=1;i<list.size();i++) {
			if(max.calSalary()<list.get(i).calSalary()) {
				max=list.get(i);
			}
		}System.out.println("MAX is: "+max.getEmpID()+" with price: "+max.calSalary());
	
	}
	
	void min() {
		EMPLOYEE min = list.get(0);
		for(int i=1;i<list.size();i++) {
			if(min.calSalary()>list.get(i).calSalary()) {
				min=list.get(i);
			}
		}System.out.println("Min is: "+min.getEmpID()+" with price: "+min.calSalary());
	
	}
	double sumf() {
		double sum=0;
		for(int i=1;i<list.size();i++) {
			if(list.get(i) instanceof EMP_FULLTIME) {
				sum+=list.get(i).calSalary();
			}
		}System.out.println("Sum fulltime: "+sum);
			
		return sum;
	}
	
	double sump() {
		double sum =0;
		
		for(int i=0;i<list.size();i++) {
			if(list.get(i)instanceof EMP_PARTTIME) {
				sum+=list.get(i).calSalary();
			}
		}System.out.println("Sum parttime: "+sum);
		return sum;
	}
	double sumall() {
		double sum =0;
		
		for(int i=0;i<list.size();i++) {
				sum+=list.get(i).calSalary();
		}System.out.println("Sum parttime: "+sum);
		return sum;
	}
	
	void sort() {
		for(int i=0;i<list.size()-1;i++) {
			for(int j=i+1;j<list.size();j++) {
				if(list.get(i).calSalary()<list.get(j).calSalary()) {
					EMPLOYEE temp = list.get(i);
					list.set(i,list.get(j));
					list.set(j, temp);
				}
			}
		}
		System.out.println("sau khi sap xep: ");
		update();
	}

	void Menu() throws IOException{
		Scanner a = new Scanner(System.in);
		while(true) {
			System.out.println("1. AddNew");
			System.out.println("2. update");
			System.out.println("3. find");
			System.out.println("4. delete");
			System.out.println("5. max");
			System.out.println("6. min");
			System.out.println("7. sumf");
			System.out.println("8. sump");
			System.out.println("9. sumall");
			System.out.println("10. sort");
			System.out.println("11. exit");
			
		
			int b = a.nextInt();
			switch(b) {
			case 1:
				input();
				break;
			case 2:
				update();
				break;
			case 3:
				find();
				break;
			case 4:
				delete();
				break;
			case 5:
				max();
				break;
			case 6:
				min();
				break;
			case 7:
				sumf();
				break;
			case 8:
				sump();
				break;
			case 9:
				sumall();
				break;
			case 10:
				sort();
				break;
			case 11:
				System.out.println("Exiting....");
				return ;
			default:
				System.out.println("Try again!");
				break;
			}
		}
	}
}









public abstract class onn {

	public static void main(String[] args) throws IOException {
		EMP_LIST a = new EMP_LIST();
		a.Menu();

	}

}
