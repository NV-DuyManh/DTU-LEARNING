package sangnguyento2;

import java.util.*;

public class Main {

	void Eratosthene(int n) {
		int count =0;
	    ArrayList<Boolean> a = new ArrayList<>();
	    for (int i = 0; i <= n; i++) a.add(Boolean.TRUE);
	    for (int p = 2; p <= Math.sqrt(n); p++) {
	        if (a.get(p) == true) {
	            int j = p + p;
	            while (j <= n) {
	                a.set(j, Boolean.FALSE); 
	                j = j + p;
	            }
	        }
	    }
	    System.out.println("\nDanh sách các số nguyên tố <= " + n + ":\n");
	    for (int i = 2; i <= n; i++) {
	        if (a.get(i)) 
	        	//System.out.print(" " + i);
	        	count++;
	    }System.out.println("\nSố lượng số nguyên tố: " + count);
	}

	public static void main(String[] args) {
		Main m = new Main();
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhập n: ");
		int n = sc.nextInt();
		m.Eratosthene(n);
		sc.close();
	}
}
