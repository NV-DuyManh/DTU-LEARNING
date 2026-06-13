// Hãy kiem tra so nguyên duong n có toàn chu so chan hay không
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if (n <= 0) {
        cout << "Nhap khong hop le. Vui long nhap so nguyen duong." << endl;
        return 1;
    }
    bool number = true;
    while (n > 0) {
        int i = n % 10;
        if (i % 2 != 0) {
            number = false;
            break;
        }
        n /= 10;
    }
    if (number) {
        cout << "So nguyen n co toan chu so chan." << endl;
    } else {
        cout << "So nguyen n khong toan chu so chan." << endl;
    }

    return 0;
}

