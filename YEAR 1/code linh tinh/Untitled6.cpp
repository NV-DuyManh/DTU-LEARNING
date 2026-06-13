#include <iostream>
using namespace std;
 int sum(int n){
 	int b=0; 
 	for (int i =1;i<=n;i++){
 		int a =0;
 		for (int j=1; j<=i/2;j++){
 			if (i%j==0){
 				a+=j;
			 }
		 }
		 if (a==i){
		 	 b+=i;
		 }
		 
	 } return b; 
 }


int main (){
	int n;
	cout <<"enter n: "; 
	cin >>n;
	if (n<=0){
		cout <<"nhap lai";
		return 1;
	
		
	}
		cout <<"tong cac so hoan thien la:"<<sum(n);
		return 0; 
	
}
