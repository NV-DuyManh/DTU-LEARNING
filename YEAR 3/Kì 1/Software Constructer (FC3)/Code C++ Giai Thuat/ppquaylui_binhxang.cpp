#include<iostream>
using namespace std;

int kq[100],chon[100],v[100],n,dem=0;
void khoitao(){
	n=8;
	v[0]=5;v[1]=4;v[2]=2;v[3]=7;v[4]=6;v[5]=2;v[6]=3;v[7]=9;
	for(int j=0;j<n;j++)chon[j]=kq[j]=0;
}
void inkq(){
	cout<<"\n Cach thu"<<++dem<<":";
	for(int j=0;j<n;j++)cout<<" "<<kq[j];
}
void tim(int i, int d){
	if(i>n)inkq();            //neu da du het n binh xang thi in kq 
	else
		for(int j=0;j<n;j++){         //duyet het cac binh xang
			if(chon[j]==0 && v[j]>d) {    //neu binh xang chua duoc chon va co the bay khoang cach d
			  	kq[i-1] = v[j]; 
			    chon[j] = 1;
				tim(i+1, v[j]-d);
				kq[i-1]=0; chon[j]=0;
			}
		}
	}


int main(){
	int d =2; 
	khoitao();
	tim(1,d);
	  cout << "\n Tong so cach: " << dem;
	cout<<"\n Xong!";
}
