#include<iostream>
#include<cmath>
using namespace std;

struct toado {
    double x;
    double y;
};

void nhap(toado &td){
	cout <<"+ nhap x: ";
	cin >>td.x;
	cout <<"+ nhap y: ";
	cin>>td.y;
}
void xuat(toado td){
	cout <<"("<<td.x<<","<<td.y<<")"<<endl;
}
double tinhtoado(toado a, toado b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    toado A, B, C;

    cout << "-- Nhap toa do diem A: "<<endl;
    nhap(A);

    cout << "-- Nhap toa do diem B: "<<endl;
    nhap(B);

    cout << "-- Nhap toa do diem C: "<<endl;
    nhap(C);

    double AB = tinhtoado(A, B);
    double BC = tinhtoado(B, C);
    double AC = tinhtoado(A, C);

    cout << "==> Do dai canh AB: " << AB << endl;
    cout << "==> Do dai canh BC: " << BC << endl;
    cout << "==> Do dai canh AC: " << AC << endl;
    
    xuat(A);
    xuat(B);
    xuat(C);

    return 0;
}
