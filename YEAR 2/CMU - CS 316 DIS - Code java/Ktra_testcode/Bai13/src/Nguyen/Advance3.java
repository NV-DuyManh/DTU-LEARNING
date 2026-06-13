package Nguyen;

public class Advance3 {
	/**
	 * Tính số fibonacci thứ n
	 * 
	 * @param n: chỉ số của số fibonacci tính từ 0 vd: F0 = 0, F1 = 1, F2 = 1, F3 =2
	 * @return số fibonacci thứ n, nếu không có trả về =-1
	 */
	public int fibonacci(int n) {
		if (n < 0) {
			return -1;
		} else if (n == 0 || n == 1) {
			return n;
		} else {
			return fibonacci(n - 1) + fibonacci(n - 2);
		}
	}
}