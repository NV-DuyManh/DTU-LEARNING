package nv;

import java.util.*;

import java.io.IOException;

class projectEmp {
    public String  name;
    public int level;
    public double bonus;

    public double getPayment() {
        return 0;
    }

    public double getBasicSalary() {
        return 0;
    }

    public projectEmp() {}

    public projectEmp( String name, int level, double bonus) {
        this.name = name;
        this.level = level;
        this.bonus = bonus;
    }

    public int getlevel() {
        return this.level;
    }

    public String getName() {
        return this.name;
    }

    public double getbonus() {
        return this.bonus;
    }

    public void setlevel(int level) {
        this.level = level;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setCode(double bonus) {
        this.bonus = bonus;
    }

    public void input() {
        Scanner qq = new Scanner(System.in);
        System.out.println("Nhập name: ");
        name = qq.nextLine();
        System.out.println("Nhập level: ");
        level = qq.nextInt();
        System.out.println("Nhập bonus: ");
        bonus = qq.nextDouble();
      
    }
}

class PMEmp extends projectEmp {
    public double coefficient;

    public PMEmp() {}

    public PMEmp(String name, int level, double bonus,double coefficient) {
        super(name, level, bonus);
        this.coefficient = coefficient;
    }

    public double getcoefficient() {
        return this.coefficient;
    }

    public void setcoefficient(double coefficient) {
        this.coefficient = coefficient;
    }

    public void input() {
        super.input();
        Scanner ss = new Scanner(System.in);
        System.out.println("Nhập coefficient: ");
        coefficient = ss.nextDouble();
     
    }

    public double getBasicSalary() {
        if (this.getlevel()==1) {
            return 20000000;
        } else if (this.getlevel()==2) {
            return 15000000;
        } else {
            return 1200000;
        }
    }

    public double getPayment() {
        return this.getBasicSalary() + this.bonus*this.coefficient;
    }
}

class devEmp extends projectEmp {
    public int overTime;

    public devEmp() {}

    public devEmp(String name, int level, double bonus,int overTime)	 {
    	 super(name, level, bonus);
         this.overTime = overTime;
    }

    public int getoverTime() {
        return this.overTime;
    }

    public void setoverTime(int overTime) {
        this.overTime = overTime;
    }

   

    public void input() {
        super.input();
        Scanner tt = new Scanner(System.in);
      
        System.out.println("Nhập overTime: ");
        overTime = tt.nextInt();
     
    }

    public double getBasicSalary() {
    	if (this.getlevel()==1) {
            return 15000000;
        } else if (this.getlevel()==2) {
            return 11000000;
        } else {
            return 800000;
        }
    }

    public double getPayment() {
        return this.getBasicSalary() + this.bonus + this.overTime * this.getBasicSalary() / 24;
    }
}

public class ArrayOfProjectEmp {
    public static double sum(projectEmp[] arr) {
        double sum = 0;
       
		for(int i=0;i<arr.length;i++) {
			sum+=arr[i].getPayment();
		}
        System.out.println("Tổng lương 5 nhân viên là: " + sum);
        return sum;
    }

    public static void sort(projectEmp[] arr) {
	    for (int i = 0; i < arr.length-1; i++) {
	        for (int j = i + 1; j < arr.length; j++) {
	            if (arr[i].getPayment() > arr[j].getPayment()) {
	            	projectEmp temp = arr[i];
	                arr[i] = arr[j];
	                arr[j] = temp;
	            }
	        }
	    }
	    System.out.println();
	    System.out.println("Sắp xếp lương tăng dần theo tên nhân viên: ");
	    for (int i = 0; i < arr.length; i++) {
	        System.out.println(" -> "+arr[i].name+" || Luong "+arr[i].getPayment());
	    }
	}

    public static void main(String[] args) {
    	projectEmp[] arr = new projectEmp[5];
    	arr[0] = new devEmp("Hieu",2, 100, 3);
    	arr[1] = new PMEmp("Trung",3,300,1.3);
    	arr[2] = new devEmp("Manh",1, 2000, 3);
    	arr[3] = new PMEmp("Loc",3,4500,1.3);
    	arr[4] = new devEmp("Kha",2, 240, 3);
        sum(arr);
        sort(arr);
    }
}
