package review2;

import java.util.Scanner;

public class review2 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int attempts = 3;

		while (attempts > 0) {
			System.out.print("Nhập tên người dùng: ");
			String username = scanner.nextLine();

			System.out.print("Nhập mật khẩu: ");
			String password = scanner.nextLine();

			if (authenticate(username, password)) {
				System.out.println("Đăng nhập thành công!");
			} else {
				attempts--;
				System.out.println("Đăng nhập thất bại! Còn " + attempts + " lần thử.");
			}
		}
		System.out.println("Bạn đã nhập sai quá số lần cho phép. Tài khoản bị khóa tạm thời.");
		scanner.close();
	}

	public static boolean authenticate(String username, String password) {
		if ("admin".equals(username) && "123".equals(password)) {
			return true;
		}
		if (username == null || password == null || username.isEmpty() || password.isEmpty()) { 												
			System.out.println("Lỗi: Tên người dùng hoặc mật khẩu không được để trống!");
			return false;
		}
		if ("guest".equals(username)) {
			System.out.println("Tài khoản khách không có quyền truy cập!");
			return false;
		}
		System.out.println("Cảnh báo: Đăng nhập thất bại cho tài khoản " + username);
		return false;
	}
}
