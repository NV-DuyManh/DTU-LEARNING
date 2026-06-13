package g;
import java.io.*;
import java.util.*;

public class Main {
	int [][]a; int m,n;
	void nhap() {
		Scanner in = new Scanner(System.in);
	 m = in.nextInt();
	 n = in.nextInt();
		a = new int[m][n];
		for (int i=0;i<m;i++) {
			for (int j=0;j<n;j++) {
				a[i][j] = in.nextInt();
			}
		}
	}
	void in() {
		for (int j=0;j<n;j++) {
			int max = a[0][j];
			for (int i=0;i<m;i++) {
				if (a[i][j] > max) {
					max = a[i][j];
				}
			}
			System.out.print(max +" ");
		}
		System.out.print("\n");
		for (int i=0; i<m;i++) {
			float k=0; int l=0;
			for (int j=0;j<n;j++) {
				if(a[i][j]%2!=0) {
					k+=a[i][j];
					l++;
				}
			}
			if (l > 0) {
                System.out.printf("%.1f ", k/l);
            } else {
                System.out.printf("%.1f ", 0.0);
            }
	}}
	public static void main(String[] args) {
		Main m = new Main();
		m.nhap();m.in();
	}
}
