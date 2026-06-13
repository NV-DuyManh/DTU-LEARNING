package Node2;

import java.util.*;

class Node {
	int data;
	Node next;

	Node(int x) {
		data = x;
		next = null;
	}

	Node(int x, Node t) {
		data = x;
		next = t;
	}

	public String toString() {
		return data + "-->";
	}
}

public class MySLL {
	Node head = null;

	void nhap() {
		int x;
		Scanner s = new Scanner(System.in);
		Node cuoi = null;
		head = null;
		while (true) {
			System.out.print("Nhap noi dung: ");
			x = s.nextInt();
			if (x == 0) {
				break;
			}
			Node t = new Node(x);
			if (head == null) {
				cuoi = head = t;
			} else {
				cuoi.next = t;
				cuoi = t;
			}
		}
	}

	void in() {
		System.out.print("Noi dung danh sach:");
		Node p = head;
		while (p != null) {
			System.out.print(p);
			p = p.next;
		}
		System.out.println("null\n");
	}

	int tong() {
		int sum = 0;
		Node p = head;
		while (p != null) {
			if (p.data % 2 == 0) {
				sum += p.data;
			}
			p = p.next;
		}
		return sum;
	}

	int maxds() {
		int max = 0;
		Node p = head;
		if (p == null) {
			System.out.println("DS trong!");
			return 0;
		} else {

			int m = p.data;
			while (p != null) {
				if (p.data > max)
					m = p.data;
				p = p.next;
			}
			return m;
		}
	}

	boolean timx(int x) {
		Node p = head;
		while (p != null) {
			if (p.data == x) {
				return true;
			}
			p = p.next;
		}
		return false;
	}

	void hoanvi() {
		if (head == null || head.next == null) {
			return;
		}
		Node n2 = head.next;
		head.next = n2.next;
		n2.next = head;
		head = n2;
	}

	void inkecuoi() {
		if (head == null || head.next == null) {
			System.out.println("Khong co not ke cuoi");
			return;
		}
		Node p = head;
		while (p.next.next != null) {
			p = p.next;
		}
		System.out.println("Not ke cuoi la: " + p.data);
	}

	boolean tang() {
		Node p = head;
		while (p != null & p.next != null) {
			if (p.data > p.next.data) {
				return false;
			}
			p = p.next;
		}
		return true;
	}

	void sapxep() {
		if (head == null || head.next == null) {
			return;
		}
		boolean swap;
		do {
			swap = false;
			Node p = head;
			while (p.next != null) {
				if (p.data > p.next.data) {
					int temp = p.data;
					p.data = p.next.data;
					p.next.data = temp;
					swap = true;
				}
				p = p.next;
			}
		} while (swap);
	}

	void chen(int x) {
		Node t = new Node(x);
		if (head == null || head.data >= x) {
			t.next = head;
			head = t;
			return;
		}
		Node p = head;
		while (p.next != null && p.next.data < x) {
			p = p.next;
		}
		t.next = p.next;
		p.next = t;
	}

	public static void main(String[] args) {
	
		MySLL l = new MySLL();
		l.nhap();
		l.in();
		System.out.println("Tong cac so chan la: " + l.tong());
		System.out.println("Max trong danh sach la: " + l.maxds());
		Scanner s = new Scanner(System.in);
		System.out.print("Nhap gia tri can tim: ");
		int x = s.nextInt();
		System.out.println(" Co ton tai " + x + " khong: " + l.timx(x));
		l.hoanvi();
		System.out.print("Sau khi hoan vi not thu nhat va not thu nhi: ");
		l.in();
		l.inkecuoi();
		System.out.println("Danh sach tang dan khong: " + l.tang());
		l.sapxep();
		System.out.print("Sau khi sap xep tang dan: ");
		l.in();
		System.out.print("Nhap gia tri can chen vao danh sach: ");
		int y = s.nextInt();
		l.chen(y);
		System.out.print("Danh sach sau khi chen: ");
		l.in();
	}

}
