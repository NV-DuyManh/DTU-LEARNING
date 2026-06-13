package sach;

import java.util.*;
import java.io.*;

interface IBOOK {
	double Calculate_Total();
}

abstract class BOOK implements IBOOK {
	public String bookID, publisher;
	public double unitPrice, quantity;
	public String entryDate;

	public BOOK() {
	}

	public BOOK(String bookID, String publisher, String entryDate, double unitPrice, double quantity) {
		this.bookID = bookID;
		this.publisher = publisher;
		this.entryDate = entryDate;
		this.unitPrice = unitPrice;
		this.quantity = quantity;
	}

	public String getBookID() {
		return this.bookID;
	}

	public String getPublisher() {
		return this.publisher;
	}

	public String getEntryDate() {
		return this.entryDate;
	}

	public double getUnitPrice() {
		return this.unitPrice;
	}

	public double getQuantity() {
		return this.quantity;
	}

	public void setBookID(String bookID) {
		this.bookID = bookID;
	}

	public void setPublisher(String publisher) {
		this.publisher = publisher;
	}

	public void setEntryDate(String entryDate) {
		this.entryDate = entryDate;
	}

	public void setUnitPrice(double unitPrice) {
		this.unitPrice = unitPrice;
	}

	public void setQuantity(double quantity) {
		this.quantity = quantity;
	}

	public abstract double Calculate_Discount();

	public void Input() {
		Scanner s = new Scanner(System.in);
		System.out.print("Enter book ID: ");
		this.bookID = s.nextLine();
		System.out.print("Enter publisher: ");
		this.publisher = s.nextLine();
		System.out.print("Enter entry date: ");
		this.entryDate = s.nextLine();
		System.out.print("Enter unit price: ");
		this.unitPrice = s.nextDouble();
		System.out.print("Enter quantity: ");
		this.quantity = s.nextDouble();
	}

	public void Output() {
		System.out.println("Book ID: " + bookID);
		System.out.println("Publisher: " + publisher);
		System.out.println("Entry Date: " + entryDate);
		System.out.println("Unit Price: " + unitPrice);
		System.out.println("Quantity: " + quantity);
	}
}

class TEXTBOOK extends BOOK {
	public String status;

	public TEXTBOOK(String bookID, String publisher, String entryDate, double unitPrice, double quantity,
			String status) {
		super(bookID, publisher, entryDate, unitPrice, quantity);
		this.status = status;
	}

	public TEXTBOOK() {
	}

	public String getStatus() {
		return this.status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	public double Calculate_Discount() {
		if (this.status.equals("new")) {
			return this.quantity * this.unitPrice * 10 / 100;
		} else {
			return this.quantity * this.unitPrice * 50 / 100;
		}
	}

	public double Calculate_Total() {
		return (this.quantity * this.unitPrice) - this.Calculate_Discount();
	}

	public void Input() {
		super.Input();
		Scanner x = new Scanner(System.in);
		System.out.print("Enter status: ");
		this.status = x.nextLine();
	}

	public void Output() {
		super.Output();
		System.out.println("Status: " + status);
	}
}

class REFERENCE_BOOK extends BOOK {
	public double tax;

	public REFERENCE_BOOK(String bookID, String publisher, String entryDate, double unitPrice, double quantity,
			double tax) {
		super(bookID, publisher, entryDate, unitPrice, quantity);
		this.tax = tax;
	}

	public REFERENCE_BOOK() {
	}

	public double getTax() {
		return this.tax;
	}

	public void setTax(double tax) {
		this.tax = tax;
	}

	public double Calculate_Discount() {
		return this.quantity * this.unitPrice * 5 / 100;
	}

	public double Calculate_Total() {
		return (this.quantity * this.unitPrice) + this.tax - this.Calculate_Discount();
	}

	public void Input() {
		super.Input();
		Scanner d = new Scanner(System.in);
		System.out.print("Enter tax: ");
		this.tax = d.nextDouble();
	}

	public void Output() {
		super.Output();
		System.out.println("Tax: " + tax);
	}
}

class BOOKLIST {
	BOOK a[] = new BOOK[100];
	int n;

	public void AddNew() throws IOException {

		Scanner e = new Scanner(System.in);
		System.out.println("Enter book type (T for Textbook, R for Reference Book): ");
		char type = (char) System.in.read();
		e.nextLine();

		if (type == 'T' || type == 't') {
			TEXTBOOK textbook = new TEXTBOOK();
			textbook.Input();
			a[n++] = textbook;
		} else if (type == 'R' || type == 'r') {
			REFERENCE_BOOK referenceBook = new REFERENCE_BOOK();
			referenceBook.Input();
			a[n++] = referenceBook;
		} else {
			System.out.println("Invalid book type!");
		}
	}

	public void Delete() {
		Scanner z = new Scanner(System.in);
		System.out.print("Enter index of book to delete: ");
		int tam = z.nextInt();
		if (tam >= 0 && tam < n) {
			for (int i = tam; i < n - 1; i++) {
				a[i] = a[i + 1];
			}
			n--;
		} else {
			System.out.println("Invalid index");
		}
	}

	public void sort() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i].Calculate_Discount() < a[j].Calculate_Total()) {
					BOOK tam = a[i];
					a[i] = a[j];
					a[j] = tam;
				}
			}
		}
		System.out.println("Books after sort: ");
		for (int i = 0; i < n; i++) {
			a[i].Output();
		}
	}

	public double Calculate_TotalAmount() {
		double sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i].Calculate_Total();
		}
		System.out.println("Total cost of books: " + sum);
		return sum;
	}

	public void DisplayBooks() {
		for (int i = 0; i < n; i++) {
			a[i].Output();
			System.out.println("Total: " + a[i].Calculate_Total());
		}
	}
}

public class Sach {
	public static void main(String[] args) throws IOException {
		BOOKLIST t = new BOOKLIST();
		Scanner q = new Scanner(System.in);
		int choice;

		do {
			System.out.println("1. Add new book");
			System.out.println("2. Delete a book");
			System.out.println("3. Display books");
			System.out.println("4. Sort books");
			System.out.println("5. Calculate total cost");
			System.out.println("6. Exit");
			System.out.print("Enter your choice: ");
			choice = q.nextInt();

			switch (choice) {
			case 1:
				t.AddNew();
				break;
			case 2:
				t.Delete();
				break;
			case 3:
				t.DisplayBooks();
				break;
			case 4:
				t.sort();
				break;
			case 5:
				t.Calculate_TotalAmount();
				break;
			case 6:
				System.out.println("Exiting...");
				break;
			default:
				System.out.println("Invalid choice! Please try again.");
			}
		} while (choice != 6);
	}
}