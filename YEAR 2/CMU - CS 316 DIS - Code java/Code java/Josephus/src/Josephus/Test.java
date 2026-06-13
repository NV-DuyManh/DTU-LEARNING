package Josephus;

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

class MyQueue {
	Node head, tail;

	MyQueue() {
		head = tail = null;

	}

	boolean EmptyQ() {
		return head == null;
	}

	void AddQ(int x) {
		Node t = new Node(x);
		if (head == null) {
			head = tail = t;
		} else {
			tail.next = t;
			tail = t;
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
}

public class Test {
	void Josephus(int n, int k) {
		MyQueue Q = new MyQueue();
		for (int i = 1; i <= n; i++) {
			Q.AddQ(i);
		}
		int d = 0, vt = 1;
		while (d < n - 1) {
			int x = Q.RemoveQ();
			if (vt < k) {
				vt++;
				Q.AddQ(x);
			} else {
				d++;
				vt = 1;
			}
		}
		System.out.println("\nVua la: " + Q.RemoveQ());
	}

	public static void main(String[] args) {
		
		Test m = new Test();
		m.Josephus(16, 4);
		m.Josephus(137, 7);
	}

}
