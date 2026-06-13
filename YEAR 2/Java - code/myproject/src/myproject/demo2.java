package myproject;


import java.io.*;
import java.util.*;
public class demo2 {
	public static void main(String[] args) {
		int a, b, c;
		char ch, con;
		Scanner objSc = new Scanner(System.in);
		do {
			System.out.println("Nhap a: ");
			a = objSc.nextInt();
			System.out.println("Nhap b: ");
			b = objSc.nextInt();
			System.out.println("Moi ban nhap ki tu(+,-,*,/): ");
			ch = (char) System.in.read();

			switch (ch) {
			case '+':
				c = a + b;
				System.out.println("Tong 2 so: " + c);
				break;
			case '-':
				c = a - b;
				System.out.println("Hieu 2 so: " + c);
				break;
			case '*':
				c = a * b;
				System.out.println("Tich 2 so: " + c);
				break;
			case '/':
				c = a / b;
				System.out.println("Thuong 2 so: " + c);
				break;
			default:
				System.out.println("Nhap sai");
				break;
			}
			System.in.skip(ch);
			System.out.println("Tiep tuc khong?(Y/N)");
			con = (char) System.in.read();
		} while (con == 'Y' || con == 'y');
	}
}
