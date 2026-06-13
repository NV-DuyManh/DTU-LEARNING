#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int x,n,T=0;
	cout <<"Nhap x = ";
	cin >> x;
	cout <<"Nhap n = ";
	cin >>n;
	for(int i=1;i<=n;i++){    		//T=x^2 + x^4 +.....+ x^2n
		T=T+ pow(x,2*i);
	}
	cout <<"Tong cua T =" << T;
	return 0;
}
