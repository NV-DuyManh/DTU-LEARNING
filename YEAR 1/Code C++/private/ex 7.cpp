#include<iostream>
using namespace std;
class Book{
	private:
		string title;
		string author;
		int year_published;
	public:
		Book(){
			this->title = " ";
			this->author = " ";
			this->year_published;
		};
		Book(string title, string author, int year_published){
			this->title = title;
			this->author = author;
			this->year_published = year_published;
		};
	~Book(){
	}
	string get_Title(){
		return this->title;
	};
	string get_Author(){
		return this->author;
	};
	int get_year_published(){
		return this->year_published;
	};
	void set_Title(string title){
		title = title;
	};
	void set_Author (string author){
		author = author;
	};
	
	void Input(){
		fflush(stdin);
		cout <<"Enter title:";
		getline(cin, this->title);
		cout <<"Enter author:";
		getline(cin, this->author);
		cout <<"Enter year_published:";
		cin >> this->year_published;
	};
	
	void Output(){
		cout <<"Title: "<<this->title<<endl;
		cout <<"Author: "<<this->author<<endl;
		cout <<"Year_published: "<<this->year_published<<endl;
	};
	
};
		
int main(){
	Book *ds[1000];
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
			bool check = true; 
			for(int i = 0; i < n; i++){
				if(ds[i]->get_Author() == author_search){
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
