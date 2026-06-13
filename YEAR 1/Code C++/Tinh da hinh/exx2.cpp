#include <iostream>
#include <vector>
using namespace std;

class Vehicle{
	protected:
		int sobanhxe;
     	float trongluong;
    public:
    	Vehicle(){
		}
		Vehicle(int sobanhxe, float trongluong){
			this->sobanhxe = sobanhxe;
			this->trongluong = trongluong;
		}
		~Vehicle(){
		}
	int get_Sobanhxe(){
		return this->sobanhxe;
	}
	float get_Trongluong(){
		return this->trongluong;
	}
	void set_Sobanhxe(int sobanhxe){
		this->sobanhxe = sobanhxe;
	}
	void set_Trongluong(float trongluong){
		this->trongluong = trongluong;
	}
	virtual void Input(){
		
		cout<<"Nhap so banh xe: ";
		cin>>this->sobanhxe;
		cout<<"Nhap trong luong: ";
		cin>>this->trongluong;
	}
	virtual void Output(){
		cout<<"So banh xe: "<<this->sobanhxe<<endl;
		cout<<"Trong luong: "<<this->trongluong<<endl;
	}
};
class Car : public Vehicle{
	private:
		int sokhach;
	public:
		Car(){
		}
		Car(int sobanhxe, float trongluong, int sokhach):Vehicle(sobanhxe, trongluong){
			this->sokhach = sokhach;
		}
		~Car(){
		}
	int get_Sokhach(){
		return this->sokhach;
	}
	void set_Sokhach(int sokhach){
		this->sokhach = sokhach;
	}
	void Input(){
		Vehicle::Input();
		cout<<"Nhap so khach co the cho: ";
		cin>>this->sokhach;
	}
	void Output(){
		Vehicle::Output();
		cout<<"So khach co the cho: "<<this->sokhach <<endl;
	}
};
class Truck : public Vehicle{
	private:
		float taitrong;
	public:
		Truck(){
		}
		Truck(int sobanhxe, float trongluong, int sokhach, float taitrong):Vehicle(sobanhxe, trongluong){
			this->taitrong = taitrong;
		}
		~Truck(){
		}
	float get_Taitrong(){
		return this->taitrong;
	}
	void set_Taitrong(float taitrong){
		this->taitrong = taitrong;
	}
	void Input(){
		Vehicle::Input();
		cout<<"Nhap tai trong: ";
		cin>>this->taitrong;
	}
	void Output(){
		Vehicle::Output();
		cout<<"Tai trong: "<<this->taitrong<<endl;
	}
};
class LishVehicle{
	private:
		vector<Vehicle*>ds;
	public:
	LishVehicle(){
	};
	~LishVehicle(){
		for (int i=0; i<ds.size(); i++){
			delete ds[i];
		}
		ds.clear();
	}
	void NhapDS(){
		while(true){
			cout <<"\tNhap loai xe: "<<endl;
			cout <<"1. Nhap xe khach:"<<endl;
			cout <<"2. Nhap xe tai:"<<endl;
			cout <<"3. Thoat"<<endl;
			int kh;
			cout <<"Nhap: ";
			cin >>kh;
		if (kh == 1){
			Vehicle *xk = new Car();
			xk->Input();
			ds.push_back(xk);
		}
		else if (kh == 2){
			Vehicle *xt = new Truck();
			xt->Input();
			ds.push_back(xt);
		}
		else if(kh = 3){
			break;
        }else{
            cout << "\tLua chon ko dung. Vui long nhap lai!" << endl;
        }
    }
}
    void XuatDS(){
            for(int i = 0; i <ds.size(); i++){
                cout << "==Thong tin xe thu " << i+1 << ": " << endl;
                ds[i]->Output();
        }
        
    }
    void Sapxep () {
			for (int i=0;i<ds.size();i++) {
				for (int j=i+1;j<ds.size();j++) {
					if(ds[i]->get_Trongluong() <= ds[j]->get_Trongluong()) {
						swap(ds[j],ds[i]);
					}
				}
			}
	}
    float giam(){
    	for(int i=0; i<ds.size(); i++){
    		if(dynamic_cast<Car*>(ds[i]) !=NULL){
    			Car *new_car = dynamic_cast<Car*>(ds[i]); 
	         	new_car->get_Sokhach()-2;
		}
		    if(dynamic_cast<Truck*>(ds[i]) !=NULL){
    			Truck *new_truck = dynamic_cast<Truck*>(ds[i]); 
	         	new_truck->get_Trongluong()-50;
	    }
	}
}
	void dembx() {
		int demm = 0;
		for(int i =0; i<ds.size();i++){
			if(ds[i]->get_Sobanhxe() >6){
				demm++;
			}
		}
	}
    void Menu(){
            while(true){
                cout << "\t\t\t===MENU===" << endl;
                cout << "\t\t1. Nhap DS" << endl;
                cout << "\t\t2. Xuat DS" << endl;
                cout << "\t\t3. Sap xep trong luong giam dan: "<<endl;
                cout << "\t\t4. Giam xe khach xuong 2 nguoi , giam xe tai xuong 50kg"<<endl;
                cout << "\t\t5. Ðem so luong phuong tien co nhieu hon 6 banh"<<endl;
                cout << "\t\t6. Thoat" << endl;
                int luachon;
                cout << "Nhap lua chon: ";
                cin >> luachon;
                if(luachon == 1){
                    NhapDS();
                }else if(luachon == 2){
                    XuatDS();
                }else if(luachon == 3){
                	Sapxep();
				}else if(luachon == 4){
                	giam();
				}else if(luachon == 5){
                	dembx();
				}else if(luachon == 6){
                    break;
                }else{
                    cout << "Lua chon khong dung!" << endl;
                }
            }
        }
};
int main (){
	LishVehicle *a = new LishVehicle();
	a->Menu();
	delete a;
	return 0;	
};






