#include <iostream>
using namespace std;
int Nhiphan(int n){
	if(n==0){
		return 0;
	}else{
		Nhiphan(n/2);
		cout<<n%2;
	}
}
int main(){
	int n;
	do{
		cout<<"\nCho bien n: ";
		cin>>n;
		cout<<"\nDay nhi phan la: ";
		Nhiphan(n);
	}while(n>0);
	return 0; 
}
