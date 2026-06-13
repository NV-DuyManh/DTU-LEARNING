package demodao;
import java.util.*;

public class demodao {
	public static void input(int a[]) {
		Scanner in = new Scanner(System.in);
		for (int i = 0; i < a.length; i++) {
			System.out.print("a[" + i + "]=");
			a[i] = in.nextInt();
		}
	}

	public static void output(int a[]) {
		System.out.print("Dãy số sau khi đảo: ");
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
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

    public static void main(String[] args) {
    	int a[] = new int[4];
    	input(a);
    	daonguoc(a);
    	output(a);
}
}