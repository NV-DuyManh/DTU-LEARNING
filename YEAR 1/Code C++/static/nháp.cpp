#include<iostream>
#include<string>

class BankAccount {
private:
    double balance;
    double interest_rate;

public:
    BankAccount(double balance, double interest_rate) : balance(balance), interest_rate(interest_rate) {}

    void Deposit(double amount) {
        balance += amount;
    }

    bool Withdraw(double amount) {
        if(amount > balance) {
            std::cout << "Không d? s? du d? rút ti?n!" << std::endl;
            return false;
        }
        balance -= amount;
        return true;
    }

    friend class BankStatement;
};

class BankStatement {
public:
    void PrintStatement(const BankAccount& account) {
        std::cout << "so du: " << account.balance << std::endl;
        std::cout << "lai xuat: " << account.interest_rate << std::endl;
    }
};

int main() {
    BankAccount myAccount(10000.0, 0.05);
    BankStatement myStatement;

    myAccount.Deposit(5000.0);
    myAccount.Withdraw(2000.0);

    myStatement.PrintStatement(myAccount);

    return 0;
}

