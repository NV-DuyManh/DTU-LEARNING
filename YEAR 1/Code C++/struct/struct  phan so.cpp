#include <iostream>
using namespace std;

struct phanso{
	double tu,mau;
};

void nhap(phanso &ps){
	cout <<"+nhap tu: ";
	cin >> ps.tu;
	do {
		cout <<"+nhap mau: ";
		cin>> ps.mau;
		if(ps.mau == 0){
			cout <<"Mau phai khac 0. Vui long nhap lai!\n";
		}
	} while(ps.mau == 0);
}

void xuat (phanso ps){
	cout <<"Phan so da nhap la: "<<ps.tu<<"/"<<ps.mau<<endl;
}

int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void rutgon(phanso &ps){
	int ucln = UCLN(ps.tu, ps.mau);
	ps.tu /= ucln;
	ps.mau /= ucln;
}

phanso tongsp(phanso ps1,phanso ps2){
	phanso tong;
	tong.tu= ps1.tu*ps2.mau  + ps1.mau*ps2.tu;
	tong.mau= ps1.mau * ps2.mau;
	rutgon(tong);
	return tong;
}
phanso tichsp(phanso ps1,phanso ps2){
	phanso tich;
	tich.tu= ps1.tu*ps2.tu;
	tich.mau= ps1.mau * ps2.mau;
	rutgon(tich);
	return tich;
}

int main (){
	phanso A,B;
	cout <<"nhap phan so thu nhat: "<<endl;
	nhap(A);
	cout <<"nhap phan so thu hai: "<<endl;
	nhap(B);
	xuat(A);
	xuat(B);
	cout <<"phan so thu nhat sau khi rut gon la: ";
	rutgon(A); 
	xuat(A);
	cout <<"phan so thu hai sau khi rut gon la: ";
	rutgon(B);
	xuat(B);
	cout <<"tong hai so la: ";
	xuat(tongsp(A,B));
	cout <<"tich hai so la: ";
	xuat(tichsp(A,B));
 
	return 0;
}

