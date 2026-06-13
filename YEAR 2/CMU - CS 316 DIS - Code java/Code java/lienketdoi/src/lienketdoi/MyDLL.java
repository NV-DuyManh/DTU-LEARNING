package lienketdoi;

import java.util.*;



class DNode {
	int data;
	DNode next, prev;

	DNode(int x) {
		data = x;
		next = prev = null;
	}

	DNode(int x, DNode s, DNode t) {
		data = x;
		next = s;
		prev = t;
		if (t != null) {
			t.next = this;
			if (s != null) {
				s.prev = this;
			}
		}
	}

	public String toString() {
		return "<--" + data + "-.-.->";
	}
}

public class MyDLL {
	DNode head = null, tail = null;

	void nhap() {
		int x;
		Scanner sc = new Scanner(System.in);
		head = null;
		tail = null;
		while (true) {
			System.out.print("Nhập số cần nhập: ");
			x = sc.nextInt();
			if (x == 0) {
				break;
			}
			DNode t = new DNode(x);
			if (head == null) {
				head = tail = t;
			} else {
				tail.next = t;
				t.prev = tail;
				tail = t;
			}
		}
	}

	void in() {
		System.out.print("Nội dung đã nhâp là: ");
		DNode p = head;
		while (p != null) {
			System.out.print(p);
			p = p.next;
		}
		System.out.println("Null");

//		System.out.print("Nội dung đã nhâp là: ");
//		DNode q = tail;
//		while (q != null) {
//			System.out.print(q);
//			q = q.prev;
//		}
//		System.out.println("Null");

	}

	int tong() {
		int sum = 0;
		DNode p = head;
		while (p != null) {

			sum += p.data;
			p = p.next;

		}
		return sum;
	}

	int dem() {
		int dem = 0;
		DNode p = head;
		while (p != null) {
			if (p.data % 2 != 0) {
				dem++;
			}
			p = p.next;
		}
		return dem;
	}

	 boolean dx() {
	        if (head == null) return true;
	        DNode p = head, q = tail;
	        while (p != null && q != null && p != q && p.prev != q) {
	            if (p.data != q.data) {
	                return false;
	            }
	            p = p.next;
	            q = q.prev;
	        }
	        return true;
	    }


	void timx(int x) {
		DNode p = tail;
		while (p != null && p.data != x) {
			p = p.prev;
		}
		if (p == null) {
			System.out.println("Danh sách không có giá trị " + x);
			
		} else {
			if (p.prev == null) {
				System.out.println("Không có nốt đứng trước " + x);
			} else {
				System.out.println("Nốt đứng trước " + x + " la: " + p.prev.data);
			}
		}

	}

	void xoad() {
		if (head == null) {
			System.out.println();
		} else {
			head = head.next;
		}
	}

	 void xoac() {
	        if (tail == null) {
	            System.out.println("Danh sách rỗng, không thể xóa!");
	            return;
	        }
	        if (head == tail) {
	            head = tail = null;
	            return;
	        }
	        tail = tail.prev;
	        tail.next = null;
	    }

	 void xoak(int k) {
	        if (head == null || k < 0) {
	            System.out.println("Không xóa được!");
	            return;
	        }
	        if (k == 0) {
	            xoad();
	            return;
	        }
	        int vt = 0;
	        DNode p = head;
	        while (p != null && vt < k) {
	            p = p.next;
	            vt++;
	        }
	        if (p == null) {
	            System.out.println("Không xóa được, vị trí không hợp lệ!");
	            return;
	        }
	        if (p.next != null) {
	            p.next.prev = p.prev;
	        } else {
	            tail = p.prev;
	        }
	        if (p.prev != null) {
	            p.prev.next = p.next;
	        } else {
	            head = p.next;
	        }
	    }
	public static void main(String[] args) {
		MyDLL l = new MyDLL();
		l.nhap();
		System.out.println("Tổng là: " + l.tong());
		System.out.println("Tổng số lẻ là: " + l.dem());
		System.out.println("Dãy có đối xứng không? " + l.dx());
		l.timx(3);
		l.xoad();
		l.xoac();
		l.xoak(3);  
		l.in();
		System.out.println("Xong");

	}

}
