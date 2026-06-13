//  Hãy tim so luong chu so cua so nguyên duong n

#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    int count = 0;
    while(n != 0) {
        n = n / 10;
        ++count;
    }
    cout << "So luong chu so cua so nguyen duong n la: " << count;
    return 0;
}

