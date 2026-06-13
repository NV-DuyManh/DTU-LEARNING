package OOP;

class area {

	public int w, h;

	area() {
		this.w = 0;
		this.h = 0;
	}

	area(int w, int h) {
		this.w = w;
		this.h = h;
	}

	int calArea() {
		return w * h;
	}
}

public class www {

	public static void main(String[] args) {

		area objA1 = new area();
		System.out.println("Dien tich: " + objA1.calArea());

		area objA2 = new area(10, 20);
		System.out.println("Dien tich: " + objA2.calArea());
	}
}
