#include<iostream>
using namespace std;
class NhanVien{
	private:
		string MaNV, HoTen, DiaChi;
    	float LuongCB, TamUng;
	    int NamCT;
	public:
		NhanVien(){
			this->MaNV = " ";
			this->HoTen = " ";
			this->DiaChi = " ";
			this->LuongCB = 0;
			this->NamCT = 0;
			this->TamUng = 0;
		};
		NhanVien(string MaNV,string HoTen, string DiaChi, float LuongCB,float TamUng, int NamCT){
			this->MaNV = MaNV;
			this->HoTen = HoTen;
			this->DiaChi = DiaChi;
			this->LuongCB = LuongCB;
			this->NamCT = NamCT;
			this->TamUng = TamUng;
		};
	~NhanVien(){
	};
	string get_MANV(){
		return this->MaNV;
	};
	string get_HOTEN(){
		return this->HoTen;
	};
	string get_DIACHI(){
		return this->DiaChi;
	};
	float get_LUONGCB(){
		return this->LuongCB;
	};
	int get_NAMCT(){
		return this->NamCT;
	};
	void set_MANV(string MaNV){
		MaNV = MaNV;
	};
	void set_HOTEN(string HoTen){
		HoTen = HoTen;
	};
	void set_DIACHI(string DiaChi){
		DiaChi = DiaChi;
	};
	void set_LUONGCB(float LuongCB){
		LuongCB = LuongCB;
	};
	void set_NAMCT(int NamCT){
		NamCT = NamCT;
	};
	void set_TAMUNG(float TamUng){
		TamUng = TamUng;
	};
	void Nhap(){
		fflush(stdin);
		cout << "Nhap ma nhan vien: ";
		getline(cin, this->MaNV);
		cout << "Nhap ho va ten nhan vien: ";
		getline(cin, this->HoTen);
		cout << "Nhap dia chi: ";
		getline(cin, this->DiaChi);
		cout << "Nhap luong co ban: ";
		cin >> this->LuongCB;
		cout << "Nhap nam cong tac: ";
		cin >> this->NamCT;
		cout << "Nhap tien tam ung: ";
		cin >> this->TamUng;
	};
	
	float TinhThuong(){
		
		if ( 3<= this->NamCT <=5){
		    int TienThuong = this->LuongCB * 20/100;
		}
		else if( this->NamCT >5){
			int TienThuong = this->LuongCB * 50/100;
		}
		else{
			cout <<"Khong co thuong!";
		}
	};
	float TinhThucLinh(){
		int ThucLinh = this->LuongCB + TinhThuong() - this->TamUng;
	};
	
	void HienThi(){
		cout <<"Mã nhan vien: "<< this->MaNV <<endl;
		cout <<"Ho và tên nhan vien : "<< this->HoTen <<endl;
		cout <<"Dia chi: "<< this->DiaChi <<endl;
		cout <<"Luong co ban: "<< this->LuongCB <<endl;
		cout <<"Nam cong tac: "<< this->NamCT <<endl;
		cout <<"Tien tam ung: "<< this->TamUng <<endl;
		cout <<"Tien thuong: "<<TinhThuong() <<endl;
		cout <<"Thuc Linh: "<<TinhThucLinh()<<endl;
	};

};
class DSNhanVien{
	private:
		int n;
		NhanVien *ds[1000];
	public:
		DSNhanVien(){
			this->n = 0;
		};
		DSNhanVien(int n){
			this->n = n;
		};
	~DSNhanVien(){
		for(int i=0;i<n;i++){
			delete ds[i];
		}
	};
	int get_N(){
		return n;
	};
	void set_N(int n){
		n=n;
	};
	void NhapDS(){
		do{
			cout<<"Nhap so luong nhan vien: ";
			cin>>n;
			if(n<=0 || n>1000){
				cout <<"Nhap lai!!"<<endl;
			}
		}while(n<=0 || n >1000);
		for(int i =0;i<n; i++ ){
			cout <<"Nhap nhan vien thu "<<i+1<<":"<<endl;
			ds[i] = new NhanVien();
			ds[i]->Nhap();
     	};
	};
	float TongThucLinh(){
		float tong = 0;
		for(int i = 0; i<n;i++){
			tong = tong + ds[i]->TinhThucLinh();
		}
		return tong;
	}
	void SapXep(){
		for(int i = 0; i<n; i++){
			for(int j=i+1;j<n;j++){
				if(ds[i]->TinhThucLinh()<ds[j]->TinhThucLinh()){
					NhanVien *tam=ds[i];
					ds[i] = ds[j];
					ds[j] = tam;
				}
			}
		}
	}
	void HienThiDS(){
		if(n>0){
	
		for(int i=0; i<n; i++){
			cout <<"Thong tin nhan vien thu "<<i+1<<":"<<endl;
			ds[i]->HienThi();}
		}
		else{
			
		}
	}
	void Menu(){
		while(true){
			cout <<"\t\t====Menu===="<<endl;
			cout<<"1. Nhap ds: "<<endl;
			cout<<"2. Hien thi ds: "<<endl;
			cout<<"3. Sap xep: "<<endl;
			cout<<"4. Tong thuc linh: "<<endl;
			cout <<"5. Thoat: "<<endl;
			int luachon;
			cout <<"\t\tNhap lua chon: ";
			cin>>luachon;
			if(luachon == 1){
				NhapDS();
			}else if(luachon == 2){
				cout <<"\t==Danh sach nhan vien=="<<endl;
				HienThiDS();
			}else if(luachon == 3){
				SapXep();
				HienThiDS();
			}else if(luachon == 4){
				cout<<"\tTong thuc linh la: "<<TongThucLinh() <<endl;
			}else if(luachon == 5){
				break;
			}else{
				cout << "\tLua chon ko dung. Vui long nhap lai!" << endl;
			}
		}
		
	}
	
};
int main(){
	DSNhanVien *ds = new DSNhanVien();
	ds->Menu();
	delete ds;
	return 0;
	}

