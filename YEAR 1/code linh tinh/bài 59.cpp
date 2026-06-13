//Hãy kiem tra so nguyên duong n có phai là so doi xung hay không
#include <iostream>
using namespace std;
bool Palindrome(int n) {
    int so_ban_dau = n;
    int so_dao_nguoc = 0;
    while (n > 0) {
        int digit = n % 10;
        so_dao_nguoc = so_dao_nguoc * 10 + digit;
        n /= 10;
    }
    return so_ban_dau == so_dao_nguoc;
}
int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if (Palindrome(n)) {
        cout << n << " la so doi xung." << endl;
    } else {
        cout << n << " khong phai la so doi xung." << endl;
    }
    return 0;
}

