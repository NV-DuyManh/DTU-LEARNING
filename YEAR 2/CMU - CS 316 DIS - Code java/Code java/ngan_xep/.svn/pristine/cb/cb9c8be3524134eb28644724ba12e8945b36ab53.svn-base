package ngan_xep;

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
		return data + ", ";
	}
}

public class MyStack {
	Node top;

	MyStack() {
		top = null;
	}

	boolean EmptyS() {
		return top == null;
	}

	void Push(int x) {
		top = new Node(x, top);
	}

	int Pop() {
		int x = 0;
		if (top == null) {
			System.out.println("Ngăn xếp rỗng!");
		} else {
			x = top.data;
			top = top.next;
		}

		return x;
	}

	void nhap() {
		int x;
		Scanner sc = new Scanner(System.in);
		while (true) {
			System.out.println("Nhập nội dung: ");
			x = sc.nextInt();
			if (x == 0) {
				break;
			}
			Push(x);
		}
	}

	void in() {
		MyStack t = new MyStack();
		System.out.println("Nội dung ngăn xếp là: ");
		while (!EmptyS()) {
			int x = Pop();
			System.out.println(x + " ");
			t.Push(x);
		}
		while (!t.EmptyS()) {
			int x = t.Pop();
			Push(x);
		}
	}

	int tong() {
		int sum = 0;
		MyStack t = new MyStack();
		int x = 0;
		while (!EmptyS()) {
			x = Pop();
			sum += x;
			t.Push(x);
		}
		while (!t.EmptyS()) {
			x = t.Pop();
			Push(x);
		}

		return sum;
	}
	
	int dem() {
		int count = 0;
		MyStack t = new MyStack();
		int x = 0;
		while(EmptyS()) {
			x = Pop();
			count++;
			t.Push(x);
		}while(!t.EmptyS()) {
			x= t.Pop();
			Push(x);;
		}
		return count ;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyStack s = new MyStack();
		s.Push(5);
		s.Push(6);
		s.Push(7);
		s.Push(8);
		s.Push(9);
		s.nhap();
		System.out.println("Tổng là: " + s.tong());
		System.out.println("Tổng là: " + s.dem());
		s.in();
		while (!s.EmptyS()) {
			System.out.println(s.Pop() + " ");
		}
	}

}
