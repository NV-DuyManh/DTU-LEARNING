package demo11;

import java.util.*;

import java.io.*;

interface IBOOK{
	double Calculate_Total();
}

abstract class BOOK implements IBOOK{
	private String bookID, publisher, date;
	private double unitPrice,quantity;
	public BOOK(String bookID, String publisher, String date, double unitPrice, double quantity) {
		this.bookID = bookID;
		this.publisher = publisher;
		this.date = date;
		this.unitPrice = unitPrice;
		this.quantity = quantity;
	}
	public BOOK() {
	
	}
	public String getBookID() {
		return bookID;
	}
	public void setBookID(String bookID) {
		this.bookID = bookID;
	}
	public String getPublisher() {
		return publisher;
	}
	public void setPublisher(String publisher) {
		this.publisher = publisher;
	}
	public String getDate() {
		return date;
	}
	public void setDate(String date) {
		this.date = date;
	}
	public double getUnitPrice() {
		return unitPrice;
	}
	public void setUnitPrice(double unitPrice) {
		this.unitPrice = unitPrice;
	}
	public double getQuantity() {
		return quantity;
	}
	public void setQuantity(double quantity) {
		this.quantity = quantity;
	}
	public abstract double Calculate_Discount();
	void input () {
		Scanner q = new Scanner(System.in);
		System.out.println("Enter bookID: ");
		this.setBookID(q.nextLine());
		System.out.println("Enter publisher: ");
		this.setPublisher(q.nextLine());
		System.out.println("Enter date: ");
		this.setDate(q.nextLine());
		System.out.println("Enter unitPrice: ");
		this.setUnitPrice(q.nextDouble());
		System.out.println("Enter quantity: ");
		this.setQuantity(q.nextDouble());
	}
	void output() {
		System.out.println(" bookID: "+this.getBookID());
		
		System.out.println(" publisher: "+this.getPublisher());

		System.out.println(" date: "+this.getDate());
		
		System.out.println(" unitPrice: "+this.unitPrice);
		
		System.out.println(" quantity: "+this.quantity);
		
	}
}

class TEXTBOOK extends BOOK{
	public String status;

	
	public String getStatus() {
		return status;
	}


	public void setStatus(String status) {
		this.status = status;
	}


	public TEXTBOOK() {
	
	}

	public TEXTBOOK(String bookID, String publisher, String date, double unitPrice, double quantity, String status) {
		super(bookID, publisher, date, unitPrice, quantity);
		this.status = status;
	}


	public double Calculate_Total() {
		
		return this.getQuantity()*this.getUnitPrice()-this.Calculate_Discount();
	}


	public double Calculate_Discount() {
		
		if(this.getStatus().equals("new")) {
			return this.getQuantity()*this.getUnitPrice()*10/100;
		}else {
			return this.getQuantity()*this.getUnitPrice()*50/100;
		}
	}
	void input() {
		super.input();
		Scanner w = new Scanner(System.in);
		System.out.println("Enter status: ");
		this.setStatus(w.nextLine());
	}
	void output() {
		super.output();
		System.out.println(" status: "+this.getStatus());
	}
	
}
class REFERENCE_BOOK extends BOOK{
public double tax;

	
	public REFERENCE_BOOK(String bookID, String publisher, String date, double unitPrice, double quantity, double tax) {
	super(bookID, publisher, date, unitPrice, quantity);
	this.tax = tax;
}
	public REFERENCE_BOOK() {
	
	}


	public double Calculate_Total() {
		
		return this.getQuantity()*this.getUnitPrice()+this.getTax()-this.Calculate_Discount();
	}

	
	public double getTax() {
		return tax;
	}
	public void setTax(double tax) {
		this.tax = tax;
	}
	public double Calculate_Discount() {
		
		return this.getQuantity()*this.getUnitPrice()*5/100;
	}
	void input() {
		super.input();
		Scanner w = new Scanner(System.in);
		System.out.println("Enter tax: ");
		this.setTax(w.nextDouble());
	}
	void output() {
		super.output();
		System.out.println(" tax: "+this.getTax());
	}
	
}
class BOOKLIST{
	ArrayList<BOOK> list=new ArrayList<BOOK>();
	int n;
	char chon,loai;
	void inputlist() throws IOException{
		do {
			BOOK a[] = new BOOK[100];
			System.out.println("TextBook or ReferenceBook(T/R)");
			chon=(char)System.in.read();
			if(chon=='t'||chon=='T') {
				a[n]= new TEXTBOOK();
			}else {
				a[n]= new REFERENCE_BOOK();
				
			}
			list.add(a[n]);
			System.in.skip(chon);
			a[n++].input();
			System.out.println("Tiếp tục(C/K");
			loai =(char)System.in.read();
			System.in.skip(loai);
			if(loai=='k'||loai=='K') {
				break;
			}
		}while(true);
	}
	void outputlist() {
		for (int i=0;i<list.size();i++) {
			list.get(i).output();
		}
	}
	void delete(String bookId) {
		for (int i=0;i<list.size();i++) {
			if(list.get(i).getBookID().contains(bookId));
			list.remove(i);
			}
	}
	void find(String bookId) {
		int k=0;
		for(int i=0;i<list.size();i++) {
			if(list.get(i).getBookID().contains(bookId)){
			k=i;
			System.out.println("Co");
			break;
			}
			
			else {
				System.out.println("Khong co");
			}
		}
	}
}


public class zzzz {
    public static void main(String[] args) throws IOException {
    	BOOKLIST g = new BOOKLIST();
    	g.inputlist();
    	g.outputlist();
    	String id;
    	Scanner e = new Scanner(System.in);
    	System.out.println("Nhap tvid: ");
    	id = e.nextLine();
    	g.find(id);
    	System.out.println("Nhap tvid: ");
    	id = e.nextLine();
    	g.delete(id);
    	g.outputlist();
	}
}