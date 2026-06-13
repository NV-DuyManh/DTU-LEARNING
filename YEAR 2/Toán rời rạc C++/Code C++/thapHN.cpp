#include <iostream>
using namespace std;

void thapHN(int n,char A,char B, char C){
	if(n==1){
		cout <<A<<" --> "<<C<<"\n";
	}else{
		thapHN(n-1,A,C,B);
		cout<<A<<" --> "<<C<<"\n";
		thapHN(n-1,B,A,C);
	}
}
int main(){
	int n;
	cout<<endl<<"Nhap vao so dia N: ";
	cin>>n;
	cout<<"Thu tu dich chuyen cac vi tri A,B,C la: \n";
	thapHN(n, 'A', 'B','C');
	return 0;
}
