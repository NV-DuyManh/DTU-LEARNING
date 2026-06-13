#include<bits/stdc++.h>
using namespace std;
int n=0,*d;
//void docfile(){
//	fstream fi("D:\\MMATRIX.txt");
//	if(fi==NULL)cout<<"\n Khong doc duoc file!";
//	else{
//		fi>>n;d=new int [n+1];
//		for(int i=0; i<=n;i++)fi>>d[i];
//		fi.close();cout<<"\nDoc xong file!";
//	}
//}
//
//int tinh(int i,int j) {
//	if(i==j)return 0;
//	else if(j==(i+1))return d[i-1]*d[i]*d[i+1];
//	else {
//		int dem=INT_MAX;
//		for(int k=i; k<j; k++) {
//			int h=(tinh(i,k)+tinh(k+1,j)+d[i-1]*d[k]*d[j]);
//			if(h<dem)dem=h;
//		}
//		return dem;
//	}
//}

int FF_F(int d[], int n){
	int F[n+1][n+1];      //vector<vector<int>>F(n+1, vector<int>(n+1,0));
	for(int len=2; len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			F[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				int p=F[i][k]+F[k+1][j]+d[i-1]*d[k]*d[j];
				F[i][j]=min(F[i][j],p);
			}
		}
	}return F[1][n];
	
	
}	


int main() {
	cin>>n;
	d=new int [n+1];
	for(int i=0; i<=n; i++) {
		cin>>d[i];
	}

	cout<<FF_F(d,n);
}

