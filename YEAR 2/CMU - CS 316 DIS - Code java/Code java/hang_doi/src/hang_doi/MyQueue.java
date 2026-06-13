package hang_doi;

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
		return data + " ";
	}
}

public class MyQueue {
	Node head, tail;

	MyQueue() {
		head = tail = null;

	}

	boolean EmptyQ() {
		return head == null;
	}

	void add(int x) {
		Node t = new Node(x);
		if (head == null) {
			head = tail = t;
		} else {
			tail.next = t;
			tail = t;
		}
	}

	void nhap() {
		int x = 0;
		head = tail = null;
		Scanner sc = new Scanner(System.in);
		while (true) {
			System.out.print("Nhập nội dung cần nhập: ");
			x = sc.nextInt();
			if (x == 0) {
				break;
			}
			add(x);
		}
	}

	void in() {
		System.out.print("Nội dung đã nhập là: ");
		Node p = head;
		while (p != null) {
			System.out.print(p);
			p = p.next;
		}
	}

	int RemoveQ() {
		int x = 0;
		if (head == null) {
			System.out.println("\nHàng đợi rỗng");

		} else {
			x = head.data;
			if (head.next == null) {
				head = tail = null;
			} else {
				head = head.next;
			}
		}

		return x;
	}

	public static void main(String[] args) {
		MyQueue q = new MyQueue();
		q.add(3);
		q.add(2);
		q.add(7);
		q.add(6);
		q.add(9);
		q.nhap();
		q.in();
		while (!q.EmptyQ()) {
			int x = q.RemoveQ();
			System.out.println(x + " ");
		}
		System.out.println("Xong!");
	}

}
