#include<bits/stdc++.h>
using namespace std;

string X,Y;
int LCS(int m, int n){
	if(m==0||n==0)return 0;
	else if(X[m-1]==Y[n-1])return 1+LCS(m-1,n-1);
	else return max(LCS(m-1,n),LCS(m, n-1));
}

int main(){
	X="DBAXDA"; Y="ABADCA";
	int m=X.length();
	int n=Y.length();
	long t1,t2,kq;
	t1=clock();
	kq=LCS(m,n);
	t2=clock();
	cout<<"\n Do dai chuoi con chung dai nhat la: "<<kq;
	cout<<"\n Thoi gian tinh toan la = "<<(t2-t2);
}
