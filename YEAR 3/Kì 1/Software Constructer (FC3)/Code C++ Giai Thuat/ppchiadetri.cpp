#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long xmun(long long x, long long n) { //De quy
	if (n == 0) return 1;
	else if (n % 2 != 0) return x * (xmun(x, n - 1)%MOD) %MOD;
	else {
		long long kq = xmun(x, n / 2) % MOD;
		return (kq * kq) % MOD;
	}	

}
 long long xmun1(long long x,long long n){ 
 	long long s=1;
 	while(n>0){
 		if(n%2==1)s=s*x%MOD;   
 		n=n/2;
 		if(n>0)x=x*x%MOD;
	 }return s;
 }


int main() {
	long long x, n;
	cin >> x >> n;
	cout << xmun1(x, n);
}

