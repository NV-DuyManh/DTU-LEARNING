package myproject;

import java.util.Scanner;

public class demo {

	public static void main(String[] args) {
		float a, b, c;

		Scanner input = new Scanner(System.in);
		System.out.println("Nhap a: ");
		a = input.nextFloat();
		System.out.println("Nhap b: ");
		b = input.nextFloat();
		System.out.println("Nhap c: ");
		c = input.nextFloat();
		float delta = b * b - 4 * a * c;
		if (delta > 0) {
			float x1 = (float) ((-b + Math.sqrt(delta)) / (2 * a));
			float x2 = (float) ((-b - Math.sqrt(delta)) / (2 * a));
			System.out.println("Phương trình có nghiệm kép: x1 = " + x1 + " và x2 = " + x2);
		} else if (delta == 0) {
			float x1 = -b / (2 * a);
			System.out.println("Pt có n0 kép x1=x2 =" + x1);

		} else {
			System.out.println("pt vô nghiệm");
		}
	}
}