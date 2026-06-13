#include <iostream>
#include <vector>
using namespace std;

class nguoi{
	protected:
		string hoten;
		int namsinh;
	public:
		nguoi(){
		}
		nguoi(string hoten, int namsinh){
			this->hoten = hoten;
			this->namsinh = namsinh;
		}
		~nguoi(){
		}
	string get_Hoten(){
		return this->hoten;
	}
	int get_Namsinh(){
		return this->namsinh;
	}
	void set_Hoten(string hoten){
		this->hoten = hoten;
	}
	void set_Namsinh(int namsinh){
		this->namsinh = namsinh;
	}
	virtual void Input(){
		fflush(stdin);
		cout<<"Nhap ho ten: ";
		getline(cin,  this->hoten);
		cout<<"Nhap nam sinh: ";
		cin>>this->namsinh;
	}
	virtual void Output(){
		cout<<"Ho ten: "<<this->hoten <<endl;
		cout<<"Nam sinh: "<<this->namsinh <<endl;
	}
};

class BN_O : public nguoi{
	private:
		string tenbenh;
		float tiendieutri;
	public:
		BN_O(){
		}
		BN_O(string hoten, int namsinh, string tenbenh, float tiendieutri):nguoi(hoten, namsinh){
			this->tenbenh = tenbenh;
			this->tiendieutri = tiendieutri;
		}
		~BN_O(){
		}
	string get_Tenbenh(){
		return this->tenbenh;
	}
	float get_Tiendieutri(){
		return this->tiendieutri;
	}
	void set_Tenbenh(string tenbenh){
		this->tenbenh = tenbenh;
	}
	void set_Tiendieutri(float tiendieutri){
		this->tiendieutri = tiendieutri;
	}
	void Input(){
		nguoi::Input();
		fflush(stdin);
		cout <<"Nhap ten benh: ";
		getline(cin, this->tenbenh);
		cout<<"Nhap tien dieu tri: ";
		cin>>this->tiendieutri;
	}
	void Output(){
		nguoi::Output();
		cout<<"Ten benh: "<<this->tenbenh<<endl;
		cout<<"Tien dieu tri: "<<this->tiendieutri <<endl;
	}
};

class BN_I : public nguoi{
	private:
		string tenbenhbandau;
		float tienthuoc, tieno;
	public:
		BN_I(){
		}
		BN_I(string hoten, int namsinh, string tenbenh, float tiendieutri, string tenbenhbandau, float tienthuoc, float tieno):nguoi(hoten,namsinh){
			this->tenbenhbandau = tenbenhbandau;
			this->tienthuoc = tienthuoc;
			this->tieno = tieno;
		}
		~BN_I(){
		}
	string get_Tenbenhbandau(){
		return this->tenbenhbandau;
	}
	void set_Tenbenhbandau(string tenbenhbandau){
		this->tenbenhbandau = tenbenhbandau;
	}
	float get_Tienthuoc(){
		return this->tienthuoc;
	}
	float get_Tieno(){
		return this->tieno;
	}
	void set_Tienthuoc(float tienthuoc){
		this->tienthuoc = tienthuoc;
	}
	void set_Tieno(float tieno){
		this->tieno = tieno;
	}
	void Input(){
		nguoi::Input();
		fflush(stdin);
		cout<<"Nhap ten benh chuan doan ban dau: ";
		getline(cin, this->tenbenhbandau);
		cout<<"Nhap tien thuoc: ";
		cin>>this->tienthuoc;
		cout<<"Nhap tien o: ";
		cin>>this->tieno;
	}
	void Output(){
		nguoi::Output();
		cout<<"Ten benh chuan doan ban dau: "<<this->tenbenhbandau<<endl;
		cout<<"Tien thuoc: "<<this->tienthuoc<<endl;
		cout<<"Tien o: "<<this->tieno <<endl;
	}
};
class Phongkham : public nguoi{
	private:
		vector<nguoi*>ds;
	public:
		Phongkham(){
		}
		~Phongkham(){
			for(int i =0; i<ds.size();i++){
				delete ds[i];
			}
			ds.clear();
		}
	void NhapDs(){
		while(true){
			cout<<"\t\t\tNhap loai benh nhan: "<<endl;
			cout<<"\t1.Benh nhan ngoai tru "<<endl;
			cout<<"\t2.Benh nhan noi tru "<<endl;
			cout<<"\t3.Thoat "<<endl;
			int nhap;
			cout<<"Nhap lua chon: ";
			cin>>nhap;
			if(nhap == 1){
				nguoi *ngt =new BN_O();
				ngt->Input();
				ds.push_back(ngt);
			}else if(nhap == 2){
				nguoi *nt = new BN_I();
				nt->Input();
				ds.push_back(nt);
			}else if(nhap == 3){
				break;
			}else {
				cout<<"Lua chon khong dung, nhap lai"<<endl;
			}
			
		}
	}
	void XuatDs(){
		for(int i =0; i<ds.size(); i++){
		cout <<"Thong tin benh nhan thu "<<i+1<<" : "<<endl;
		ds[i]->Output(); 
    	}
	}
	
	void Menu(){
		while(true){
			cout<<"\t\t\t===Menu==="<<endl;
			cout<<"\t\t1.Nhap danh sach"<<endl;
			cout<<"\t\t2.Xuat danh sach"<<endl;
			cout<<"\t\t3.Tong tien thanh toan"<<endl;
			cout<<"\t\t4.Sap xep"<<endl;
			cout<<"\t\t5.Thoat"<<endl;
			int luachon;
			cout<<"Nhap lua chon: ";
			cin>>luachon;
			if(luachon == 1){
				NhapDs();
			}else if(luachon == 2){
				XuatDs();
			}else if(luachon == 3){
				float tong = Tongtien();
                cout << "Tong tien: " << tong << endl;

			}else if(luachon == 4){
				SapXep();
			}else if(luachon == 5){
				break;
			}else{
				cout<<"Lua chon khong dung, nhap lai"<<endl;
			}
		
		}
	}

float Tongtien(){
    float tongtien=0;
    for(int i=0; i<ds.size(); i++){
        if( ds[i]->get_Namsinh() < 1960){    
            if(dynamic_cast<BN_O*>(ds[i]) !=NULL){
                BN_O *new_ngt = dynamic_cast<BN_O*>(ds[i]); 
                tongtien+= new_ngt->get_Tiendieutri() *8/100;
            }
            else if(dynamic_cast<BN_I*>(ds[i]) !=NULL){
                BN_I *new_nt = dynamic_cast<BN_I*>(ds[i]); 
                tongtien+= new_nt->get_Tienthuoc() *10/100 + new_nt->get_Tieno() *12/100;
            }
        }
        else if(ds[i]->get_Namsinh() >= 1960){
        	if(dynamic_cast<BN_O*>(ds[i]) !=NULL){
                BN_O *new_ngt = dynamic_cast<BN_O*>(ds[i]); 
                tongtien+= new_ngt->get_Tiendieutri();
            }
            else if(dynamic_cast<BN_I*>(ds[i]) !=NULL){
                BN_I *new_nt = dynamic_cast<BN_I*>(ds[i]); 
                tongtien+= new_nt->get_Tienthuoc() + new_nt->get_Tieno();
            }
		}
    }
    return tongtien;
}
  void SapXep(){
            for(int i = 0; i < ds.size(); i++){
                for(int j = 0; j < ds.size(); j++){
                    if(ds[i]->get_Hoten() > ds[j]->get_Hoten()){
                        nguoi *tam = ds[i];
                        ds[i] = ds[j];
                        ds[j] = tam;
                    }
                }
            }
        }


};
int main(){
	Phongkham *pk = new Phongkham;
	pk->Menu();
	delete pk;
	return 0;
}

