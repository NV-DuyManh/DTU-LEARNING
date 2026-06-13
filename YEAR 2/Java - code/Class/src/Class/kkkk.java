package Class;
import java.util.*;

class person {
    public int id;
    public String name;

    public void input() {
        Scanner objSc = new Scanner(System.in);
        System.out.println("ID: ");
        this.id = objSc.nextInt();
        objSc.nextLine();
        System.out.println("Name: ");
        this.name = objSc.nextLine();
    }

    public void output() {
        System.out.println("ID: " + this.id + "    Name: " + this.name);
    }
}

class students extends person {
    public int studID;
    public float GPA;

    public void input() {
        super.input();
        Scanner objSc = new Scanner(System.in);
        System.out.println("Student ID: ");
        this.studID = objSc.nextInt();
        System.out.println("GPA: ");
        this.GPA = objSc.nextFloat();
    }

    public void output() {
        super.output();
        System.out.println("Student ID: " + this.studID + "    GPA: " + this.GPA);
    }
}

public class kkkk {
    public static void main(String[] args) {
        students student = new students();
        student.input();
        student.output();
    }
}
