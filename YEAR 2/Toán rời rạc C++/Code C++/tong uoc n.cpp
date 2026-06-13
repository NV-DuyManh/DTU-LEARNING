#include <iostream> 
using namespace std;

int uoc(int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			sum+=i;
		}
	}return sum; 

}
int main(){
	int n;
	do{
cout <<"Nhap so nguyen n: ";
cin>>n;
cout<<"Tong uoc cua n la: "<<uoc(n)<<endl;
}while(n>0);
return 0; 
}
