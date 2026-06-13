package Array3;

import java.util.*;

public class a3333 {
	final static int MAX = 1000;

	public static void input(int a[]) {
		Scanner ii = new Scanner(System.in);
		for (int i = 0; i < a.length; i++) {
			System.out.print("a[" + i + "]=");
			a[i] = ii.nextInt();
		}
	}

	public static void output(int a[]) {
		System.out.print("Dãy số đã nhập là: ");
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}

	public static int ktsnt(int a) {
		if (a <= 1) {
			return 0;
		}
		for (int i = 2; i <= Math.sqrt(a); i++) {
			if (a % i == 0) {
				return 0;
			}
		}
		return 1;
	}

	public static void snt(int a[]) {
		int snt[] = new int[MAX];
		int k = 0;
		for (int i = 0; i < a.length; i++) {
			if (ktsnt(a[i]) == 1) {
				snt[k] = a[i];
				k++;
			}
		}
		System.out.print("Dãy số nguyên tố là:");
		for (int i = 0; i < k; i++) {
			System.out.print(" " + snt[i]);
		}
		System.out.println();
		if (k == a.length) {
			System.out.print("Tất cả đều là số nguyên tố");
		} else {
			System.out.print("Không phải tất cả đều là nguyên tố");
		}
		System.out.println();
	}

	public static int[] chen(int a[]) {
		Scanner uu = new Scanner(System.in);
		int dau, cuoi;
		System.out.print("Nhập phần tử đầu cần chèn: ");
		dau = uu.nextInt();
		System.out.print("Nhập phần tử cuối cần chèn: ");
		cuoi = uu.nextInt();

		int tam[] = new int[a.length + 2];
		tam[0] = dau;
		tam[tam.length - 1] = cuoi;

		for (int i = 1; i < tam.length - 1; i++) {
			tam[i] = a[i - 1];
		}

		return tam;
	}

	public static int[] xoa(int a[]) {
		int tam[] = new int[a.length - 2];
		for (int i = 0; i < tam.length; i++) {
			tam[i] = a[i + 1];
		}
		return tam;
	}

	public static int ktshh(int a) {
		int n = 0;
		for (int i = 1; i < a; i++) {
			if (a % i == 0) {
				n += i;
			}
		}
		if (n == a) {
			return 1;
		} else {
			return 0;
		}
	}

	public static void tachmang(int a[], int[] shh, int[] kshh) {
		int k = 0, s = 0;

		for (int i = 0; i < a.length; i++) {
			if (ktshh(a[i]) == 1) {
				shh[k++] = a[i];
			} else {
				kshh[s++] = a[i];
			}
		}

		System.out.print("Dãy số hoàn hảo là:");
		for (int i = 0; i < k; i++) {
			System.out.print(" " + shh[i]);
		}
		System.out.println();

		System.out.print("Dãy không phải số hoàn hảo là:");
		for (int i = 0; i < s; i++) {
			System.out.print(" " + kshh[i]);
		}
		System.out.println();
	}

	public static int[] ghepMang(int[] a, int aLength, int[] b, int bLength) {
		int[] hop = new int[aLength + bLength];
		int index = 0;

		for (int i = 0; i < aLength; i++) {
			hop[index++] = a[i];
		}
		for (int i = 0; i < bLength; i++) {
			hop[index++] = b[i];
		}

		return hop;
	}

	public static void giam(int a[]) {
		int giam;
		for (int i = 0; i < a.length - 1; i++) {
			for (int j = i + 1; j < a.length; j++) {
				if (a[i] < a[j]) {
					giam = a[i];
					a[i] = a[j];
					a[j] = giam;
				}
			}
		}
		System.out.print("Mảng sau khi sắp xếp giảm dần:");
		for (int i = 0; i < a.length; i++) {
			System.out.print(" " + a[i]);
		}
	}

	public static void tang(int a[]) {
		int tang;
		for (int i = 0; i < a.length - 1; i++) {
			for (int j = i + 1; j < a.length; j++) {
				if (a[i] > a[j]) {
					tang = a[i];
					a[i] = a[j];
					a[j] = tang;
				}
			}
		}
		System.out.print("Mảng sau khi sắp xếp tăng dần:");
		for (int i = 0; i < a.length; i++) {
			System.out.print(" " + a[i]);
		}
	}

	public static void main(String[] args) {
		int a[] = new int[5];
		int[] shh = new int[MAX];
		int[] kshh = new int[MAX];
		input(a);
		output(a);
		snt(a);
		a = chen(a);
		System.out.print("Mảng sau khi chèn: ");
		output(a);
		a = xoa(a);
		System.out.print("Mảng sau khi xóa: ");
		output(a);
		tachmang(a, shh, kshh);
		int k = 0, s = 0;
		for (int i = 0; i < a.length; i++) {
			if (ktshh(a[i]) == 1) {
				k++;
			} else {
				s++;
			}
		}
		int[] hopMang = ghepMang(shh, k, kshh, s);
		System.out.print("Dãy sau khi ghép là:");
		for (int i = 0; i < hopMang.length; i++) {
			System.out.print(" " + hopMang[i]);
		}
		System.out.println();
		giam(a);
		System.out.println();
		tang(a);
	}
}
