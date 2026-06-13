#include<iostream>
using namespace std;

int kq[100],chon[100],v[100],n,dem=0;
void khoitao(){ for(int i=0;i<n;i++){
    cin>>v[i];
    chon[i]=kq[i]=0;
}
}

//void inkq(){
//	cout<<++dem;
//	for(int j=0;j<n;j++)cout<<" "<<kq[j];
//}
void tim(int i, int d){
	if(i>n)dem++;            //neu da du het n binh xang thi in kq 
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
	int d; 
	cin>>n>>d; 
	khoitao(); 
	tim(1,d); 
	cout<<dem; 
	return 0;
//	cout<<"\n Xong!";
}
