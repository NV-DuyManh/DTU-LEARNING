#include <iostream>
#include <cstring>

using namespace std;

class Book {
    string name;
    char *author;
    int py; 

public:
    Book(string n, const char *a, int y) : name(n), py(y) {
        author = new char[strlen(a) + 1];
        strcpy(author, a);
    }

    Book(const Book &b) : name(b.name), py(b.py) {
        author = new char[strlen(b.author) + 1];
        strcpy(author, b.author);
    }

    ~Book() {
        delete[] author;
    }

    Book& operator=(const Book &b) {
        if (this != &b) {
            delete[] author;
            name = b.name;
            py = b.py;
            author = new char[strlen(b.author) + 1];
            strcpy(author, b.author);
        }
        return *this;
    }

    bool operator==(const Book &b) {
        return (strcmp(author, b.author) == 0);
    }

    friend istream& operator>>(istream &is, Book &b);

    friend ostream& operator<<(ostream &os, const Book &b);
};

istream& operator>>(istream &is, Book &b) {
    cout << "Nhap ten sach: ";
    getline(is, b.name);
    cout << "Nhap ten tac gia: ";
    char temp[100];
    is.getline(temp, 100);
    b.author = new char[strlen(temp) + 1];
    strcpy(b.author, temp);
    cout << "Nhap nam xuat ban: ";
    is >> b.py;
    is.ignore(); 
    return is;
}

ostream& operator<<(ostream &os, const Book &b) {
    os << "Ten sach: " << b.name << endl;
    os << "Ten tac gia: " << b.author << endl;
    os << "Nam xuat bam: " << b.py << endl;
    return os;
}

int main() {
    Book b1("Sach 1", "Tac gia 1", 2020);
    Book b2 = b1; 
    Book b3("Sach 3", "Tac gia 3", 2021);
    b3 = b1; 
    cin >> b1; 
    cout << b1; 
    return 0;
}

