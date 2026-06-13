#include <iostream>
using namespace std;

class Employee{
	private:
		string firstName;
		string lastName;
	    int id, salary;
	    
	public:
		Employee (int id, string firstName, string lastName, int salary){
			this -> firstName = firstName;
			this -> lastName = lastName;
			this -> id =id;
			this -> salary = salary;
		}
		int getId(){
			return id;
		};
		string getFirstName(){
			return firstName;
		};
		string getLastName(){
			return lastName;
		};
		string getName(){
			return firstName + " " + lastName;
		};
		int getSalary(){
			return salary;
		};
		void setSalary (int newSalary){
			if (newSalary >=0 ){
				salary = newSalary;
			}
			else {
				cout <<"Error: Salary cannot be negative."<<endl;
			}
		}
		int getAnnualSalary(){
			return salary *12;
		};
		int raiseSalary(int percent){
			if (percent >=0){
				int raiseAmount = salary * percent / 100;
				salary += raiseAmount;
				return salary;
			}
			else {
				cout <<"Error: Raise percentage cannot be negative."<<endl;
				return salary;
			}
		}
		
};
int main (){
	Employee *e1 = new Employee(8, "Peter", "Tan", 2500);
//	e1->Output();
	e1->setSalary(999);
//	e1->Output();
	cout <<"id is: " << e1->getId() <<endl;
	cout <<"firstname is: " << e1->getFirstName() <<endl;
	cout <<"lastname is: " << e1->getLastName() <<endl;
	cout <<"salary is: "<< e1->getSalary() <<endl;
	cout <<"name is: " << e1->getName() <<endl; 
	cout <<"annual salary is: "<< e1->getAnnualSalary() <<endl;
	cout <<e1->raiseSalary(10) <<endl;
//	e1->Output();
	return 0;
}
