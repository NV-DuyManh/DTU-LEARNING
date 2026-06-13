#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void sinh(int *&a, int n){
	a= new int [n];
	for(int i=0; i<n;i++){
		//a[i]=i;
		a[i]=rand()%10001;
	}
}
void in(int *&a, int n){
	cout<<"\n Noi dung mang: ";
	for(int i=0; i<n;i++){
		cout<<" "<<a[i];
	}
}
void sol1(int *&a, int n, int k){
	for(int ll=1; ll<=k;ll++){
		int t=a[0];
		for(int i=0;i<n-1;i++){
			a[i]=a[i+1];
		}a[n-1]=t;
	}
}
int main(){
	int *a, n=300000, k=50000;
	sinh(a,n);
//	in(a,n);
	long t1=clock(); sol1(a,n,k); long t2=clock();
	//in(a,n);
	cout<<"\n Thoi gian = "<<t2-t1;
	cout<<"\nXONG!!";
}
