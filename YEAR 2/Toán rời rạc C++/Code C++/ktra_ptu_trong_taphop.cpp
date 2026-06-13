#include <iostream>
using namespace std;

bool kiemTraPhanTu(int A[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, x, luaChon;

    cout << "Nhap so phan tu cua tap A: ";
    cin >> n;
    int A[n];

    cout << "Nhap cac phan tu cua tap A:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    do {
        cout << "\nChon thao tac:\n";
        cout << "1. Kiem tra phan tu x co trong tap A\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "Nhap phan tu x can kiem tra: ";
                cin >> x;

                if (kiemTraPhanTu(A, n, x)) {
                    cout << "Phan tu " << x << " co trong tap A.\n";
                } else {
                    cout << "Phan tu " << x << " khong co trong tap A.\n";
                }
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

