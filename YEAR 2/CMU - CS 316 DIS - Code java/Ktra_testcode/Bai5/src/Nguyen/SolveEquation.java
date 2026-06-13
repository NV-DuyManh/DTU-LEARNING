package Nguyen;

public class SolveEquation {
	private int number1;
	private int number2;

	public int getNumber1() {
		return number1;
	}

	public void setNumber1(int number1) {
		this.number1 = number1;
	}

	public int getNumber2() {
		return number2;
	}

	public void setNumber2(int number2) {
		this.number2 = number2;
	}

	public String linearEquation() {
		if (number1 == 0)
			if (number2 == 0)
				return "Multi roots";
			else
				return "No root";
		else
			return "One root";
	}
}