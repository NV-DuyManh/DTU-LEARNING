#include <iostream> 
#include <math.h>
using namespace std;
bool nt(int n); 
int main (){
	int n;
	cout <<"enter n: ";
	cin >>n;
	if(n<=0){
		cout <<"errror";
		return 1;
	}
	if(nt(n)){
		cout <<n << " la snt" ;
	}	else {
		cout <<n<<"   	k pk snt"; 
	}
	return 0; }
	bool nt(int n){
	
	for (int i =2; i<=sqrt(n);i++) {
	if (n%i==0){
		return false;
		
	}	
	}
	return true;}

