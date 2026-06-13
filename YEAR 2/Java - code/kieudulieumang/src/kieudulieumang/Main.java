package kieudulieumang;

import java.util.*;

public class Main {
	int[] a;

	void nhap(int n) {
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = (int) (Math.random() * 1000000);
		}
	}

	void in() {
		System.out.println("\nNoi dung mang: ");
		for (int i = 0; i < a.length; i++) {
			System.out.println(a[i] + " ");
		}
	}

	void chenx(int x, int k) {
		int n = a.length;
		int i = 0;

		if (k < 0 || k > n) {
			System.out.println("Không chèn được");
		} else {
			int b[] = new int[n + 1];
			for (i = 0; i < k; i++) {
				b[i] = a[i];
			}
			for (i = n; i > k; i--) {
				b[i] = a[i - 1];

			}
			b[k] = x;
			a = b;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Main m = new Main();
		m.nhap(10);
		m.in();
		m.chenx(100, 5);
		m.in();
		System.out.println("\n Xong"); // S.O.P
	}

}
