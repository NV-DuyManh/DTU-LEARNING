// Hãy tìm so dao nguoc cua so nguyên duong n
#include <iostream>
using namespace std;
int main (){
	int n;
	cout <<"Nhap so nguyen duong:";
	cin >> n;
	if (n<=0){
		cout <<"Nhap khong hop le. Vui long nhap so nguyen duong." << endl;
		return 1;
		}
		int a;
	while (n>0){
		int i = n%10;
		a=a*10+i;
		n/=10;
	}
	cout <<"So dao nguoc cua so n la:"<<a<< endl;
	return 0;
	}
