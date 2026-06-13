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
	int K=0;							//T= x + x^2/(1+2) + x^3/(1+2+3) +....+x^n/(1+2+...+n)
	for (int i =1;i<=n;i++) {
		K=K+i;
		T = T + pow(x,i) /K;
	}
	cout <<"Tong cua T = " << T;
	return 0;
}
