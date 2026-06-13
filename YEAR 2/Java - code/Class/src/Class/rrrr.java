package Class;

class Employeelist {
	Employee empList[] = new Employee[100];
	int n = 0;
	char chon, loai;

	void inputEmployee() throws IOException {
		do {
			System.out.println("Bien che hay hop dong(B/H)");
			loai = (char) System.in.read();
			if (loai == 'B' || loai == 'b') {
				empList[n] = new RegularEmployee();
			} else {
				empList[n] = new ContratStaff();
			}
			System.in.skip(loai);
			empList[n++].input();
			System.out.println("Tiep tuc(C/K)");
			chon = (char) System.in.read();
			System.in.skip(chon);
			if ((n == 100) || (chon == 'K') || (chon == 'k'))
				break;
		} while (true);
	}



	void outputEmployee() {
		for (int i = 0; i < n; i++) {
			System.out.println("ID" + empList[i].ID);
			System.out.println("Lương " + empList[i].salary);
		}
	}
}
public class rrrr {

	public static void main(String[] args) {
		EmpoyeeList objEmp = new EmployeeList();
		objEmp.inputEmployee();
		objEmp.outputEmployee();
		

	}

}
