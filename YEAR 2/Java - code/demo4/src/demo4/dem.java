package demo4;

import java.util.*;
import java.io.IOException;

class Employee {
    public String id;
    public String name;
    public float salary;

    public void input() {
        Scanner qq = new Scanner(System.in);
        System.out.print("Nhập id: ");
        id = qq.nextLine();
        System.out.print("Nhập name: ");
        name = qq.nextLine();
        System.out.print("Nhập salary: ");
        salary = qq.nextFloat();
    }

    public void output() {
        System.out.print("Id: " + this.id + ", Name: " + this.name + ", Salary: " + this.salary);
        System.out.println();
    }

    public float calculateSalary() {
        return this.salary;
    }
}

class RegularEmployee extends Employee {
    public float salaryGrading;
    public float benefitGrading;

    public RegularEmployee() {
        this.salaryGrading = this.benefitGrading = 0;
    }

    public RegularEmployee(String id, String name, float salary, float salaryGrading, float benefitGrading) {
        super.id = id;
        super.name = name;
        super.salary = salary;
        this.salaryGrading = salaryGrading;
        this.benefitGrading = benefitGrading;
    }

    public void input() {
        super.input();
        Scanner rr = new Scanner(System.in);
        System.out.print("Nhập salaryGrading: ");
        salaryGrading = rr.nextFloat();
        System.out.print("Nhập benefitGrading: ");
        benefitGrading = rr.nextFloat();
    }

    public void output() {
        super.output();
        System.out.print("SalaryGrading: " + this.salaryGrading + ", BenefitGrading: " + this.benefitGrading);
        System.out.println();
    }

    public float calculateSalary() {
        this.salary = 1000000 * (1 + this.salaryGrading + this.benefitGrading);
        return this.salary;
    }
}

class ContractStaff extends Employee {
    public float wage;
    public float workday;
    public float excessHoursGrading;

    public ContractStaff() {
        this.wage = this.workday = this.excessHoursGrading = 0;
    }

    public ContractStaff(String id, String name, float salary, float wage, float workday, float excessHoursGrading) {
        super.id = id;
        super.name = name;
        super.salary = salary;
        this.wage = wage;
        this.workday = workday;
        this.excessHoursGrading = excessHoursGrading;
    }

    public void input() {
        super.input();
        Scanner rr = new Scanner(System.in);
        System.out.print("Nhập wage: ");
        wage = rr.nextFloat();
        System.out.print("Nhập workday: ");
        workday = rr.nextFloat();
        System.out.print("Nhập excessHoursGrading: ");
        excessHoursGrading = rr.nextFloat();
    }

    public void output() {
        super.output();
        System.out.println("Wage: " + this.wage + ", Workday: " + this.workday + ", ExcessHoursGrading: " + this.excessHoursGrading);
    }

    public float calculateSalary() {
        this.salary = this.wage * this.workday * (1 + this.excessHoursGrading);
        return this.salary;
    }
}

class EmployeeList {
	Employee a[]=new Employee[100];
	int n=0;
	char loai, chon;
	void inputepl() throws IOException{
		do {
			System.out.println("B/H");
			loai =(char)System.in.read();
			if(loai == 'b'|| loai =='B') {
				a[n]=new RegularEmployee();
			}
			else {
				a[n]=new ContractStaff();
			}
			System.in.skip(loai);
			a[n++].input();
			System.out.println("C/K");
			chon=(char)System.in.read();
			System.in.skip(chon);
			if((n==100)||(chon=='k'||chon=='K')) {
				break;
			}
		}while(true);
	}
	void outputepl(){
		for(int i=0;i<n;i++) {
			a[i].output();
		}
	}
	 public void max() {
		Employee max=a[0];
		for(int i=0;i<n;i++) {
			if(a[i].salary>max.salary) {
				max=a[i];
			}
		}
		System.out.println("Số lương lớn nhất: "+max);

	}
	 public void sapxep() {
		 Employee tam = a[0];
		 for(int i=0;i<n-1;i++) {
			 for(int j=i+1;i<n;j++) {
				 if(a[i].salary<a[j].salary) {
					 tam=a[i];
					 a[i]=a[j];
					 a[j]=tam;
				 }
			 }
		 }System.out.println("Nv sau khi sap xep: ");
		 for(int i=0;i<n;i++) {
			 a[i].output();
		 }
	 }
}
	
  
public class dem {

    public static void main(String[] args) throws IOException {
       EmployeeList nv = new EmployeeList();
       nv.inputepl();
       nv.outputepl();
    }
}
