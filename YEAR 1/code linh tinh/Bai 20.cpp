//Liet ke tat ca cac uoc so cua so nguyen duong n

#include<iostream>
using namespace std;

int main() {
	int n;
	cout <<"Nhap n = ";
	cin >>n;
	if (n<0) {
		cout <<"Errol!";
	}
	cout <<"Cac uoc so cua " <<n <<" la : ";
	for (int i=1;i<=n;i++) {
		if(n%i==0) {
			cout <<i << " ";
		}
	}
	return 0;
}
