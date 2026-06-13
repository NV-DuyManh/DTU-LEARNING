package Array1;

import java.util.*;

public class aaa {
	final static int MAX = 1000;

	public static void input(int a[]) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < a.length; i++) {
			System.out.print("a[" + i + "]=");
			a[i] = in.nextInt();
		}
	}

	public static void output(int a[]) {
		System.out.print("Dãy số đã nhập là: ");
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}

	public static void sln(int a[]) {
		int max = a[0];
		for (int i = 0; i < a.length; i++) {
			if (a[i] > max) {
				max = a[i];
			}
		}
		System.out.println("Số lớn nhất là: " + max);
	}

	public static void snn(int a[]) {
		int min = a[0];
		for (int i = 0; i < a.length; i++) {
			if (a[i] < min) {
				min = a[i];

			}
		}
		System.out.println("Số nhỏ nhất là: " + min);
	}

	public static int ktscp(int a) {
		int cp = (int) (Math.sqrt(a));
		if (cp * cp == a) {
			return 1;
		} else {
			return 0;
		}
	}

	public static void scp(int a[]) {
		int scp[] = new int[MAX];
		int k = 0;
		for (int i = 0; i < a.length; i++) {
			if (ktscp(a[i]) == 1) {
				scp[k] = a[i];
				k++;
			}
		}
		System.out.print("Dãy số chính phương là:");
		for (int i = 0; i < k; i++) {
			System.out.print(" " + scp[i]);

		}
		System.out.println();
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

	public static void shh(int a[]) {
		int shh[] = new int[MAX];
		int k = 0;
		for (int i = 0; i < a.length; i++) {
			if (ktshh(a[i]) == 1) {
				shh[k] = a[i];
				k++;
			}
		}
		System.out.print("Dãy số hoàn hảo là:");
		for (int i = 0; i < k; i++) {
			System.out.print(" " + shh[i]);
		}
		System.out.println();
	}


	public static int[] chen(int a[], int n, int m) {
		if (n < 0 || n > a.length) {
			System.out.println("Phan tu muon chen vuot qua pham vi mang!Vui long nhap phan tu muon chen khac!");
			return a;
		}
		int[] newa = new int[a.length + 1];
		for (int i = 0, j = 0; i < newa.length; i++) {
			if (i == n) {
				newa[i] = m;
			} else {
				newa[i] = a[j++];
			}
		}
		return newa;
	}

	
	public static int[] xoa(int a[], int n) {
		if (n < 0 || n > a.length) {
			System.out.println("Khong co phan tu can xoa trong mang!");
			return a;
		}
		int[] newa = new int[a.length - 1];
		for (int i = 0, j = 0; i < a.length; i++) {
			if (i != n) {
				newa[j++] = a[i];
			}
		}
		return newa;
	}

	public static void daonguoc(int[] a) {
		int dau = 0;
		int cuoi = a.length - 1;
		while (dau < cuoi) {
			int tam = a[dau];
			a[dau] = a[cuoi];
			a[cuoi] = tam;

			dau++;
			cuoi--;
		}
	}

	public static int ktso(int a) {

		if (a % 2 == 0) {
			return 1;
		} else {
			return 0;
		}
	}

	public static void schan(int a[]) {
		int schan[] = new int[MAX];
		int k = 0;
		for (int i = 0; i < a.length; i++) {
			if (ktso(a[i]) == 1) {
				schan[k] = a[i];
				k++;
			}
		}
		System.out.print("Dãy số chẵn là:");
		for (int i = 0; i < k; i++) {
			System.out.print(" " + schan[i]);
		}
		System.out.println();
	}

	public static void sle(int a[]) {
		int sle[] = new int[MAX];
		int k = 0;
		for (int i = 0; i < a.length; i++) {
			if (ktso(a[i]) == 0) {
				sle[k] = a[i];
				k++;
			}
		}
		System.out.print("Dãy số lẻ là:");
		for (int i = 0; i < k; i++) {
			System.out.print(" " + sle[i]);
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

	public static void tachmang(int a[], int[] snt, int[] khongSnt) {
		int k = 0, s = 0;

		for (int i = 0; i < a.length; i++) {
			if (ktsnt(a[i]) == 1) {
				snt[k++] = a[i];
			} else {
				khongSnt[s++] = a[i];
			}
		}

		System.out.print("Dãy số nguyên tố là:");
		for (int i = 0; i < k; i++) {
			System.out.print(" " + snt[i]);
		}
		System.out.println();

		System.out.print("Dãy không phải số nguyên tố là:");
		for (int i = 0; i < s; i++) {
			System.out.print(" " + khongSnt[i]);
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

	public static void main(String[] args) {
		int a[] = new int[10];
		int[] snt = new int[MAX];
		int[] khongSnt = new int[MAX];

		input(a);
		output(a);
		sln(a);
		snn(a);
		scp(a);
		shh(a);
		schan(a);
		sle(a);

		int n, m, l;
		Scanner o = new Scanner(System.in);
		System.out.println("\nNhập phần tử bạn muốn xóa trong mảng :");
		n = o.nextInt();
		a = xoa(a, n);
		System.out.println("Mảng sau khi xóa phần tử thứ " + n + " là :");
		output(a);

		System.out.println("\nNhập phần tử bạn muốn chèn trong mảng :");
		m = o.nextInt();
		System.out.println("\nNhập giá trị của phần tử bạn muốn chèn trong mảng :");
		l = o.nextInt();
		a = chen(a, m, l);
		System.out.println("Mảng sau khi chèn phần tử thứ " + m + " la :");
		output(a);
		daonguoc(a);
		System.out.println("\nMảng sau khi đảo ngược là : ");
		output(a);
		tachmang(a, snt, khongSnt);

		int k = 0, s = 0;
		for (int i = 0; i < a.length; i++) {
			if (ktsnt(a[i]) == 1) {
				k++;
			} else {
				s++;
			}
		}

		int[] hopMang = ghepMang(snt, k, khongSnt, s);
		System.out.print("Dãy sau khi ghép là:");
		for (int i = 0; i < hopMang.length; i++) {
			System.out.print(" " + hopMang[i]);
		}

	}

}
