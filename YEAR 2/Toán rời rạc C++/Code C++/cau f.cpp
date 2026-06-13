//f.	Tính t?ng S= 1/2 +2/3+ 3/4 + ...+ n/ n+1
#include <iostream>
using namespace std;
double Sum(int n) {
    if (n == 1) 
        return 1.0 / 2; 
    else{
    	return Sum(n - 1) + (double)n / (n + 1); 
	}
}
int main() {
    int n;
    do{
    	cout << "Nhap n: ";
        cin >> n;
    cout << "Tong S = " << Sum(n) << endl;
	}while (n>1);
       return 0;
}

