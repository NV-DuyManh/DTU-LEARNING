package Sophuc;

import java.util.*;




class Employee {
    public String id, name, code;

    public double getPayment() {
        return 0;
    }

    public double getBasicSalary() {
        return 0;
    }

    public Employee() {}

    public Employee(String id, String name, String code) {
        this.id = id;
        this.name = name;
        this.code = code;
    }

    public String getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public String getCode() {
        return this.code;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public void input() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Nhập ID: ");
        id = scanner.nextLine();
        System.out.println("Nhập name: ");
        name = scanner.nextLine();
        System.out.println("Nhập code: ");
        code = scanner.nextLine();
        scanner.close();
    }
}

class SoftwarePM extends Employee {
    public double bonus;

    public SoftwarePM() {}

    public SoftwarePM(String id, String name, String code, double bonus) {
        super(id, name, code);
        this.bonus = bonus;
    }

    public double getBonus() {
        return this.bonus;
    }

    public void setBonus(double bonus) {
        this.bonus = bonus;
    }

    public void input() {
        super.input();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Nhập bonus: ");
        bonus = scanner.nextDouble();
        scanner.close();
    }

    public double getBasicSalary() {
        if (this.getCode()==("1")) {
            return 30000000;
        } else if (this.getCode()==("2")) {
            return 20000000;
        } else {
            return 3200000;
        }
    }

    public double getPayment() {
        return this.getBasicSalary() + this.bonus;
    }
}

class Programmer extends Employee {
    public double bonus;
    public int OTMoney;

    public Programmer() {}

    public Programmer(String id, String name, String code, double bonus, int OTMoney) {
        super(id, name, code);
        this.bonus = bonus;
        this.OTMoney = OTMoney;
    }

    public double getBonus() {
        return this.bonus;
    }

    public void setBonus(double bonus) {
        this.bonus = bonus;
    }

    public int getOTMoney() {
        return this.OTMoney;
    }

    public void setOTMoney(int OTMoney) {
        this.OTMoney = OTMoney;
    }

    public void input() {
        super.input();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Nhập bonus: ");
        bonus = scanner.nextDouble();
        System.out.println("Nhập OTMoney: ");
        OTMoney = scanner.nextInt();
        scanner.close();
    }

    public double getBasicSalary() {
        if (this.getCode()==("1")) {
            return 25000000;
        } else if (this.getCode()==("2")) {
            return 13000000;
        } else {
            return 600000;
        }
    }

    public double getPayment() {
        return this.getBasicSalary() + this.bonus + this.OTMoney * this.getBasicSalary() / 24;
    }
}

public class sophuc {
    public static double sum(Employee[] arr) {
        double sum = 0;
       
		for(int i=0;i<arr.length;i++) {
			sum+=arr[i].getPayment();
		}
        System.out.println("Tổng lương 5 nhân viên là: " + sum);
        return sum;
    }

    public static void sort(Employee[] arr) {
    	Employee temp=arr[0];
	    for (int i = 0; i < arr.length-1; i++) {
	        for (int j = i + 1; j < arr.length; j++) {
	            if (arr[i].getPayment() > arr[j].getPayment()) {
	                temp = arr[i];
	                arr[i] = arr[j];
	                arr[j] = temp;
	            }
	        }
	    }
	    System.out.println();
	    System.out.println("Sắp xếp lương tăng dần theo tên nhân viên: ");
	    for (int i = 0; i < arr.length; i++) {
	        System.out.println(arr[i].name);
	    }
	}

    public static void main(String[] args) {
        Employee[] arr = new Employee[5];
        arr[0] = new Programmer("1", "Can", "2", 300, 100000);
        arr[1] = new SoftwarePM("2", "Khoi", "2", 200000);
        arr[2] = new Programmer("3", "Manh", "2", 200, 300000);
        arr[3] = new SoftwarePM("4", "Loc", "2", 400000);
        arr[4] = new Programmer("5", "Kha", "2", 100, 500000);
        sum(arr);
        sort(arr);
    }
}
