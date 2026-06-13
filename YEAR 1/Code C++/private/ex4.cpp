#include <iostream>
using namespace std; 
class Account {
    string name;
    double balance;

public:
    Account (string name, float balance){
    		this -> name = name;
    		this -> balance = balance;
		}
    
    ~Account() {}


    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "So du khong du" << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    Account *Tk= new Account("Duy Manh", 1000);
    Tk ->deposit(500);
    Tk ->withdraw(200);
    cout <<"So du hien tai la: " <<Tk->getBalance()<<endl;
  
    return 0;
}

