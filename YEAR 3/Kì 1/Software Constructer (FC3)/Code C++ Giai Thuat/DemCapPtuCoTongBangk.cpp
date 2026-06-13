#include<bits/stdc++.h>
using namespace std;

void dem_cap(int *a, int n,int k){
	int dem=0;
    for(int i=0;i<n-1;i++)
    	for(int j = i+1;j<n;j++)   
	    	if(a[i]+a[j]==k) dem++;
	cout << dem;
}

int main(){
	int n,k;
	cin>>n>>k;
	int *a = new int[n];
	for(int i=0;i<n;i++) cin>>a[i];
	dem_cap(a,n,k);
	
	return 0;
}

