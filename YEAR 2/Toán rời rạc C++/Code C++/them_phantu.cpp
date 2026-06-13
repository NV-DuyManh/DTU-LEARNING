#include <iostream>
using namespace std;

void themPhanTu(int A[], int& n, int x) {
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            cout << "Phan tu " << x << " da co trong tap A, khong the them.\n";
            return;
        }
    }
    A[n++] = x;
    cout << "Da them phan tu " << x << " vao tap A.\n";
}

int main() {
    int n, x, luaChon;

    cout << "Nhap so phan tu cua tap A: ";
    cin >> n;
    int A[100]; 
    cout << "Nhap cac phan tu cua tap A:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    do {
        cout << "\nChon thao tac:\n";
        cout << "1. Them phan tu vao tap A\n";
        cout << "2. Xem tap A\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "Nhap phan tu x can them: ";
                cin >> x;
                themPhanTu(A, n, x);
                break;

            case 2:
                cout << "Tap A hien tai: ";
                for (int i = 0; i < n; i++) {
                    cout << A[i] << " ";
                }
                cout << endl;
                break;

            case 0:
                cout << "Ket thuc chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    } while (luaChon != 0);

    return 0;
}

