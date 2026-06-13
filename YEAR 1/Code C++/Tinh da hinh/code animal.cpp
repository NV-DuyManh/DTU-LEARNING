#include<iostream>
using namespace std;

class Animal{
	protected:
		float cannang;
    	string tenGOI;
	public:
		Animal(){
		}
		Animal(float cannang, string tenGoi){
			this->cannang = cannang;
			this->tenGOI = tenGoi;
		}
		virtual ~Animal(){
		}
	float get_cannang(){
		return this->cannang;
	}
	string get_tenGoi(){
		return this->tenGOI;
	}
	void set_cannang(float cannang){
		this->cannang= cannang;
	}
	void set_tenGoi(string tenGoi){
		this->tenGOI = tenGoi;
	}
	virtual void Input(){
		fflush(stdin);
		cout <<"Nhap can nang: ";
		cin >>this->cannang;
		fflush(stdin);
		cout <<"Nhap ten goi: ";
		getline(cin, this->tenGOI);
	}
	virtual void Output(){
		cout <<"Can nang: "<<this->cannang <<endl;
		cout <<"Ten goi: "<<this->tenGOI <<endl;
		an();
	    diChuyen();
	}
	void an(){
		cout <<"Dong vat dang an "<<endl;
	}
	void diChuyen(){
		cout <<"Dong vat dang di chuyen "<<endl;
	}
}; 

class Cat : public Animal{
	private:
		string mauLong, mauMat;
	public:
		Cat(){
		}
		Cat(float cannang, string tenGoi, string mauLong, string mauMat):Animal(cannang, tenGoi){
			this->mauLong = mauLong;
			this->mauMat = mauMat;
		}
		~Cat(){
		}
	string get_mauLong(){
		return this->mauLong;
	}
	string get_mauMat(){
		return this->mauMat;
	}
	void set_mauLong(string mauLong){
		this->mauLong = mauLong;
	}
	void set_mauMat(string mauMat){
		this->mauMat = mauMat;
	}
	void Input(){
		Animal::Input();
		fflush(stdin);
		cout <<"Nhap mau long: ";
		getline(cin, this->mauLong);
		cout <<"Nhap mau mat: ";
		getline(cin, this->mauMat);
	}
	void Output(){
		Animal::Output();
		cout <<"Mau long: "<<this->mauLong<<endl;
		cout <<"Mau mat: "<<this->mauMat<<endl;
		batChuot();
		leoCay();
	}
	void batChuot(){
		cout <<"Meo dang bat chuot "<<endl;
	}
	void leoCay(){
		cout <<"Meo dang leo cay "<<endl;
	}
};
class Fish : public Animal{
	private:
		string kieuVay, loaiNuoc;
	public:
		Fish(){
		}
		Fish(float cannang, string tenGoi, string kieuVay, string loaiNuoc):Animal(cannang, tenGoi){
			this->kieuVay = kieuVay;
			this->loaiNuoc = loaiNuoc;
		}
		~Fish(){
		}
	string get_kieuVay(){
		return this->kieuVay;
	}
	string get_loaiNuoc(){
		return this->loaiNuoc;
	}
	void set_kieuVay(string kieuVay){
		this->kieuVay = kieuVay;
	}
	void set_loaiNuoc(string loaiNuoc){
		this->loaiNuoc = loaiNuoc;
	}
	
	void Input(){
		Animal::Input();
		fflush(stdin);
		cout <<"Nhap kieu vay: ";
		getline(cin, this->kieuVay);
		cout <<"Nhap loai nuoc: ";
		getline(cin, this->loaiNuoc);
	}
	void Output(){
		Animal::Output();
		cout <<"Kieu vay: "<<this->kieuVay<<endl;
		cout <<"Loai nuoc: "<<this->loaiNuoc<<endl;
		boi();
	}
	void boi(){
		cout <<"Ca dang boi"<<endl;
	}
};
class manager {
	private:
		Animal *ds[1000];
		int n;
	public:
		manager(){
			this->n = 0;
		}
		~manager(){
			for(int i=0;i<n;i++){
				delete ds[i];
			}
		}
		void NhapDs(){
			while(true){
				cout <<"\t\t\tNhap loai dong vat: "<<endl;
				cout <<"\t\t1. Nhap meo: "<<endl;
				cout <<"\t\t2. Nhap ca: "<<endl;
				cout <<"\t\t3. Thoat: "<<endl;
				int nhap;
				cout <<"\t==>Nhap lua chon: ";
				cin >>nhap; 
				if(nhap == 1){
					Cat *cat = new Cat();
					cat->Input();
					ds[n]= cat;
					n++;
				}
				else if(nhap == 2){
					Fish *fish = new Fish();
					fish->Input();
					ds[n]= fish;
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
				cout <<"Thong tin dong vat thu "<<i+1<<" la: "<<endl;
				ds[i]->Output();
			}
		}
	
	
		void Menu(){
			while (true){
				cout <<"\t\t\t===Menu=== "<<endl;
				cout <<"\t\t1. Nhap Ds: "<<endl;
				cout <<"\t\t2. Xuat Ds: "<<endl;
				cout <<"\t\t3. Thoat: "<<endl;
				int luachon;
				cout <<"\t==>Nhap lua chon: ";
				cin >>luachon;
				if(luachon == 1){
					NhapDs();
				}
				else if(luachon == 2){
					XuatDs();
				}
				else if(luachon == 3){
					break;
				}
				else{
					cout << "Lua chon khong dung!" << endl;
				}
			}
		}
};


int main(){
    manager *b = new manager();
    b->Menu();
    delete b;
    return 0;
};
	
