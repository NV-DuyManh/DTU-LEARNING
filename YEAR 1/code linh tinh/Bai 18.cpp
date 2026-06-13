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
													//T= 1+ x^2/2! + x^4/4! +.....+ x^2n/(2N)!
int main() {
    int x,n;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap n: ";
    cin >> n;
    double S = 1;
    for(int i = 1; i <= n; i++) {
        S = S + pow(x, 2 * i) / giai_thua(2 * i);
    }
    cout << "Tong cua T = " << S;
    return 0;
}

