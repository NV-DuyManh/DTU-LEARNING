//Bài 60: Hãy kiem tra các chu so cua so nguyên duong n có tang dan tu trái sang phai hay không
#include <iostream>
using namespace std;
bool isIncreasingDigits(int n) {
    int lastDigit = n % 10;
    n /= 10;
    while (n > 0) {
        int currentDigit = n % 10;
        if (currentDigit >= lastDigit) {
            return false; 
        lastDigit = currentDigit;
        n /= 10;
    }
    return true; 
}
}
int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if (isIncreasingDigits(n)) {
        cout << n << " co cac chu so tang dan." << endl;
    } else {
        cout << n << " khong co cac chu so tang dan." << endl;
    }
    return 0;
}

