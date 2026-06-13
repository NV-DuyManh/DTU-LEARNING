#include<iostream>
using namespace std;
#define MAX_BOOKS 1000
class Book{
	private:
		string title;
		string author;
		int year;
	public:
		Book(){
		}
		Book(string title, string author, int year){
			this->title = title;
			this->author = author;
			this->year = year;
		}
		~Book(){
		}
		void set_author(string author){
			this->author = author;
		}
		string get_author(){
			return this->author;
		}
		void Input(){
			fflush(stdin);
			cout << "Enter the title: ";
			getline(cin, this->title);
			fflush(stdin);
			cout << "Enter the author: ";
			getline(cin, this->author);
			cout << "Enter the year: ";
			cin >> this->year;
		}
		void Output(){
			cout << "Title: " << this->title << endl;
			cout << "author: " << this->author << endl;
			cout << "year: " << this->year << endl;
		}
		
};
int main(){
	Book *ds[MAX_BOOKS];
	int n = 0;
	while(true){
		cout << "\t====MENU====" << endl;
		cout << "1. Add" << endl;
		cout << "2. Display" << endl;
		cout << "3. Search by author name" << endl;
		cout << "4. Exit" << endl;
		int choosen;
		cout << "Enter the choosen: ";
		cin >> choosen;
		if(choosen == 1){
			do{
				cout << "Enter the number of book(s) (1 - 1000): ";
				cin >> n;
			}while(n <= 0 || n > 1000);
			for(int i = 0; i < n; i++){
//				Book *book = new Book();
//				book->Input();
//				ds[i] = book;
				cout << "Enter book's info " << (i+1) << ": " << endl;
				ds[i] = new Book();
				ds[i]->Input();
			}
			
		}else if(choosen == 2){
			if(n > 0){
				cout << "\tList books: " << endl;
				for(int i = 0; i < n; i++){
					cout << "Book's info " << (i+1) << ": " << endl;
					ds[i]->Output();
				}
			}else{
				cout << "Empty" << endl;
			}
			
		}else if(choosen == 3){
			string author_search;
			fflush(stdin);
			cout << "Enter author name to search: ";
			getline(cin, author_search);
			bool check = true; //gia su ko tim thay
			for(int i = 0; i < n; i++){
				if(ds[i]->get_author() == author_search){
					ds[i]->Output();
					check = false;
				}
			}
			if(check){
				cout << "not found" << endl;
			}
		}else if(choosen == 4){
			for(int i = 0; i < n; i++){
				delete ds[i];
			}
			break;
		}else{
			
			cout << "Invalid! Enter again" << endl;
		}
		
	}
	return 0;
}
