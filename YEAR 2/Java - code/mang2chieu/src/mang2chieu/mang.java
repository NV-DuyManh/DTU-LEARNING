package mang2chieu;

import java.util.*;
import java.io.*;
public class mang {
	int a[][];
	int m, n;

	void nhap() {
		Scanner kb = new Scanner(System.in);
		System.out.println("Nhap so hang");
		m = kb.nextInt();
		System.out.println("Nhap so cot");
		n = kb.nextInt();
		a = new int[m][n];
		Random rd = new Random();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = kb.nextInt();
			}
		}

	}

	void in() {
		for (int i = 0; i < m; i++) {
			System.out.println("\n");
			for (int j = 0; j < n; j++) {
				// System.out.println(" "+a[i][j]);
				System.out.format("%5d", a[i][j]);
			}
		}System.out.println();

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		mang m = new mang();
		m.nhap();
		m.in();
	}

}
