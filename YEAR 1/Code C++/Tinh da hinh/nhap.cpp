#include<iostream>
using namespace std;

class Nhanvien{
	protected:
		string ma,hoten,diachi;
		float luongcb,tamung;
		int namct;
	public:
		Nhanvien(){
		}
		Nhanvien(string ma,string hoten,string diachi, float luongcb, float tamung, int namct){
			this->ma = ma;
			this->hoten = hoten;
			this->diachi = diachi;
			this->luongcb = luongcb;
			this->tamung = tamung;
			this->namct = namct;
		}
		~Nhanvien(){
		}
	string get_ma(){
		return this->ma;
	}
	string get_hoten(){
		return this->hoten;
	}
	string get_diachi(){
		return this->diachi;
	}
	float get_luongcb(){
		return this->luongcb;
	}
	int get_namct(){
		return this->namct;
	}
	float get_tamung(){
		return this->tamung;
	}
	
	void set_ma(string ma){
		this->ma = ma;
	}
	void set_hoten(string hoten){
		this->hoten = hoten;
	}
	void set_diachi(string diachi){
		this->diachi = diachi;
	}
	void set_luongcb(float luongcb){
		this->luongcb = luongcb;
	}
	void set_namct(int namct){
		this->namct = namct;
	}
	void set_tamung(float tamung){
		this->tamung = tamung;
	}
	void Input(){
		fflush(stdin);
		cout<<"Nhap ma: ";
		getline(cin, this->ma);
		cout<<"Nhap hoten: ";
		getline(cin, this->hoten);
		cout<<"Nhap diachi: ";
		getline(cin, this->diachi);
		cout<<"Nhap luongcb: ";
		cin>>this->luongcb;
		cout<<"Nhap namct: ";
		cin>>this->namct;
		cout<<"Nhap tamung: ";
		cin>>this->tamung;
	}
	void Output(){
		cout<<"Ma: "<<this->ma<<endl;
		cout<<"Hoten: "<<this->hoten<<endl;
		cout<<"Diachi: "<<this->diachi<<endl;;
		cout<<"Luong cb: "<<this->luongcb<<endl;
		cout<<"Nam ct: "<<this->namct<<endl;
		cout<<"Tam ung: "<<this->tamung<<endl;
	}
	float Tinhthuong(){
		float tienthuong =0;
		if(3<= this->namct <=5){
			return tienthuong= this->luongcb *20/100;
		}else if(this->namct > 5){
			return tienthuong= this->luongcb *50/100;
		}else{
			return tienthuong = 0;
		}
	}
};







