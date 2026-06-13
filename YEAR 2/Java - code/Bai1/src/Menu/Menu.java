package Menu;

import java.util.*;

public class Menu {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		float a, b, c;
		int i;
		do {
			System.out.println("1. PT bậc 1: ");
			System.out.println("2. PT bậc 2: ");
			System.out.println("3. Exit: ");
			System.out.println("Nhập lựa chọn: ");
			i = input.nextInt();
			switch (i) {
			case 1:
				System.out.println("Nhap a: ");
				a = input.nextFloat();
				System.out.println("Nhap b: ");
				b = input.nextFloat();
				if (a == 0) {
					if (b == 0) {
						System.out.println("VSN");
					} else {
						System.out.println("VN");
					}
				} else {
					float x = -b / a;
					System.out.println("Pt có nghiệm là: " + x);
				}
				break;
			case 2:
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
					System.out.println("Pt có 2 nghiệm là: x1= " + x1 + " và x2= " + x2);
				} else if (delta == 0) {
					float x1 = -b / (2 * a);
					System.out.println("Pt có nghiệm kép x1=x2=: " + x1);
				} else {
					System.out.println("Pt vô nghiệm");
				}
				break;
			default:
				System.out.println("Đã thoát chương trình.");
			}
		} while (i != 3);
	}
}
