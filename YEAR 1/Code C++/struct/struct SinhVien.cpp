#include <iostream>
using namespace std;

struct SinhVien{
	string Mssv, Hoten, Diachi;
	float diemLTCS, diemLTHDT, diemCSDL;
};

void nhap(SinhVien sv){
	fflush (stdin);
	cout <<"Nhap ma so sinh vien: ";
	getline(cin,sv.Mssv);
	cout <<"Nhap ho ten: ";
	getline(cin,sv.Hoten);
	cout <<"Nhap dia chi: ";
	getline(cin,sv.Diachi);
	cout <<"Diem LTCS: ";
	cin >>sv.diemLTCS;
	cout <<"Diem LTHDT: ";
	cin >> sv.diemLTHDT;
	cout <<"Diem CSDL: ";
	cin >>sv.diemCSDL;
	}

void sapxep (SinhVien sv){
	if (((sv.diemCSDL+sv.diemLTCS+sv.diemLTHDT)/3)>=8.5){
		cout <<"Gioi";
	}
}
int main(){
	SinhVien sv;
	nhap(sv);
	return 0;
}
