#include<bits/stdc++.h>
using namespace std;
int m,n,a[100][100],h[100],c[100],d=0,dem=0;
void docfile(){
	ifstream fi("D:\\pikachu.txt");
	fi>>m>>n;
	for(int i =0;i<m;i++){
		for(int j=0;j<n;j++){
			fi>>a[i][j];
		}
	}fi.close();
}
void inmt(){
	for(int i=0;i<m;i++){
		cout<<"\n";
		for(int j=0;j<n;j++)cout<<setw(4)<<a[i][j];
	}
}
void inkq(){
	cout<<"\n Cach thu "<<++dem<<": ";
	for(int i =1; i<=d;i++){
		cout<<"( "<<h[i]<<", "<<c[i]<<" )";
		if(i<d) cout<<" , ";
	}
}
void di(int x, int y){
	d++;h[d]=x; c[d]=y;
	if(y==n-1)inkq();
	else{
		if(x>0 && a[x][y]<a[x-1][y+1])di(x-1,y+1);
		if(a[x][y]<a[x][y+1])di(x, y+1);
		if(x<m && a[x][y]<a[x+1][y+1])di(x+1,y+1);
		
	}h[d]=0;c[d]=0;d--;
}
int main(){
	docfile();
	inmt();
	inkq();
	di(4,4);
}
