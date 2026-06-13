package Class;	
import java.util.Scanner;

class employee {
    public int id;
    public String name;
    public float salary;

    public void input() {
        Scanner objSC = new Scanner(System.in);
        System.out.print("Nhập id: ");
        id = objSC.nextInt();
        objSC.nextLine();
        System.out.print("Nhập tên: ");
        name = objSC.nextLine();
        System.out.print("Nhập lương: ");
        salary = objSC.nextFloat();
        System.out.println();
    }

    public void output() {
        System.out.println("Id: " + id + ", Name: " + name + ", Salary: " + salary);
    }
}

class employeelish {
    public void input(employee el[]) {
        for (int i = 0; i < el.length; i++) {
            el[i] = new employee();
            el[i].input();
        }
    }

    public void output(employee el[]) {
        for (int i = 0; i < el.length; i++) {
            el[i].output();
        }
    }

    public void sapxep(employee a[]) {
        for (int i = 0; i < a.length - 1; i++) {
            for (int j = i + 1; j < a.length; j++) {
                if (a[i].salary < a[j].salary) {
                    float tam = a[i].salary;
                    a[i].salary = a[j].salary;
                    a[j].salary = tam;
                }
            }
        }
        System.out.print("Tiền lương khi sắp xếp giảm dần:");
        for (int i = 0; i < a.length; i++) {
            System.out.print(" " + a[i].salary);
        }
    }

    public float tongluong(employee a[]) {
        float tong = 0;
        for (int i = 0; i < a.length; i++) {
            tong += a[i].salary;
        }
        return tong;
    }

    public void maxsalary(employee a[]) {
        float maxSalary = a[0].salary;
        for (int i = 1; i < a.length; i++) {
            if (a[i].salary > maxSalary) {
                maxSalary = a[i].salary;
            }
        }
        System.out.println("Lương cao nhất của nhân viên: " + maxSalary);
    }
}

public class bbbb {
    public static void main(String[] args) {
        employee el[] = new employee[10];
        employeelish list = new employeelish();

        list.input(el);
        list.output(el);
        list.sapxep(el);
        list.maxsalary(el);

        float tongLuong = list.tongluong(el);
        System.out.println("\nTổng lương của tất cả nhân viên: " + tongLuong);
    }
}
