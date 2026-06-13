#include<bits/stdc++.h>
using namespace std;
int nhan(int a){
	int s=0;
	while(a<0){
	a=a*2;  //a=a+a hay a=a*2
	}
	return s;
}
int main(){
	
	int a;
	cin>>a;
//	long a = 9795795, b=83837;
	cout<<nhan(a);
}
