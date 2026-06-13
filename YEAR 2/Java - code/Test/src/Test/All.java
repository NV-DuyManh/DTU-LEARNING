package Test;

import java.util.*;

public class All {
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
			System.out.print(" " + a[i]);
		}
		System.out.println();
	}

	public static void max(int a[]) {
		int max = a[0];
		for (int i = 0; i < a.length; i++) {
			if (a[i] > max) {
				max = a[i];
			}
		}
		System.out.println("Sln là: " + max);
	}

	public static void min(int a[]) {
		int min = a[0];
		for (int i = 0; i < a.length; i++) {
			if (a[i] < min) {
				min = a[i];
			}
		}
		System.out.println("Snn là: " + min);
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
		System.out.print("Dãy số nguyên tố là: ");
		for (int i = 0; i < k; i++) {
			System.out.print(" " + snt[i]);
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
		System.out.print("Dãy số hoàn hảo là: ");
		for (int i = 0; i < k; i++) {
			System.out.print(" " + shh[i]);
		}
		System.out.println();
	}

	public static int ktscp(int a) {
		int cp = (int) Math.sqrt(a);
		if (cp * cp == a) {
			return 1;
		} else {
			return 0;
		}

	}

	public static void tach(int a[], int scp[], int kcp[]) {
		int s = 0;
		int k = 0;
		for (int i = 0; i < a.length; i++) {
			if (ktscp(a[i]) == 1) {
				scp[s] = a[i];
				s++;
			} else {
				kcp[k] = a[i];
				k++;
			}
		}
		System.out.print("scp là: ");
		for (int i = 0; i < s; i++) {
			System.out.print(" " + scp[i]);
		}
		System.out.println();
		System.out.print("Số kcp là: ");
		for (int i = 0; i < k; i++) {
			System.out.print(" " + kcp[i]);
		}
		System.out.println();
	}

	public static int[] ghep(int a[], int al, int b[], int bl) {
		int hop[] = new int[al + bl];
		int u = 0;
		for (int i = 0; i < al; i++) {
			hop[u] = a[i];
			u++;
		}
		for (int i = 0; i < bl; i++) {
			hop[u] = b[i];
			u++;
		}
		return hop;
	}

	public static void sapxep(int a[]) {
		int tam;
		for (int i = 0; i < a.length - 1; i++) {
			for (int j = i + 1; j < a.length; j++) {
				if (a[i] > a[j]) {
					tam = a[i];
					a[i] = a[j];
					a[j] = tam;
				}
			}
		}
	}

	public static void chen(int a[]) {
		int dau, cuoi;
		Scanner uu = new Scanner(System.in);
		System.out.println("Nhập đầu cần chèn: ");
		dau = uu.nextInt();
		System.out.println("Nhập cuối cần chèn: ");
		cuoi = uu.nextInt();

		int tam[] = new int[a.length + 2];
		tam[0] = dau;
		tam[tam.length - 1] = cuoi;
		for (int i = 1; i < tam.length - 1; i++) {
			tam[i] = a[i - 1];
		}

	}

	public static void xoa(int a[]) {
		int tam[] = new int[a.length - 2];
		for (int i = 1; i < tam.length; i++) {
			tam[i] = a[i + 1];
		}
	}

	public static void main(String[] args) {
		int a[] = new int[5];
		int scp[] = new int[MAX];
		int kcp[] = new int[MAX];
		input(a);
		output(a);
		max(a);
		min(a);
		snt(a);
		shh(a);
		tach(a, scp, kcp);
		int s = 0, k = 0;
		for (int i = 0; i < a.length; i++) {
			if (ktscp(a[i]) == 1) {
				s++;
			} else {
				k++;
			}
		}
		int[] hopm = ghep(scp, s, kcp, k);
		System.out.println("Mang sau khi ghép là: ");
		for (int i = 0; i < hopm.length; i++) {
			System.out.print(" " + hopm[i]);
		}


		sapxep(a);
		output(a);
		
		xoa(a);
		output(a);
	}

}
