#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int x,n;
	cout << "Nhap x = ";
	cin >> x;						
	cout << "Nhap n = ";
	cin >> n;
	double T=0;
	int P=1;								//T= x + x^2/2! +x^3/3! +....+x^n/N!
	for (int i =1;i<=n;i++) {
		P=P*i;
		T = T + pow(x,i) /P;
	}
	cout <<"Tong cua T = " << T;
	return 0;
}
