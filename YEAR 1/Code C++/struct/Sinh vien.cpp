#include <iostream>
using namespace std;

struct SinhVien{
	string Mssv, Hoten, Diachi;
	float diemLTCS, diemLTHDT, diemCSDL;
};

void nhap(SinhVien &sv){
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

float diemTB(SinhVien sv){
	return (sv.diemLTCS + sv.diemLTHDT + sv.diemCSDL) / 3;
}

void xeploai(SinhVien sv){
	float dtb = diemTB(sv);
	if (dtb >= 8.5){
		cout <<"Gioi";
	}
	else if (dtb >= 7){
		cout <<"Kha";
	}
	else if (dtb >= 5){
		cout <<"Trung binh";
	}
	else {
		cout << "Yeu";
	}
}

void xuat(SinhVien sv){
	cout <<sv.Mssv<<" || "<<sv.Hoten<<" || "<<sv.Diachi<<" || "<<sv.diemLTCS<<" || "<<sv.diemLTHDT<<" || "<<sv.diemCSDL<<" || ";
	xeploai(sv);
	cout <<endl;
}

void sapxep(SinhVien ds[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(diemTB(ds[i]) > diemTB(ds[j])){
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void nhapsoluong(SinhVien ds[],int n){
	for (int i=0;i<n;i++){
		cout <<"Nhap sinh vien thu "<<i+1<<" la: "<<endl;
		nhap(ds[i]);
	}
}

void xuatds(SinhVien ds[],int n){
	cout <<"Danh sach sinh vien la: "<<endl;
	for (int i=0;i<n;i++){
		cout <<"Sinh vien thu "<<i+1<<" la: ";
		xuat(ds[i]);
	}
}

int main(){
	int n;
	cout <<"Nhap so luong sinh vien: ";
	cin >>n;
	SinhVien ds[100];
	nhapsoluong(ds,n);
	sapxep(ds,n);
	xuatds(ds,n);
	
	return 0;
}

