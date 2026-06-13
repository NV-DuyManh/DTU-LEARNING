#include <iostream>
using namespace std;

struct SinhVien{
	string ho_ten;
	int tuoi;
	float diem;
};
typedef struct SinhVien SINHVIEN;
void Nhap_Thong_Tin (SINHVIEN &x) {
	fflush(stdin);
	cout <<"+ nhap ten:";
	getline(cin,x.ho_ten);
	cout <<"+ nhap tuoi: ";
	cin>>x.tuoi;
	cout <<"+ nhap diem: ";
	cin>>x.diem;
	
}
void Xuat_Thong_Tin (SINHVIEN x){
	cout <<"Ho ten: " <<x.ho_ten<<" - Tuoi: "<<x.tuoi<< " - Diem: "<<x.diem;
}
int main(){
	SINHVIEN sv1;
	SINHVIEN sv2;
	cout <<"-- Nhap thong tin sv1: "<<endl;
	Nhap_Thong_Tin(sv1);
	cout<<"   ==> Xuat thong tin sv1: "<<endl;
	Xuat_Thong_Tin(sv1);
	cout<<endl;
	cout <<"-- Nhap thong tin sv2: "<<endl;
	Nhap_Thong_Tin(sv2);
	cout<<"   ==> Xuat thong tin sv2: "<<endl;
	Xuat_Thong_Tin(sv2);
	
	return 0;
}
