package Nguyen;

public class Sort2 {
	public int number1;
	public int number2;

	public void sortDesc() {
		if (number1 < number2) {
			int temp = number1;
			number1 = number2;
			number2 = temp;
		}
	}
}
