package gg;

import java.util.*;

public class mang {
    int a[][]; // Khai báo mảng 2 chiều
    int m, n;  // Số hàng và số cột

    void nhap() {
        Scanner kb = new Scanner(System.in);
        System.out.println("Nhap so hang");
        m = kb.nextInt();
        System.out.println("Nhap so cot");
        n = kb.nextInt();
        a = new int[m][n]; // Khởi tạo mảng 2 chiều
        Random rd = new Random();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = kb.nextInt(); // Nhập từng phần tử của mảng
            }
        }
    }

    void in() {
        for (int i = 0; i < m; i++) {
            System.out.println("\n");
            for (int j = 0; j < n; j++) {
                System.out.format("%5d", a[i][j]); // Sửa định dạng từ %5.2f thành %5d để in số nguyên
            }
        }
        System.out.println(); // Đảm bảo xuống dòng sau khi in toàn bộ mảng
    }

    public static void main(String[] args) {
        mang m = new mang();
        m.nhap(); // Nhập mảng
        m.in();   // In mảng
    }
}
