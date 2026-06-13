#include<iostream>
using namespace std;

class NhanVien{
	private:
		string hoTen;
		float luongCB;
		int namCT;
		float tamUng;
		//int *p = new int;
	public:
		NhanVien(){
			
		}
		NhanVien(string hoTen, float luongCB, int namCT, float tamUng){
			this->hoTen = hoTen;
			this->luongCB = luongCB;
			this->namCT = namCT;
			this->tamUng = tamUng;
		}
		~NhanVien(){
			//delete p;
		}
		void set_HoTen(string hoTen){
			this->hoTen = hoTen;
		}
		string get_HoTen(){
			return this->hoTen;
		}
		void Nhap(){
			fflush(stdin);
			cout << "Nhap ho ten: ";
			getline(cin, this->hoTen);
			cout << "Nhap luong co ban: ";
			cin >> this->luongCB;
			cout << "Nhap nam cong tac: ";
			cin >> this->namCT;
			cout << "Nhap tam ung: ";
			cin >> this->tamUng;
		}
		float TinhThuong(){
			if(this->namCT >=3 && this->namCT <=5){
				return this->luongCB * 20/100;
			}else if(this->namCT > 5){
				return this->luongCB * 50/100;
			}else{
				return 0;
			}
		}
		float TinhThucLinh(){
			return this->luongCB + TinhThuong() - this->tamUng;
		}
		void HienThi(){
			cout << "Ho ten: " << this->hoTen << endl;
			cout << "Luong co ban: " << this->luongCB << endl;
			cout << "Nam cong tac: " << this->namCT << endl;
			cout << "Tam ung: " << this->tamUng << endl;
			cout << "Tien thuong: " << TinhThuong() << endl;
			cout << "Thuc linh: " << TinhThucLinh() << endl;
		}
};

class DSNhanVien{
	private:
		int n;
		NhanVien *ds[1000];
	public:
		DSNhanVien(){
			this->n = 0;
		}
		~DSNhanVien(){
			for(int i = 0; i < n; i++){
				delete ds[i];
			}
		}
		void NhapDS(){
			do{
				cout << "Nhap so luong nhan vien: ";
				cin >> n;
				if(n <=0 || n > 1000){
					cout << "Nhap lai" << endl;
				}
			}while(n <=0 || n > 1000);
			for(int i = 0; i < n; i++){
				cout << "Nhap thong tin nhan vien thu " << (i+1) << ": " << endl;
				ds[i] = new NhanVien();
				ds[i]->Nhap();
			}
		}
		float TongThucLinh(){
			float tong = 0;
			for(int i = 0; i < n; i++){
				tong = tong + ds[i]->TinhThucLinh();
			}
			return tong;
		}
		void SapXep(){
			for(int i = 0; i < n; i++){
				for(int j = i+1; j < n; j++){
					if(ds[i]->TinhThucLinh() < ds[j]->TinhThucLinh()){
						NhanVien *tam = ds[i];
						ds[i] = ds[j];
						ds[j] = tam;
					}
				}
			}
		}
		void HienThiDS(){
			if(n > 0){
				for(int i = 0; i < n; i++){
					cout << "Thong tin nhan vien thu "  <<(i+1) << ": " << endl;
					ds[i]->HienThi();
				}
			}else{
				cout << "Khong co du lieu nao." << endl;
			}
			
		}
		void Menu(){
			while(true){
				cout << "\t====MENU=====" << endl;
				cout << "1. Nhap ds" << endl;
				cout << "2. Hien thi ds" << endl;
				cout << "3. Sap xep" << endl;
				cout << "4. Tong thuc linh" << endl;
				cout << "5. Thoat" << endl;
				int luachon;
				cout << "Nhap lua chon: ";
				cin >> luachon;
				if(luachon == 1){
					NhapDS();
				}else if(luachon == 2){
					cout << "==Danh sach Nhan vien==" << endl;
					HienThiDS();
				}
				else if(luachon == 3){
					SapXep();
					HienThiDS();
				}
				else if(luachon == 4){
					cout << "Tong thuc linh la: " << TongThucLinh() << endl;
				}
				else if(luachon == 5){
					break;
				}else{
					cout << "Lua chon ko dung. Vui long nhap lai!" << endl;
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
