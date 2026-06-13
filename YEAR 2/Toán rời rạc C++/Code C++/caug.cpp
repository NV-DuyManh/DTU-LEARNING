//g.	Tính t?ng S= 1/2+ 1/2.3 +1/3.4 + ... + 1/n(n+1)
#include <iostream>
using namespace std;
double Sum(int n) {
    if (n == 1) 
        return 1.0 / 2; 
    else{
    	return Sum(n - 1) + 1.0 / (n * (n + 1)); 
	}
}
int main() {
    int n;
    do{
    	cout << "Nhap n: ";
        cin >> n;
    cout << "Tong S = " << Sum(n) << endl;
	}while(n>1);
       return 0;
}

