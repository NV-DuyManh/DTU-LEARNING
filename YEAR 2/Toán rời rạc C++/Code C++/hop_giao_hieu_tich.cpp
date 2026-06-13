#include <iostream>
#include <algorithm>
using namespace std;

void Hop(int A[], int n, int B[], int m) {
    int result[n + m], k = 0;
    for (int i = 0; i < n; i++) result[k++] = A[i];
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) result[k++] = B[i];
    }
    sort(result, result + k);
    cout << "Hop cua A va B la: ";
    for (int i = 0; i < k; i++) cout << result[i] << " ";
    cout << endl;
}

void Giao(int A[], int n, int B[], int m) {
    cout << "Giao cua A va B la: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                cout << A[i] << " ";
                break;
            }
        }
    }
    cout << endl;
}

void Hieu(int A[], int n, int B[], int m) {
    cout << "Hieu cua A va B la: ";
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) cout << A[i] << " ";
    }
    cout << endl;
}

void Tich(int A[], int n, int B[], int m) {
    cout << "Tích Descartes cua A va B la: { ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "(" << A[i] << ", " << B[j] << ") ";
        }
    }
    cout << "}" << endl;
}

int main() {
    int n, m, choice;
    cout << "Nhap so luong phan tu tap hop A: ";
    cin >> n;
    int A[n];
    cout << "Nhap cac phan tu tap hop A:\n";
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Nhso luong phan tu tap hop B: ";
    cin >> m;
    int B[m];
    cout << "Nhap cac phan tu tap hop B:\n";
    for (int i = 0; i < m; i++) cin >> B[i];

    sort(A, A + n);
    sort(B, B + m);

    do {
        cout << "\nMenu:\n";
        cout << "1. Tinh hop\n";
        cout << "2. Tinh giao\n";
        cout << "3. Tinh hieu\n";
        cout << "4. Tinh tich Descartes\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Hop(A, n, B, m);
                break;
            case 2:
                Giao(A, n, B, m);
                break;
            case 3:
                Hieu(A, n, B, m);
                break;
            case 4:
                Tich(A, n, B, m);
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 0);

    return 0;
}
	
