#include <iostream>
using namespace std;


int kq[100],chon[100],v[100],n,dem=0;



void khoitao() {
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}
void phantich(int ll){
	
	if(ll=0)dem++;
	
	else{
		for(int i=0;i<n;i++){
			if(ll>=b[i]){
				sb++;
				m[sb]=b[i];
				phantich(ll-b[i]);
				sb--;
			}
		}
	}
} 
void tim(int i, int d){
	if(i>n)dem++;         
	else
		for(int j=0;j<n;j++){         
			if(chon[j]==0 && v[j]>d) {    
			  	kq[i-1] = v[j]; 
			    chon[j] = 1;
				tim(i+1, v[j]-d);
				kq[i-1]=0; chon[j]=0;
			}
		}
}

int main() {
    cin >> n >> k;
    khoitao();
    tim(0);
    cout << dem;
    return 0;
}

