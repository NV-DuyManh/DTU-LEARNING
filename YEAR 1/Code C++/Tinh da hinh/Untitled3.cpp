#include<iostream>
#include<vector>
using namespace std;

class Employee {
	protected:
		string name;
		int paymentPerHour;
	public:
		Employee(){
		}
		Employee(string name, int paymentPerHour){
			this->name = name;
			this->paymentPerHour = paymentPerHour;
		}
		~Employee(){
		}
	string getName(){
		return this->name;
	}
	int getPaymentPerHour(){
		return this->paymentPerHour;
	}
	void setName(string name){
		this->name= name;
	}
	void setPaymentPerHour(int paymentPerHour){
		this->paymentPerHour = paymentPerHour;
	}
	
	virtual void Input(){
		fflush(stdin);
		cout<<"Nhap ten: ";
		getline(cin, this->name);
		cout<<"Nhap tien nhan duoc: ";
		cin>>this->paymentPerHour;
	}
	virtual void Output(){
		cout<<"Ten: "<<this->name<<endl;
		cout<<"Tien nhan duoc: "<<this->paymentPerHour<<endl;
	}
	virtual float CalculateSalar () = 0;
	
}; 
class PartTimeEmployee : public Employee{
	private:
		float workingHours;
	public:
		PartTimeEmployee(){
		}
		PartTimeEmployee(string name, int paymentPerHour, float workingHours):Employee(name, paymentPerHour){
			this->workingHours = workingHours;
		}
		~PartTimeEmployee(){
		}
	float getWorkingHours(){
		return this->workingHours;
	}
	void setWorkingHours(float workingHours){
		this->workingHours = workingHours;
	}
	void Input(){
		fflush(stdin);
		Employee::Input();
		cout <<"Nhap gio lam viec: ";
		cin>>this->workingHours;
	}
	void Output(){
		Employee::Output();
		cout<<"Gio lam viec: "<<this->workingHours<<endl;
	}
	float CalculateSalary(){
		return this->workingHours * this->paymentPerHour;
	}
};
class FullTimeEmployee : public Employee{
	public:
		FullTimeEmployee(){
		}
		~FullTimeEmployee(){
		}
		float CalculateSalary(){
			return 8* this->paymentPerHour;
		}
};
class EmployeeManager {
	private:
		vector<Employee*>ds;
	public:
		EmployeeManager(){
		}
		~EmployeeManager(){
			for(int i=0; i<ds.size();i++){
				delete ds[i];
			}
			ds.clear();
		}
	void NhapDs(){
		while(true){
			cout <<"\t\tNhap tuy chon:"<<endl;
			cout <<"\t1.Nhap PartTimeEmployee "<<endl;
			cout <<"\t2.Nhap FullTimeEmployee "<<endl;
			cout <<"\t3.Thoat"<<endl;
			int luachon;
			cout <<"Nhap lua chon: ";
			cin>>luachon;
			if(luachon == 1){
				Employee *btg = new PartTimeEmployee();
				btg->Input();
				ds.push_back(btg);
			}else if(luachon == 2){
				Employee *ttg = new FullTimeEmployee();
				ttg->Input();
				ds.push_back(ttg);
			}else if(luachon == 3){
				break;
			}else{
				cout <<"Lua chon khong dung, nhap lai";
			}
		}
	}
	void XuatDs(){
		for(int i=0;i<ds.size();i++){
			cout <<"Thong tin nhan vien thu "<<i+1<<" la: "<<endl;
			ds[i]->Output();
		}
	}
	float tongluong(){
	for (int i=0;i<ds.size();i++) {
                if (dynamic_cast<FullTimeEmployee*>(ds)) {  
                   float totalSalary += ds[i]->CalculateSalary();
                }
            }
            cout << "Tong luong nhan vien toan thoi gian: " << totalSalary << endl;}
	void Menu(){
		while(true){
			cout<<"\t\t===Menu==="<<endl;
			cout<<"\t1.Them viec lam "<<endl;
			cout<<"\t2.Hien thi tat ca nhan vien"<<endl;
			cout<<"\t3.Hien thi tong luong nhan vien toan thoi gian";
			cout<<"\t4.Sap xep nhan vien theo ten"<<endl;
			cout<<"\t5.Thoat"<<endl;
			int nhap;
			cout <<"Nhap lua chon: ";
			cin>nhap;
			if(nhap == 1){
				NhapDs();
			}else if(nhap == 2){
				XuatDs();
			}else if(nhap == 3){
				
			}else if(nhap == 4){
				
			}else if(nhap == 5){
				break;
			}else{
				cout <<"Lua chon khong dung, nhap lai";
			}
		}
	}
	void SapXep(){
            for(int i = 0; i < ds.size(); i++){
                for(int j = 0; j < ds.size(); j++){
                    if(ds[i]->getName() > ds[j]->getName()){
                        Employee *tam = ds[i];
                        ds[i] = ds[j];
                        ds[j] = tam;
                    }
                }
            }
        }
};
int main(){
	EmployeeManager *a = new EmployeeManager();
	a->Menu();
	delete a;
	return 0;
}








