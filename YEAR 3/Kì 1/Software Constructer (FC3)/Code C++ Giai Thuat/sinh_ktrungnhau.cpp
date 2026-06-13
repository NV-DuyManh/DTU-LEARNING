#include<bits/stdc++.h>
using namespace std;

void sinh_khong_trung_nhau(int *&a, int n){
	vector <int> b(n);
	a= new int[n];
	for(int i=0;i<n;i++)b[i]=i+1;
	for(int i=0;i<n;i++){
		int x = rand()%b.size();
		a[i]=b[x];
		b.erase(b.begin()+x);
	}
	cout<<"\n DAY SINH: \t";
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}

void dem_cap(int *a, int n,int k){
	int dem=0;
    for(int i=0;i<n-1;i++)
    	for(int j = i+1;j<n;j++)   
	    	if(a[i]+a[j]==k) dem++;
	cout << dem;
}
void in(int *a, int n){
	cout<<"\n Noi dung mang: ";
	for(int i=0; i<n-1;i++)cout<<a[i]<<" ";
}
int main(){
	int *a, n=10; 
	sinh(a,n);
}

