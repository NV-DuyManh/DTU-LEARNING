#include<bits/stdc++.h>
using namespace std;

//Do phuc tap cua thuat toan la O(m*n)
int find (string T, string S){
	int n =T.length();
	int m =S.length();
	for(int i =0; i<=n-m;i++){
		int j=0;
		while(j<m && T[i+j]==S[j]) j++;
		if(j==m) return i+1;
	}
	return 0;
}


int main(){
	string S,T;
//	cout<<"Nhap chuoi T: ";
	cin>>S>>T;
//	cout<<"Nhap chuoi T: ";

//	cout<<"\n Ket qua tim chuoi S trong chuoi T: ";
	cout<<endl<<find(T,S);
	return 0;
}
