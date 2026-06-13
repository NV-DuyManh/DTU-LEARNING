#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int x,n,T=0;
	cout <<"Nhap x = ";
	cin >> x;
	cout <<"Nhap n = ";      //T=x + x^3 + x^5 + .... + x^2n+1
	cin >>n;
	for(int i=0;i<=n;i++){
		T=T+ pow(x,2*i+1);
	}
	cout <<"Tong cua T =" << T;
	return 0;
}
