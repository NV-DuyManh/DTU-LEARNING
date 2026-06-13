#include<iostream>
using namespace std;

int main() {
	int n;
	cout <<"Nhap n = ";
	cin >> n;
	double T=0,P=0,M;
	for (int i =1;i<=n;i++) {    //T= 1 + 1/(1+2)+.....+1/(1+2+3+....+n)
		P=P+i;
		M=1.0/P;
		T=T+M;
	}
	cout <<"Tong cua T = " << T;
	return 0;
}
