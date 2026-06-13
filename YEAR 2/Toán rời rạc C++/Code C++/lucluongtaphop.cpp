#include <iostream>
#include <vector>
using namespace std;

int card(int a[], int size){
	int count = 0;
	for(int i=0;i<size;i++){
		bool check = true;
		for(int j=0;j<i;j++){
			if(a[i]==a[j]){
				check=false;
				break;
			}
		}if(check){
			count++;
		}
	}return count;
}
int main(){
	int a[]={1,1,2,2,2,3,4,4,5,6,7,8};
	cout<<"Luc luong cua tap hop la: "<<card(a,12)<<endl;
}
