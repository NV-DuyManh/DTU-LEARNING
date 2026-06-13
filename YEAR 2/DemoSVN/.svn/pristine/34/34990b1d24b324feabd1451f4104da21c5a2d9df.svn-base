package Caynhiphan;

import java.util.*;

class TNode {
	int data;
	TNode left, right;

	TNode(int x) {
		data = x;
		left = right = null;
	}

	TNode(int x, TNode ll, TNode rr) {
		data = x;
		left = ll;
		right = rr;
	}
}

public class MyBinaryTree {
	TNode root;

	void taocayT() {
		TNode A = new TNode(7, new TNode(1), new TNode(6));
		TNode B = new TNode(5, null, new TNode(9));
		root = new TNode(2, A, B);
	}

	void duyet1(TNode T) {
		if (T != null) {
			System.out.print(T.data + " ");
			duyet1(T.left);
			duyet1(T.right);

		}
	}

	void duyettientu() {
		System.out.print("\nTien tu: ");
		duyet1(root);
	}

	void duyet2(TNode T) {
		if (T != null) {
			duyet2(T.left);
			System.out.print(T.data + " ");
			duyet2(T.right);
		}
	}

	void duyettrungtu() {
		System.out.print("\nTrung tu: ");
		duyet2(root);
	}

	void duyet3(TNode T) {
		if (T != null) {
			duyet3(T.left);
			duyet3(T.right);
			System.out.print(T.data + " ");
		}
	}

	void duyethautu() {
		System.out.print("\nHau tu: ");
		duyet3(root);
	}//duyettuan tu
	
	int sonot(TNode T) {
		if(T==null) {
			return 0;
		}else {
			return 1 +sonot(T.left)+sonot(T.right);
		}
	}
	int sn() {
		return sonot(root);
	}
	int tong(TNode T) {
		if(T==null) {
			return 0;
		}else {
			return T.data +tong(T.left)+tong(T.right);
		}
	}//duyet cay
	int tongnot() {
		return tong(root);
	}

	public static void main(String[] args) {
		MyBinaryTree t = new MyBinaryTree();
		t.taocayT();
	//	t.taocayT1();
		t.duyettientu();
		t.duyettrungtu();
		t.duyethautu();
		System.out.println("\nSố nốt trong cây là: "+t.sn());
		System.out.println("\nTổng số nốt trong cây là: "+t.tongnot());
	}
}