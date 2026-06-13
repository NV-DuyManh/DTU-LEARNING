package sangnguyento;

import java.util.*;

public class code2 {

	boolean nguyento(int x) {
		if (x < 2) {
			return false;
		}

		for (int i = 2; i <= Math.sqrt(x); i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}

	void lietke_nguyento(int n) {
		int count = 0;
		System.out.println("\nCác số nguyên tố <= " + n + ":");
		for (int i = 2; i <= n; i++) {
			if (nguyento(i)) {
				
				count++;
			}
		}
		System.out.println("\nSố lượng số nguyên tố: " + count);
	}

	public static void main(String[] args) {
		code2 m = new code2();
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhập n: ");
		int n = sc.nextInt();
		m.lietke_nguyento(n);
		sc.close();
	}
}
