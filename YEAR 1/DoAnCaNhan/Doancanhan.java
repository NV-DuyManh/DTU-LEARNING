package doancanhan;

import java.util.*;

import java.io.*;

interface IBOOK {
	final static int MONEY_SERVE = 10000;

	double calculatePrice();

	double discount();
}

abstract class BOOK implements IBOOK {
	private int number;
	private String title;
	private String author;
	private String publish;
	private int day;
	private int month;
	private int year;
	private int warrantyYears;
	private String rating;
	private String type;
	private String status;
	private String export;
	private int quantity;
	private boolean isExported;
	private float price;
	private float weight;

	public BOOK() {
		this.number = 0;
		this.title = "";
		this.author = "";
		this.publish = "";
		this.day = 0;
		this.month = 0;
		this.year = 0;
		this.warrantyYears = 0;
		this.rating = "";
		this.type = "";
		this.status = "";
		this.export = "";
		this.quantity = 0;
		this.isExported = false;
		this.price = 0;

	}

	public BOOK(int number, String title, String author, String publish, int day, int month, int year,
			int warrantyYears, String rating, String type, String status, String export, int quantity,
			boolean isExported, float price, float weight) {
		super();
		this.number = number;
		this.title = title;
		this.author = author;
		this.publish = publish;
		this.day = day;
		this.month = month;
		this.year = year;
		this.warrantyYears = warrantyYears;
		this.rating = rating;
		this.type = type;
		this.status = status;
		this.export = export;
		this.quantity = quantity;
		this.isExported = isExported;
		this.price = price;
		this.weight = weight;
	}

	public int getNumber() {
		return number;
	}

	public void setNumber(int number) {
		this.number = number;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getAuthor() {
		return author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public String getPublish() {
		return publish;
	}

	public void setPublish(String publish) {
		this.publish = publish;
	}

	public int getDay() {
		return day;
	}

	public void setDay(int day) {
		this.day = day;
	}

	public int getMonth() {
		return month;
	}

	public void setMonth(int month) {
		this.month = month;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public int getWarrantyYears() {
		return warrantyYears;
	}

	public void setWarrantyYears(int warrantyYears) {
		this.warrantyYears = warrantyYears;
	}

	public String getRating() {
		return rating;
	}

	public void setRating(String rating) {
		this.rating = rating;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	public String getExport() {
		return export;
	}

	public void setExport(String export) {
		this.export = export;
	}

	public int getQuantity() {
		return quantity;
	}

	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}

	public boolean getisExported() {
		return isExported;
	}

	public void setisExported(boolean isExported) {
		this.isExported = isExported;
	}

	public float getPrice() {
		return price;
	}

	public void setPrice(float price) {
		this.price = price;
	}

	public float getWeight() {
		return weight;
	}

	public void setWeight(float weight) {
		this.weight = weight;
	}

	public void input() {
		Scanner q = new Scanner(System.in);
		System.out.println("Enter number: ");
		this.setNumber(q.nextInt());
		q.nextLine();
		System.out.println("Enter title: ");
		this.setTitle(q.nextLine());
		System.out.println("Enter author: ");
		this.setAuthor(q.nextLine());
		System.out.println("Enter publish: ");
		this.setPublish(q.nextLine());
		int iday, imonth, iyear;
		do {
			System.out.println("Enter year: ");
			iyear = q.nextInt();
			if (iyear < 1700 || iyear > 2999) {
				System.out.println("Try again!");
			} else {
				do {
					System.out.println("Enter month: ");
					imonth = q.nextInt();
					if (imonth <= 0 || imonth > 12) {
						System.out.println("Try again!");
					} else {
						boolean checkDay = false;
						do {
							System.out.println("Enter day: ");
							iday = q.nextInt();
							if (iday <= 0 || iday > 31) {
								System.out.println("Try again!");
							} else if ((imonth == 2 && iday > 29)
									|| ((imonth == 4 || imonth == 6 || imonth == 9 || imonth == 1) && iday > 30)) {
								System.out.println("Try again!");
							} else {
								checkDay = true;
								day = iday;
								month = imonth;
								year = iyear;
							}
						} while (!checkDay);
					}
				} while (imonth <= 0 || imonth > 12);
			}
		} while (iyear < 1700 || iyear > 2999);
		System.out.println("Enter warranty period in years: ");
		this.setWarrantyYears(q.nextInt());
		q.nextLine();
		System.out.println("Enter rating (high or low): ");
		this.setRating(q.nextLine());
		System.out.println("Enter type: ");
		this.setType(q.nextLine());
		System.out.println("Enter status (new or old): ");
		this.setStatus(q.nextLine());
		System.out.println("Enter export: ");
		this.setExport(q.nextLine());
		System.out.println("Enter quantity: ");
		this.setQuantity(q.nextInt());
		q.nextLine();
		while (true) {
			System.out.println("Enter isExported (true or false): ");
			if (q.hasNextBoolean()) {
				this.setisExported(q.nextBoolean());
				break;
			} else {
				System.out.println("Invalid input, please enter true or false.");
				q.next();
			}
		}
		q.nextLine();
		System.out.println("Enter price: ");
		this.setPrice(q.nextFloat());
		System.out.println("Enter weight: ");
		this.setWeight(q.nextFloat());
		q.nextLine();
	}

	public void output() {
		System.out.println(" Number: " + this.getNumber());
		System.out.println(" Title: " + this.getTitle());
		System.out.println(" Author: " + this.getAuthor());
		System.out.println(" Publish: " + this.getPublish());
		System.out.println(" Day: " + this.getDay());
		System.out.println(" Month: " + this.getMonth());
		System.out.println(" Year: " + this.getYear());
		System.out.println(" Rating: " + this.getRating());
		System.out.println(" Type: " + this.getType());
		System.out.println(" Status: " + this.getStatus());
		System.out.println(" Export: " + this.getExport());
		System.out.println(" Quantity: " + this.getQuantity());
		System.out.println(" IsExported: " + this.getisExported());
		System.out.println(" Price: " + this.getPrice());
		System.out.println(" Weight: " + this.getWeight());
		System.out.println(" Purchase date: " + day + "/" + month + "/" + year);
		System.out.println(" Warranty status: " + checkwarranty());
		System.out.print(" Book condition: ");
		checkCondition();
		System.out.println();

	}

	public abstract double calculatePrice();

	public abstract double discount();

	public abstract void checkBookType();

	public String checkwarranty() {
		Calendar currentDate = Calendar.getInstance();
		int currentYear = currentDate.get(Calendar.YEAR);
		int currentMonth = currentDate.get(Calendar.MONTH) + 1;
		int currentDay = currentDate.get(Calendar.DAY_OF_MONTH);

		int yearsElapsed = currentYear - year;
		int monthsElapsed = currentMonth - month;
		int daysElapsed = currentDay - day;

		if (monthsElapsed < 0) {
			yearsElapsed--;
			monthsElapsed += 12;
		}

		if (daysElapsed < 0) {
			monthsElapsed--;

			currentDate.add(Calendar.MONTH, -1);
			daysElapsed += currentDate.getActualMaximum(Calendar.DAY_OF_MONTH);
		}

		System.out.println(
				"Elapsed time: " + yearsElapsed + " years, " + monthsElapsed + " months, " + daysElapsed + " days.");

		if (yearsElapsed < warrantyYears || (yearsElapsed == warrantyYears && monthsElapsed <= 0 && daysElapsed <= 0)) {
			return "Warranty is still valid.";
		} else {
			return "Warranty expired.";
		}
	}

	public void checkCondition() {
		if (this.getQuantity() == 0) {
			status = "Out of Stock";
		} else if (this.getQuantity() < 10) {
			status = "Low Stock";
		} else {
			status = "In Stock";
		}
	}

	public void updateQuantity() {
		Scanner s = new Scanner(System.in);
		int quantityInStock;
		System.out.println("Enter quantityInStock: ");
		quantityInStock = s.nextInt();
		this.quantity += quantityInStock;
		checkCondition();
	}

}

class TEXTBOOK extends BOOK {

	public String subject;
	public int level;
	public String version;
	public String education_level;
	public float tax;

	public TEXTBOOK() {
		this.subject = "";
		this.level = 0;
		this.version = "";
		this.tax = 0;
		this.education_level = "";
	}

	public TEXTBOOK(int number, String title, String author, String publish, int day, int month, int year,
			int warrantyYears, String rating, String type, String status, String export, int quantity,
			boolean isExported, float price, float weight, String subject, int level, String version, float tax,
			String education_level) {
		super(number, title, author, publish, day, month, year, warrantyYears, rating, type, status, export, quantity,
				isExported, price, weight);
		this.subject = subject;
		this.level = level;
		this.version = version;
		this.tax = tax;
		this.education_level = education_level;
	}

	public String getSubject() {
		return subject;
	}

	public void setSubject(String subject) {
		this.subject = subject;
	}

	public int getLevel() {
		return level;
	}

	public void setLevel(int level) {
		this.level = level;
	}

	public String getVersion() {
		return version;
	}

	public void setVersion(String version) {
		this.version = version;
	}

	public float getTax() {
		return tax;
	}

	public void setTax(float tax) {
		this.tax = tax;
	}

	public String getEducation_level() {
		return education_level;
	}

	public void setEducation_level(String education_level) {
		this.education_level = education_level;
	}

	public void input() {
		super.input();
		Scanner q = new Scanner(System.in);
		System.out.println("Enter subject: ");
		this.setSubject(q.nextLine());
		System.out.println("Enter level: ");
		this.setLevel(q.nextInt());
		q.nextLine();
		System.out.println("Enter version: ");
		this.setVersion(q.nextLine());
		System.out.println("Enter education_level: ");
		this.setEducation_level(q.nextLine());
		System.out.println("Enter tax: ");
		this.setTax(q.nextFloat());
		updateQuantity();
	}

	public void output() {
		super.output();
		System.out.println(" Subject: " + this.getSubject());
		System.out.println(" Level: " + this.getLevel());
		System.out.println(" Version: " + this.getVersion());
		System.out.println(" Education_level: " + this.getEducation_level());
		System.out.println(" Tax: " + this.getTax());
	}

	public double calculatePrice() {

		return this.MONEY_SERVE + this.getPrice() * this.getQuantity() + this.applyTax() - this.discount();
	}

	public double discount() {
		double discountRate = 0;

		if (this.getStatus().equals("new")) {
			discountRate = 0.10;
		} else if (this.getStatus().equals("old")) {
			discountRate = 0.50;
		} else {
			discountRate = 0.05;
		}

		if (this.getQuantity() > 100) {
			discountRate += 0.05;
		}

		if (this.getRating().equals("high")) {
			discountRate += 0.03;
		} else if (this.getRating().equals("low")) {
			discountRate -= 0.02;
		}

		return this.getQuantity() * this.getPrice() * discountRate;
	}

	public void checkBookType() {
		String[] naturalSciences = { "math", "physic", "chemistry", "biology", "astronomy", "geology" };
		String[] socialSciences = { "history", "sociology", "psychology", "economic", "science", "Anthropology" };

		this.setType("Other");

		for (String science : naturalSciences) {
			if (science.equalsIgnoreCase(subject)) {
				this.setType("Natural Sciences");
				break;
			}
		}

		for (String social : socialSciences) {
			if (social.equalsIgnoreCase(subject)) {
				this.setType("Social Sciences");
				break;
			}
		}

		System.out.println("Book Type: " + this.getType());
	}

	public double applyTax() {

		if (this.getWeight() > 10 && this.getWeight() < 50) {
			return this.getPrice() * this.getTax() / 100;
		} else if (this.getWeight() >= 50) {
			return this.getPrice() * (this.getTax() / 100) * (this.getWeight() - 49);
		} else {
			return 0;
		}

	}

}

class REFERENCE_BOOK extends BOOK {
	public String ISBN;
	public String topic;
	public String reference_type;
	public String publisherLocation;
	public float VAT;

	public REFERENCE_BOOK() {
		this.ISBN = "";
		this.topic = "";
		this.reference_type = "";
		this.publisherLocation = "";
		this.VAT = 0;

	}

	public REFERENCE_BOOK(int number, String title, String author, String publish, int day, int month, int year,
			int warrantyYears, String rating, String type, String status, String export, int quantity,
			boolean isExported, float price, float weight, String iSBN, String topic, String reference_type,
			String publisherLocation, float vAT) {
		super(number, title, author, publish, day, month, year, warrantyYears, rating, type, status, export, quantity,
				isExported, price, weight);
		this.ISBN = iSBN;
		this.topic = topic;
		this.reference_type = reference_type;
		this.publisherLocation = publisherLocation;
		this.VAT = vAT;
	}

	public String getISBN() {
		return ISBN;
	}

	public void setISBN(String iSBN) {
		ISBN = iSBN;
	}

	public String getTopic() {
		return topic;
	}

	public void setTopic(String topic) {
		this.topic = topic;
	}

	public String getReference_type() {
		return reference_type;
	}

	public void setReference_type(String reference_type) {
		this.reference_type = reference_type;
	}

	public String getPublisherLocation() {
		return publisherLocation;
	}

	public void setPublisherLocation(String publisherLocation) {
		this.publisherLocation = publisherLocation;
	}

	public float getVAT() {
		return VAT;
	}

	public void setVAT(float vAT) {
		VAT = vAT;
	}

	public void input() {
		super.input();
		Scanner q = new Scanner(System.in);
		System.out.println("Enter ISBN: ");
		this.setISBN(q.nextLine());
		System.out.println("Enter topic: ");
		this.setTopic(q.nextLine());
		System.out.println("Enter reference_type (academic or non-academic): ");
		this.setReference_type(q.nextLine());
		System.out.println("Enter publisherLocation: ");
		this.setPublisherLocation(q.nextLine());
		System.out.println("Enter VAT: ");
		this.setVAT(q.nextFloat());
		updateQuantity();
	}

	public void output() {
		super.output();
		System.out.println(" ISBN: " + this.getISBN());
		System.out.println(" Topic: " + this.getTopic());
		System.out.println(" Reference_type: " + this.getReference_type());
		System.out.println(" PublisherLocation: " + this.getPublisherLocation());
		System.out.println(" VAT: " + this.getVAT());
	}

	public double calculatePrice() {

		return this.MONEY_SERVE + this.getPrice() * this.getQuantity() + this.applyVAT() - this.discount();
	}

	public double discount() {
		double discountRate = 0;

		if (this.getStatus().equals("new")) {
			discountRate = 0.5;
		} else if (this.getStatus().equals("old")) {
			discountRate = 1.5;
		} else {
			discountRate = 0.1;
		}

		if (this.getQuantity() > 100) {
			discountRate += 2;
		}

		if (this.getRating().equals("high")) {
			discountRate += 0.03;
		} else if (this.getRating().equals("low")) {
			discountRate -= 0.02;
		}

		if (this.getReference_type().equals("academic")) {
			discountRate += 0.02;
		} else if (this.getReference_type().equals("non-academic")) {
			discountRate += 0.01;
		}

		return this.getQuantity() * this.getPrice() * discountRate;
	}

	public void checkBookType() {
		String[] academicReferences = { "textbook", "journal", "thesis", "dissertation", "research" };
		String[] technicalReferences = { "manual", "guide", "handbook", "specification", "technical" };
		this.setType("General");

		for (String academic : academicReferences) {
			if (academic.equalsIgnoreCase(topic)) {
				this.setType("Academic Reference");
				break;
			}
		}

		for (String technical : technicalReferences) {
			if (technical.equalsIgnoreCase(topic)) {
				this.setType("Technical Reference");
				break;
			}
		}

		System.out.println("Book Type: " + this.getType());
	}

	public double applyVAT() {
		if (this.getWeight() > 10 && this.getWeight() < 50) {
			return this.getPrice() * this.getVAT() / 100;
		} else if (this.getWeight() >= 50) {
			return this.getPrice() * (this.getVAT() / 100) * (this.getWeight() - 49);
		} else {
			return 0;
		}
	}

}

class BOOKLIST {
	ArrayList<BOOK> list = new ArrayList<BOOK>();
	int n = 0;
	char chon, loai;

	void addBook() throws IOException {
		do {
			BOOK a[] = new BOOK[100];
			System.out.println("1. TEXTBOOK");
			System.out.println("2. REFERENCE_BOOK");
			System.out.println("Enter selection: ");
			chon = (char) System.in.read();

			if (chon == '1') {
				a[n] = new TEXTBOOK();
			} else if (chon == '2') {
				a[n] = new REFERENCE_BOOK();
			}
			System.in.skip(chon);
			a[n].input();
			list.add(a[n++]);

			System.out.println("Continue (Y/N)?");
			loai = (char) System.in.read();
			System.in.skip(loai);
			if ((n == 100) || (loai == 'N') || (loai == 'n')) {
				break;
			}
		} while (true);
	}

	void displayBooks() {
		for (int i = 0; i < list.size(); i++) {
			list.get(i).output();
		}
	}

	void findBook() {
		Scanner z = new Scanner(System.in);
		String Ititle;
		System.out.println("Enter book title: ");
		Ititle = z.nextLine();
		int k = -1;
		for (int i = 0; i < list.size(); i++) {
			if (list.get(i).getTitle().contains(Ititle)) {
				k = i;
				System.out.println("Yes!");
				break;
			}
		}
		if (k == -1) {
			System.out.println("No");
		}
	}

	void removeBook() {
		Scanner z = new Scanner(System.in);
		String Ititle;
		System.out.println("Enter book title to delete: ");
		Ititle = z.nextLine();
		for (int i = 0; i < list.size(); i++) {
			if (list.get(i).getTitle().contains(Ititle)) {
				list.remove(i);
				System.out.println("Book deleted.");
				break;
			}
		}
	}

	double calculateTotalPriceForTextbooks() {
		double sum = 0;
		for (BOOK book : list) {
			if (book instanceof TEXTBOOK) {
				sum += book.calculatePrice();
			}
		}
		System.out.println("Total price for textbooks is: " + sum);
		return sum;
	}

	double calculateTotalPriceForReferenceBooks() {
		double sum = 0;
		for (BOOK book : list) {
			if (book instanceof REFERENCE_BOOK) {
				sum += book.calculatePrice();
			}
		}
		System.out.println("Total price for reference books is: " + sum);
		return sum;
	}

	double calculateTotalPrice() {
		double sum = 0;
		for (int i = 0; i < list.size(); i++) {
			sum += list.get(i).calculatePrice();
		}
		System.out.println("Sum book money is: " + sum);
		return sum;
	}

	void maxprice() {
		if (list.isEmpty()) {
			System.out.println("No books available.");
			return;
		}
		BOOK max = list.get(0);
		for (int i = 1; i < list.size(); i++) {
			if (max.calculatePrice() < list.get(i).calculatePrice()) {
				max = list.get(i);
			}
		}
		System.out.println("The most expensive book: " + max.getTitle() + " with price: " + max.calculatePrice());
	}

	void minprice() {
		if (list.isEmpty()) {
			System.out.println("No books available.");
			return;
		}
		BOOK min = list.get(0);
		for (int i = 1; i < list.size(); i++) {
			if (min.calculatePrice() > list.get(i).calculatePrice()) {
				min = list.get(i);
			}
		}
		System.out.println("The cheapest book: " + min.getTitle() + " with price: " + min.calculatePrice());
	}

	void clearList() {
		list.clear();
		System.out.println("The book list has been cleared.");
	}

	void sort() {
		for (int i = 0; i < list.size() - 1; i++) {
			for (int j = i + 1; j < list.size(); j++) {
				if (list.get(i).calculatePrice() > list.get(j).calculatePrice()) {
					BOOK temp = list.get(i);
					list.set(i, list.get(j));
					list.set(j, temp);
				}
			}
		}
		System.out.println("Books sorted by price:");
		displayBooks();
	}

	public void saveToFile() throws IOException {
		File file = new File("D:\\cmutpm2.txt");
		FileWriter writer = null;

		try {

			writer = new FileWriter(file);
			writer.write(
					"\n+------------------------------------------------------------------------------------------------------------------------------- TEXTBOOK -----------------------------------------------------------------------------------------------------------------------------+\n");
			writer.write(
					"| Book Number | Title           | Author          | Publisher       | Publication Date | Warranty Period | Rating    | Type      | Status    | Is Exported | Price       | Weight      | Subject         | Level           | Version      | Education Level | Tax      |\n");
			writer.write(
					"+-------------+-----------------+-----------------+-----------------+------------------+-----------------+-----------+-----------+-----------+-------------+-------------+-------------+-----------------+-----------------+--------------+-----------------+----------+\n");

			for (BOOK book : list) {
				if (book instanceof TEXTBOOK) {
					TEXTBOOK textbook = (TEXTBOOK) book;
			
					writer.write(String.format(
							"| %-11d | %-15s | %-15s | %-15s | %-16s | %-15d | %-9s | %-9s | %-9s | %-11s | %-11.2f | %-11.2f |  %-15s | %-15s | %-12s | %-15s | %-8.2f |\n",
							book.getNumber(), book.getTitle(), book.getAuthor(), book.getPublish(),
							book.getDay() + "/" + book.getMonth() + "/" + book.getYear(), book.getWarrantyYears(),
							book.getRating(), book.getType(), book.getStatus(), book.getisExported(), book.getPrice(),
							book.getWeight(), textbook.getSubject(), textbook.getLevel(), textbook.getVersion(),
							textbook.getEducation_level(), textbook.getTax()));
				}
			}

			
			writer.write(
					"\n+-------------------------------------------------------------------------------------------------------------------------------- REFERENCE BOOK ----------------------------------------------------------------------------------------------------------------------+\n");
			writer.write(
					"| Book Number | Title           | Author          | Publisher       | Publication Date | Warranty Period | Rating    | Type      | Status    | Is Exported | Price       | Weight      | ISBN            | Topic           | Ref. Type    | Location        | VAT      |\n");
			writer.write(
					"+-------------+-----------------+-----------------+-----------------+------------------+-----------------+-----------+-----------+-----------+-------------+-------------+-------------+-----------------+-----------------+--------------+-----------------+----------+\n");

			for (BOOK book : list) {
				if (book instanceof REFERENCE_BOOK) {
					REFERENCE_BOOK referenceBook = (REFERENCE_BOOK) book;
					
					writer.write(String.format(
							"| %-11d | %-15s | %-15s | %-15s | %-16s | %-15d | %-9s | %-9s | %-9s | %-11s | %-11.2f | %-11.2f | %-15s | %-15s | %-12s | %-15s | %-8.2f |\n",
							book.getNumber(), book.getTitle(), book.getAuthor(), book.getPublish(),
							book.getDay() + "/" + book.getMonth() + "/" + book.getYear(), book.getWarrantyYears(),
							book.getRating(), book.getType(), book.getStatus(), book.getisExported(), book.getPrice(),
							book.getWeight(), referenceBook.getISBN(), referenceBook.getTopic(),
							referenceBook.getReference_type(), referenceBook.getPublisherLocation(),
							referenceBook.getVAT()));
				}
			}

			System.out.println("Book list saved to cmutpm2.txt");
		} catch (IOException e) {
			System.out.println("An error occurred while saving to file.");
			e.printStackTrace();
		} finally {
			if (writer != null) {
				try {
					writer.close();
				} catch (IOException e) {
					System.out.println("Error closing FileWriter.");
					e.printStackTrace();
				}
			}
		}
	}

	void loadFromFile() throws IOException {
		File a = new File("D:\\cmutpm2.txt");
		FileReader b = new FileReader(a);
		BufferedReader c = new BufferedReader(b);
		try {

			String line;

			while ((line = c.readLine()) != null) {
				String[] data = line.split(", ");

				if (data.length < 23) {
					System.out.println(line);
					continue;
				}

				BOOK book;
				if (data[0].equals("TEXTBOOK")) {
					book = new TEXTBOOK();
				} else {
					book = new REFERENCE_BOOK();
				}

				list.add(book);
			}
			System.out.println("Book list loaded from cmutpm2.txt");
		} catch (FileNotFoundException e) {
			System.out.println("Error!");
			e.printStackTrace();
			c.close();
		}
		c.close();
	}

	void Menu() throws IOException {
		Scanner u = new Scanner(System.in);
		while (true) {
			System.out.println("    Menu    ");
			System.out.println(" 1. Add Book: ");
			System.out.println(" 2. Display Books: ");
			System.out.println(" 3. Find Book: ");
			System.out.println(" 4. Remove Book: ");
			System.out.println(" 5. Calculate Total Price For Text Book: ");
			System.out.println(" 6. Calculate Total Price For Reference Book: ");
			System.out.println(" 7. Calculate Total Price: ");
			System.out.println(" 8. Max Price: ");
			System.out.println(" 9. Min Price: ");
			System.out.println("10. Sort Book: ");
			System.out.println("11. Save To File: ");
			System.out.println("12. Read From File: ");
			System.out.println("13. Clear List: ");
			System.out.println("14. Exit: ");
			System.out.println("    Choose an opition: ");
			int chon = u.nextInt();
			switch (chon) {
			case 1:
				addBook();
				break;
			case 2:
				displayBooks();
				break;
			case 3:
				findBook();
				break;
			case 4:
				removeBook();
				break;
			case 5:
				calculateTotalPriceForTextbooks();
				break;
			case 6:
				calculateTotalPriceForReferenceBooks();
				break;
			case 7:
				calculateTotalPrice();
				break;
			case 8:
				maxprice();
				break;
			case 9:
				minprice();
				break;
			case 10:
				sort();
				break;
			case 11:
				saveToFile();
				break;
			case 12:
				loadFromFile();
				break;
			case 13:
				clearList();
				break;
			case 14:
				System.out.println("Exiting....");
				return;
			default:
				System.out.println("Invalid opition. Try again!!");
				break;
			}

		}
	}

}

public abstract class Doancanhan {

	public static void main(String[] args) throws IOException {
		BOOKLIST e = new BOOKLIST();
		e.Menu();
	}

}
