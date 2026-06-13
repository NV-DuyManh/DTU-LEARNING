package Nguyen;

public class Sort1 {
	public static int number1;
	public static int number2;

	public static void sortAsc() {
		if (number1 > number2) {
			int temp = number1;
			number1 = number2;
			number2 = temp;
		}
	}
}
