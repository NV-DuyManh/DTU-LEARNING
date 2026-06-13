#include<bits/stdc++.h>
using namespace std;
long long nhan(long long a, long long b){
	long long s=0;
	while(b>0){
		if(b&1)s=s+a; // b&1 <=> b%2==1 
		b=b>>1;  //b=b/2
		if(b>0)a=a<<1;  //a=a+a hay a=a*2
	}
	return s;
}
int main(){
	long a,b;
	cin>>a>>b;
//	long a = 9795795, b=83837;
	cout<<nhan(a,b);
}
