package demo1;

import java.util.*;


public class Main {
    int a[][];
    int m, n;

    void nhap() {
        Scanner kb = new Scanner(System.in);
        System.out.println("Nhap so hang:");
        m = kb.nextInt();
        System.out.println("Nhap so cot:");
        n = kb.nextInt();
        a = new int[m][n];
        System.out.println("Nhap cac phan tu:");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = kb.nextInt();
            }
        }
    }

    void in() {
        System.out.println("Mang hai chieu:");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.format("%5d", a[i][j]);
            }
            System.out.println();
        }
    }

    void Max() {
        System.out.println("Gia tri lon nhat cua tung cot:");
        for (int j = 0; j < n; j++) {
            int max = Integer.MIN_VALUE;
            for (int i = 0; i < m; i++) {
                if (a[i][j] > max) {
                    max = a[i][j];
                }
            }
            System.out.print(max + " ");
        }
        System.out.println();
    }

    void TBC() {
        System.out.println("Trung binh cong cac so le cua tung dong:");
        for (int i = 0; i < m; i++) { 
            int sumOdd = 0; 
            int countOdd = 0;
            for (int j = 0; j < n; j++) { 
                if (a[i][j] % 2 != 0) { 
                    sumOdd += a[i][j];
                    countOdd++;
                }
            }
            double avg; 
            if (countOdd > 0) {
                avg = (double) sumOdd / countOdd;
            } else {
                avg = 0.0; 
            }
            System.out.printf("%.1f ", avg); 
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Main m = new Main();
        m.nhap();
        m.in();
        m.Max();
        m.TBC ();
    }
}
