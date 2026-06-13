package myproject;
import java.util.Scanner;

public class sosanh {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Nhap so luong chu so: ");
        int n = input.nextInt();
        int[] numbers = new int[n];

        // Nhập các chữ số
        for (int i = 0; i < n; i++) {
            System.out.println("Nhap chu so thu " + (i + 1) + ": ");
            numbers[i] = input.nextInt();
        }

        // So sánh các chữ số
        int max = numbers[0];
        int min = numbers[0];
        for (int i = 1; i < n; i++) {
            if (numbers[i] > max) {
                max = numbers[i];
            }
            if (numbers[i] < min) {
                min = numbers[i];
            }
        }

        System.out.println("Chu so lon nhat la: " + max);
        System.out.println("Chu so nho nhat la: " + min);
    }
}
