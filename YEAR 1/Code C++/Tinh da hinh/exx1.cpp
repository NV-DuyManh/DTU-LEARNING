#include <iostream>
using namespace std;

class ve{
	protected:
		string sohieu, di, den;
		float dodaiht;
		int mucgia;
	public:
		ve(){
		}
		ve(	string sohieu,string di,string den,	float dodaiht, int mucgia){
			this->sohieu = sohieu;
			this->di = di;
			this->den = den;
			this->dodaiht = dodaiht;
			this->mucgia = mucgia;
		}
		~ve(){
		}
	string get_Sohieu(){
		return this->sohieu;
	}
	string get_Di(){
		return this->di;
	}
	string get_Den(){
		return this->den;
	}
	float get_Dodaiht(){
		return this->dodaiht;
	}
	int get_Mucgia(){
		return this->mucgia;
	}
	void set_Sohieu(string sohieu){
		this->sohieu = sohieu;
	}
	void set_Di(string di){
		this->di = di;
	}
	void set_Den(string den){
		this->den = den;
	}
	void set_Dodaiht(float dodaiht){
		this->dodaiht = dodaiht;
	}
	void set_Mucgia(int mucgia){
		this->mucgia = mucgia;
	}
	void Input(){
		fflush(stdin);
		cout <<"Nhap so hieu: ";
		getline(cin, this->sohieu);
		cout <<"Nhap ten ga di: ";
		getline(cin, this->di);
		cout <<"Nhap ten ga den: ";
		getline(cin, this->den);
		cout <<"Nhap do dai hanh trinh: ";
		cin >>this->dodaiht;
	}
	void Output(){
		cout <<"So hieu: "<<this->sohieu <<endl;
		cout <<"Ten ga di: "<<this->di <<endl;
		cout <<"Ten ga den: "<<this->den <<endl;
		cout <<"Do dai hanh trinh: "<<this->dodaiht <<endl;
		cout <<"Muc gia: " <<this->mucgia <<endl;
	
	}
};

class tauhoa : public ve{
	public:
		tauhoa(){
			this->mucgia = 1000000;
		}
		~tauhoa(){
		}
	float tien(){
		if(500<this->dodaiht<=1200){
			return this->mucgia *120/100;
		}
		else{
			return this->mucgia;
		}
	}
	void Output(){
		ve::Output();
		cout <<"Gia ve tau hoa la: "<<tien()<<endl;
	}

};

class maybay : public ve{
	public:
		maybay(){
			this->mucgia = 1500000;
		}
		~maybay(){
		}
	float ttien(){
		if(this->dodaiht >1200){
			return this->mucgia *150/100;
		}
		else{
			return this->mucgia;
		}
	}
	void Output(){
		ve::Output();
		cout <<"Gia ve may bay la: "<<ttien()<<endl;
	}
};
class ql : public ve{
	private:
		ve *ds[1000];
		int n;
	public:
		ql(){
			this->n = 0;
		}
		~ql(){
			for(int i=0;i<n;i++){
				delete ds[i];
			}
		}
		void NhapDs(){
			while(true){
				cout <<"\tNhap loai ve: "<<endl;
				cout <<"1. Nhap tau hoa: "<<endl;
				cout <<"2. Nhap may bay: "<<endl;
				cout <<"3. Thoat: "<<endl;
				int nhap;
				cout <<"Nhap lua chon: ";
				cin >>nhap; 
				if(nhap == 1){
					tauhoa *th = new tauhoa();
					th->Input();
					ds[n]= th;
					n++;
				}
				else if(nhap == 2){
					maybay *mb = new maybay();
					mb->Input();
					ds[n]= mb;
					n++;
				}
				else if(nhap == 3){
		        	break;
                }
				else{
                    cout << "\tLua chon ko dung. Vui long nhap lai!" << endl;
                }
			}
		}
		void XuatDs(){
			for (int i=0; i<n;i++){
				cout <<"Thong tin ve thu "<<i+1<<" la: "<<endl;
				ds[i]->Output();
			}
		}
		void SapXep(){
			for(int i=0; i<n-1; i++){
				for(int j=i+1; j<n; j++){
					if(ds[i]->get_Mucgia() > ds[j]->get_Mucgia()){
						ve* temp = ds[i];
						ds[i] = ds[j];
						ds[j] = temp;
					}
				}
			}
		}
		float TongTien(){
			float tong = 0;
			for(int i = 0; i < n; i++){
				tong += ds[i]->get_Mucgia();
			}
			return tong;
		}
		float TongTien300(){
			float tong = 0;
			for(int i = 0; i < n; i++){
				if(ds[i]->get_Dodaiht() > 300){
					tong += ds[i]->get_Mucgia();
				}
			}
			return tong;
		}
		void Menu(){
			while (true){
				cout <<"\t\tNhap lua chon: "<<endl;
				cout <<"1. Nhap Ds: "<<endl;
				cout <<"2. Xuat Ds: "<<endl;
				cout <<"3. Sap xep theo gia ve: "<<endl;
				cout <<"4. Tinh tong tien ve: "<<endl;
				cout <<"5. Tinh tong tien ve neu do dai hanh trinh > 300: "<<endl;
				cout <<"6. Thoat: "<<endl;
				int luachon;
				cout <<"Nhap lua chon: ";
				cin >>luachon;
				if(luachon == 1){
					NhapDs();
				}
				else if(luachon == 2){
					XuatDs();
				}
				else if(luachon == 3){
					SapXep();
				}
				else if(luachon == 4){
					cout << "Tong tien ve: " << TongTien() << endl;
				}
				else if(luachon == 5){
					cout << "Tong tien ve neu do dai hanh trinh > 300: " << TongTien300() << endl;
				}
				else if(luachon == 6){
					break;
				}
				else{
					cout << "Lua chon khong dung!" << endl;
				}
			}
		}
};

int main(){
    ql *b = new ql();
    b->Menu();
    delete b;
    return 0;
};
	
