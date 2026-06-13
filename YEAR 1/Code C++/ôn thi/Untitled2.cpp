#include <iostream>
#include <vector>
using namespace std;

class Xe{
	protected:
		string ten;
		float gio;
	public:
		Xe(){
		}
		Xe(string ten, float gio){
			this->ten = ten;
			this->gio = gio;
		}
		~Xe(){
		}
	string get_ten(){
		return this->ten;
    }
	float get_gio(){
		return this->gio;
	}
	
	void set_ten(string ten){
		this->ten = ten;
	}
	void set_gio(float gio){
		this->gio = gio;
	}
	virtual void Input(){
		fflush(stdin);
		cout <<"Nhap ten: ";
		getline(cin, this->ten);
		cout <<"Nhap gio thue: ";
		cin >>this->gio;
	} 
	virtual void Output(){
		cout <<"Ten: "<<this->ten<<endl;
		cout <<"Gio thue: "<<this->gio<<endl;
	}
	virtual float tien(){
		float tienthue = 0;
	}

};

class Xedap : public Xe{
	public:
	    void Output(){
	    	Xe::Output();
	    	cout<<"Tien thue xe dap: "<<tien()<<endl;
		}
		~Xedap(){
		};
	float tien(){
		Xe::tien();
		if(this->gio <=1){
			return 10000;
		}else{
			return 10000 +(this->gio-1)*8000;
		}
	}		
};

class ql : public Xe{
	private:
		vector<Xe*>ds;
	public:
		ql(){
		};
		~ql(){
			for(int i=0;i<ds.size();i++){
				delete ds[i];
			}
			ds.clear();
		};
	
	void NhapDs(){
		while(true){
			cout<<"Nhap tuy chon: "<<endl;
			cout<<"1. Xe dap"<<endl;
			cout<<"2. Xe may"<<endl;
			cout<<"3. Thoat"<<endl;
			int luachon;
			cout<<"Nhap lua chon: ";
			cin >> luachon;
			if(luachon == 1){
				Xe *xd = new Xedap();
				xd->Input();
				ds.push_back(xd);
			}else if(luachon == 3){
				break;
			}else{
				cout<<"Loi, nhap lai"; 
			}
		}
	}
	void XuatDs(){
		for (int i =0; i<ds.size(); i++){
			cout <<"Thong tin xe thu "<<i + 1<<" la: "<<endl;
			ds[i]->Output(); 
		}
	}
	void Menu(){
		   while(true){
		   	cout <<"Menu"<<endl;
		   	cout <<"1.Nhap xe"<<endl;
		   	cout <<"2.Xuat xe"<<endl;
		   	cout <<"3.Tong tien xm va xd"<<endl;
		   	cout <<"4.Tong tien xe may 200pk"<<endl;
		   	cout <<"5.Thoat"<<endl;
		   	int lc;
			   cout <<"Nhap lua chon: ";
			   cin >>lc;
			if(lc==1){
				NhapDs();
			} else if(lc==2){
				XuatDs();
			}else if(lc==3){
				tongxm();
//			}else if(lc==4){
//				Tong200();
			}
			else if(lc==5){
				break;
			}else{
				cout <<"Nhap lai"<<endl; 
			}
		   }
	} 
	float tongxm(){
		float tong =0;
		for(int i =0; i<ds.size();i++){
			tong+= ds[i]->tien();
		}
	} 
};
int main(){
	ql *a = new ql();
	a->Menu();
	delete a;
	return 0;
};
