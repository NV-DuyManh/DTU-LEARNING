#include <iostream>
using namespace std;

class BankAccount{
	private:
		float balance, interest_rate;
	public:
		BankAccount(){
		}
		BankAccount(float balance, float interest_rate){
			this->balance = balance;
			this->interest_rate = interest_rate;
		}
		~BankAccount(){
		}
		float get_balance(){
			return this->balance;
		}
		float get_interest_rate(){
			return this->interest_rate;
		}
		void set_balance(float balance){
			this->balance = balance;
		}
		void set_interest_rate(float interest_rate){
			this->interest_rate = interest_rate;
		}
		
		void Deposit(double amount) {
            balance += amount;
        }
        void  Withdraw(double amount) {
            if(amount > balance) {
                cout << "Khong du so du" << endl; 
            }else{
            	balance -= amount;
		    }
	    }
    friend class BankStatement;
    
};
class BankStatement {
public:
    void Output(const BankAccount &account) {
        cout << "So du: " << account.balance << endl;
        cout << "Lai xuat: " << account.interest_rate << endl;
    }
};
int main() {
    BankAccount a(10000, 100);
    BankStatement b;
    a.Deposit(2000);
    a.Withdraw(1000);
    b.Output(a);

    return 0;
}
