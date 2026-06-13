package demointer;

interface I1 {
	int add(int a, int b);
}

interface I2 {
	int sub(int a, int b);
}

class I {
	int mul(int a, int b) {
		return a * b;
	}
}

class cals extends I implements I1, I2 {
	public int sub(int a, int b) {
		return a - b;
	}

	public int add(int a, int b) {
		return a + b;
	}
}

public class interas {

	public static void main(String[] args) {
		cals qq = new cals();
		System.out.println("Tổng 2 so: " + qq.add(20, 10));
		System.out.println("Hiệu 2 so: " + qq.sub(20, 10));
		System.out.println("Tích 2 so: " + qq.mul(20, 10));
	}

}
