#include <iostream>
using namespace std;
int main(){
	int n;
	int sum=0;
	cout <<"enter n: ";
	cin >> n;
	if (n<=0){
		cout <<"error";
	}
		
	for (int i=1;i<=n;i++){
		if(n%i==0){
			sum+=i;
		}
	}
	cout <<"result: "<<sum;
	return 0;
	}

