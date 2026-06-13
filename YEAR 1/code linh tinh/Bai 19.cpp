#include<iostream>
#include<math.h>
using namespace std;

long long giai_thua(int n) {
    long long gt = 1;
    for(int i = 1; i <= n; i++) {
        gt = gt * i;
    }
	return gt;
}

int main() {
    int x,n;
    cout << "Nhap x: ";  					//S=1 + x + x^3/3! + x^5/5! + … + x^(2n+1)/(2n+1)!
    cin >> x;
    cout << "Nhap n: ";
    cin >> n;
    double S = 1;
    for(int i = 0; i <= n; i++) {
        S = S + pow(x, 2 * i +1) / giai_thua(2 * i + 1);
    }
    cout << "Tong cua S =  " << S;
    return 0;
}

