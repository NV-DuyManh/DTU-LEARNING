#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rev(int *&a, int l, int r){
	int i=l,j=r;
	while(i<j){
		int t =a[i];
		a[i]=a[j];
		i++;
		j--;
	}
}

using namespace std;
void sinh(int *&a, int n){
	a= new int [n];
	for(int i=0; i<n;i++){
		//a[i]=i;
		a[i]=rand()%10001;
	}
}
void sol2(int *&a,int n, int k){
	rev(a,0,k-1);
	rev(a,k,n-1);
	rev(a,0,n-1);
}
int main(){
	int *a, n=300000,k=50000;
	sinh(a,n);	
	long t1=clock();
	sol2(a,n,k);
	long t2=clock();
	cout<<"\n Thoi gian = "<<t2-t1;
	cout<<"\n xong!";
}
