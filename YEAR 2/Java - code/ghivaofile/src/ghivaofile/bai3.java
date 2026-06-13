package ghivaofile;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

interface IManageable {
    boolean isAvailable();
    double calculateRentalPrice();
}

abstract class LibraryItem implements IManageable {
    protected String id;
    protected String title;
    protected String author;
    protected int publishYear;
    protected String category;
    protected String location;
    protected double price;
    protected int numCopies;
    protected boolean checkedOut;

    public LibraryItem(String id, String title, String author, int publishYear, String category, String location, double price, int numCopies) {
        this.id = id;
        this.title = title;
        this.author = author;
        this.publishYear = publishYear;
        this.category = category;
        this.location = location;
        this.price = price;
        this.numCopies = numCopies;
        this.checkedOut = false;
    }

    public LibraryItem() {
        this("", "", "", 0, "", "", 0, 0);
    }

    // Getters and Setters
    public String getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public int getPublishYear() {
        return publishYear;
    }

    public String getCategory() {
        return category;
    }

    public String getLocation() {
        return location;
    }

    public double getPrice() {
        return price;
    }

    public int getNumCopies() {
        return numCopies;
    }

    public boolean isCheckedOut() {
        return checkedOut;
    }

    public void checkOut() {
        if (isAvailable()) {
            this.checkedOut = true;
            this.numCopies--;
            System.out.println("Item checked out successfully.");
        } else {
            System.out.println("Item is not available.");
        }
    }

    public void returnItem() {
        this.checkedOut = false;
        this.numCopies++;
        System.out.println("Item returned.");
    }

    public boolean isAvailable() {
        return numCopies > 0 && !checkedOut;
    }

    public abstract double calculateRentalPrice();

    public void input() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter ID: ");
        this.id = sc.nextLine();
        System.out.print("Enter Title: ");
        this.title = sc.nextLine();
        System.out.print("Enter Author: ");
        this.author = sc.nextLine();
        System.out.print("Enter Publish Year: ");
        this.publishYear = sc.nextInt();
        sc.nextLine(); 
        System.out.print("Enter Category: ");
        this.category = sc.nextLine();
        System.out.print("Enter Location: ");
        this.location = sc.nextLine();
        System.out.print("Enter Price: ");
        this.price = sc.nextDouble();
        System.out.print("Enter Number of Copies: ");
        this.numCopies = sc.nextInt();
        System.out.print("Enter Checked Out (true/false): ");
        this.checkedOut = sc.nextBoolean();
        sc.nextLine(); 
    }

    public void output() {
        System.out.println("ID: " + this.id);
        System.out.println("Title: " + this.title);
        System.out.println("Author: " + this.author);
        System.out.println("Publish Year: " + this.publishYear);
        System.out.println("Category: " + this.category);
        System.out.println("Location: " + this.location);
        System.out.println("Price: " + this.price);
        System.out.println("Number of Copies: " + this.numCopies);
        System.out.println("Checked Out: " + (this.checkedOut ? "Yes" : "No"));
    }
}

class Book extends LibraryItem {
    private String isbn;
    private int numberOfPages;

    public Book(String id, String title, String author, int publishYear, String category, String location, double price, int numCopies, String isbn, int numberOfPages) {
        super(id, title, author, publishYear, category, location, price, numCopies);
        this.isbn = isbn;
        this.numberOfPages = numberOfPages;
    }

    public Book() {
        super();
        this.isbn = "";
        this.numberOfPages = 0;
    }

    // Getters and Setters
    public String getIsbn() {
        return isbn;
    }

    public int getNumberOfPages() {
        return numberOfPages;
    }

    public boolean isHardcover() {
        return numberOfPages > 300;
    }

    public double calculateRentalPrice() {
        return price + (numberOfPages * 0.01);
    }

    public void input() {
        super.input();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter ISBN: ");
        this.isbn = sc.nextLine();
        System.out.print("Enter Number of Pages: ");
        this.numberOfPages = sc.nextInt();
    }

    public void output() {
        super.output();
        System.out.println("ISBN: " + this.isbn);
        System.out.println("Number of Pages: " + this.numberOfPages);
        System.out.println("Hardcover: " + (isHardcover() ? "Yes" : "No"));
    }
}

class Magazine extends LibraryItem {
    private int issueNumber;
    private String frequency;

    public Magazine(String id, String title, String author, int publishYear, String category, String location, double price, int numCopies, int issueNumber, String frequency) {
        super(id, title, author, publishYear, category, location, price, numCopies);
        this.issueNumber = issueNumber;
        this.frequency = frequency;
    }

    public Magazine() {
        super();
        this.issueNumber = 0;
        this.frequency = "";
    }

    // Getters and Setters
    public int getIssueNumber() {
        return issueNumber;
    }

    public String getFrequency() {
        return frequency;
    }

    public boolean isMonthly() {
        return frequency.equalsIgnoreCase("monthly");
    }

    public double calculateRentalPrice() {
        return price + (issueNumber * 0.5);
    }

    public void input() {
        super.input();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Issue Number: ");
        this.issueNumber = sc.nextInt();
        sc.nextLine(); 
        System.out.print("Enter Frequency: ");
        this.frequency = sc.nextLine();
    }

    public void output() {
        super.output();
        System.out.println("Issue Number: " + issueNumber);
        System.out.println("Frequency: " + frequency);
        System.out.println("Monthly: " + (isMonthly() ? "Yes" : "No"));
    }
}

class LibraryList {
    private List<LibraryItem> list = new ArrayList<>();

    void addLibraryItem(LibraryItem item) {
        list.add(item);
    }

    void displayItems() {
        for (LibraryItem item : list) {
            item.output();
            System.out.println("-----------------------------");
        }
    }

    LibraryItem findItem(String title) {
        for (LibraryItem item : list) {
            if (item.getTitle().equalsIgnoreCase(title)) {
                return item;
            }
        }
        return null;
    }

    void removeItem(String title) {
        LibraryItem item = findItem(title);
        if (item != null) {
            list.remove(item);
            System.out.println("Item deleted.");
        } else {
            System.out.println("Item not found.");
        }
    }

//    public void saveToFile() throws IOException {
//        File file = new File("D:\\bai3.txt");
//        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
//            for (LibraryItem item : list) {
//                writer.write("+-----------------------------+\n");
//                if (item instanceof Book) {
//                    Book book = (Book) item;
//                    writer.write("|          BOOK               |\n");
//                    writer.write("+-----------------------------+\n");
//                    writer.write("| ID:               " + String.format("%-20s", book.getId()) + " |\n");
//                    writer.write("| Title:            " + String.format("%-20s", book.getTitle()) + " |\n");
//                    writer.write("| Author:           " + String.format("%-20s", book.getAuthor()) + " |\n");
//                    writer.write("| Publish Year:     " + String.format("%-20s", book.getPublishYear()) + " |\n");
//                    writer.write("| Category:         " + String.format("%-20s", book.getCategory()) + " |\n");
//                    writer.write("| Location:         " + String.format("%-20s", book.getLocation()) + " |\n");
//                    writer.write("| Price:           " + String.format("%-20s", book.getPrice()) + " |\n");
//                    writer.write("| Number of Copies: " + String.format("%-20s", book.getNumCopies()) + " |\n");
//                    writer.write("| ISBN:            " + String.format("%-20s", book.getIsbn()) + " |\n");
//                    writer.write("| Number of Pages:  " + String.format("%-20s", book.getNumberOfPages()) + " |\n");
//                    writer.write("| Checked Out:      " + String.format("%-20s", (book.isCheckedOut() ? "Yes" : "No")) + " |\n");
//                } else if (item instanceof Magazine) {
//                    Magazine magazine = (Magazine) item;
//                    writer.write("|          MAGAZINE            |\n");
//                    writer.write("+-----------------------------+\n");
//                    writer.write("| ID:               " + String.format("%-20s", magazine.getId()) + " |\n");
//                    writer.write("| Title:            " + String.format("%-20s", magazine.getTitle()) + " |\n");
//                    writer.write("| Author:           " + String.format("%-20s", magazine.getAuthor()) + " |\n");
//                    writer.write("| Publish Year:     " + String.format("%-20s", magazine.getPublishYear()) + " |\n");
//                    writer.write("| Category:         " + String.format("%-20s", magazine.getCategory()) + " |\n");
//                    writer.write("| Location:         " + String.format("%-20s", magazine.getLocation()) + " |\n");
//                    writer.write("| Price:           " + String.format("%-20s", magazine.getPrice()) + " |\n");
//                    writer.write("| Number of Copies: " + String.format("%-20s", magazine.getNumCopies()) + " |\n");
//                    writer.write("| Issue Number:     " + String.format("%-20s", magazine.getIssueNumber()) + " |\n");
//                    writer.write("| Frequency:        " + String.format("%-20s", magazine.getFrequency()) + " |\n");
//                    writer.write("| Checked Out:      " + String.format("%-20s", (magazine.isCheckedOut() ? "Yes" : "No")) + " |\n");
//                }
//                writer.write("+-----------------------------+\n");
//            }
//        }
//    }

    public void saveToFile() throws IOException {
        File file = new File("D:\\bai3.txt");
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
            for (LibraryItem item : list) {
                if (item instanceof Book) {
                    Book book = (Book) item;
                    writer.write("+---------------------------- BOOK ----------------------------+\n");
                    writer.write("ID | Title | Author | Publish Year | Category | Location | Price | Copies | ISBN | Pages | Checked Out\n");
                    writer.write(String.format("%-5s| %-10s| %-10s| %-14s| %-10s| %-10s| %-8.2f| %-7d| %-10s| %-8d| %-12s\n",
                            book.getId(),
                            book.getTitle(),
                            book.getAuthor(),
                            book.getPublishYear(),
                            book.getCategory(),
                            book.getLocation(),
                            book.getPrice(),
                            book.getNumCopies(),
                            book.getIsbn(),
                            book.getNumberOfPages(),
                            (book.isCheckedOut() ? "Yes" : "No")
                    ));
                } else if (item instanceof Magazine) {
                    Magazine magazine = (Magazine) item;
                    writer.write("+--------------------------- MAGAZINE ---------------------------+\n");
                    writer.write("ID | Title | Author | Publish Year | Category | Location | Price | Copies | Issue Number | Frequency | Checked Out\n");
                    writer.write(String.format("%-5s| %-10s| %-10s| %-14s| %-10s| %-10s| %-8.2f| %-7d| %-12s| %-10s| %-12s\n",
                            magazine.getId(),
                            magazine.getTitle(),
                            magazine.getAuthor(),
                            magazine.getPublishYear(),
                            magazine.getCategory(),
                            magazine.getLocation(),
                            magazine.getPrice(),
                            magazine.getNumCopies(),
                            magazine.getIssueNumber(),
                            magazine.getFrequency(),
                            (magazine.isCheckedOut() ? "Yes" : "No")
                    ));
                }
                writer.write("+----------------------------------------------------------------+\n");
            }
        }
    }

    
    
    public void loadFromFile() throws IOException {
        File file = new File("D:\\bai3.txt");
        if (!file.exists()) {
            System.out.println("File does not exist.");
            return;
        }
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = reader.readLine()) != null) {
                if (line.contains("BOOK")) {
                    Book book = new Book();
                    book.input();
                    addLibraryItem(book);
                } else if (line.contains("MAGAZINE")) {
                    Magazine magazine = new Magazine();
                    magazine.input();
                    addLibraryItem(magazine);
                }
            }
        }
    }
}

public class bai3 {
    public static void main(String[] args) {
        LibraryList libraryList = new LibraryList();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("1. Add Book");
            System.out.println("2. Add Magazine");
            System.out.println("3. Display All Items");
            System.out.println("4. Find Item");
            System.out.println("5. Remove Item");
            System.out.println("6. Save to File");
            System.out.println("7. Load from File");
            System.out.println("0. Exit");
            System.out.print("Choose an option: ");
            choice = scanner.nextInt();
            scanner.nextLine(); 

            switch (choice) {
                case 1:
                    Book book = new Book();
                    book.input();
                    libraryList.addLibraryItem(book);
                    break;
                case 2:
                    Magazine magazine = new Magazine();
                    magazine.input();
                    libraryList.addLibraryItem(magazine);
                    break;
                case 3:
                    libraryList.displayItems();
                    break;
                case 4:
                    System.out.print("Enter title to find: ");
                    String titleToFind = scanner.nextLine();
                    LibraryItem foundItem = libraryList.findItem(titleToFind);
                    if (foundItem != null) {
                        foundItem.output();
                    } else {
                        System.out.println("Item not found.");
                    }
                    break;
                case 5:
                    System.out.print("Enter title to remove: ");
                    String titleToRemove = scanner.nextLine();
                    libraryList.removeItem(titleToRemove);
                    break;
                case 6:
                    try {
                        libraryList.saveToFile();
                    } catch (IOException e) {
                        System.out.println("Error saving to file: " + e.getMessage());
                    }
                    break;
                case 7:
                    try {
                        libraryList.loadFromFile();
                    } catch (IOException e) {
                        System.out.println("Error loading from file: " + e.getMessage());
                    }
                    break;
                case 0:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 0);
        scanner.close();
    }
}
