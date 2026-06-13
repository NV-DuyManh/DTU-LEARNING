#include <iostream>
using namespace std;
int MaxDigit(int n) {
    if (n < 10) 
        return n; 
    else{
        return max(n % 10, MaxDigit(n / 10)); 
		} 
  
}
int main() {
    int n;
    do{
    cout << "Nhap so nguyen duong: ";
    cin >> n;
    cout << "Chu so lon nhat: " << MaxDigit(n) << endl;	
	} while(n>=10) ;
  
    return 0;
}

