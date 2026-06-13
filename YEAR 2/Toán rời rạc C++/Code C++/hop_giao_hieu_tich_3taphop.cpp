#include <iostream>
#include <algorithm>
using namespace std;

void hop(int A[], int n, int B[], int m, int result[], int& size) {
    size = 0;
    for (int i = 0; i < n; i++) result[size++] = A[i];
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) result[size++] = B[i];
    }
    sort(result, result + size);
}

void giao(int A[], int n, int B[], int m, int result[], int& size) {
    size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                result[size++] = A[i];
                break;
            }
        }
    }
    sort(result, result + size);
}

void hieu(int A[], int n, int B[], int m, int result[], int& size) {
    size = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) result[size++] = A[i];
    }
    sort(result, result + size);
}

void tichDescartes(int A[], int n, int B[], int m, int C[], int p) {
    cout << "Tich Descartes: { ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                cout << "(" << A[i] << ", " << B[j] << ", " << C[k] << ") ";
            }
        }
    }
    cout << "}" << endl;
}

int main() {
    int n, m, p, choice;

    cout << "Nhap so phan tu cua tap A: ";
    cin >> n;
    int A[n];
    cout << "Nhap cac phan tu cua tap A:\n";
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Nhap so phan tu cua tap B: ";
    cin >> m;
    int B[m];
    cout << "Nhap cac phan tu cua tap B:\n";
    for (int i = 0; i < m; i++) cin >> B[i];

    cout << "Nhap so phan tu cua tap C: ";
    cin >> p;
    int C[p];
    cout << "Nhap cac phan tu cua tap C:\n";
    for (int i = 0; i < p; i++) cin >> C[i];

    sort(A, A + n);
    sort(B, B + m);
    sort(C, C + p);

    int result[100], size;

    do {
        cout << "\nChon thao tac:\n";
        cout << "1. Tinh hop cua A, B, C\n";
        cout << "2. Tinh giao cua A, B, C\n";
        cout << "3. Tinh hieu A - (B ? C)\n";
        cout << "4. Tinh tich Descartes cua A, B, C\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int tempUnion[100], sizeUnionAB, sizeUnionABC;
                hop(A, n, B, m, tempUnion, sizeUnionAB);
                hop(tempUnion, sizeUnionAB, C, p, result, sizeUnionABC);
                cout << "Hop cua A, B, C: ";
                for (int i = 0; i < sizeUnionABC; i++) cout << result[i] << " ";
                cout << endl;
                break;
            }
            case 2: {
                int tempIntersection[100], sizeIntersectionAB, sizeIntersectionABC;
                giao(A, n, B, m, tempIntersection, sizeIntersectionAB);
                giao(tempIntersection, sizeIntersectionAB, C, p, result, sizeIntersectionABC);
                cout << "Giao cua A, B, C: ";
                for (int i = 0; i < sizeIntersectionABC; i++) cout << result[i] << " ";
                cout << endl;
                break;
            }
            case 3: {
                int unionBC[100], sizeUnionBC;
                hop(B, m, C, p, unionBC, sizeUnionBC);
                hieu(A, n, unionBC, sizeUnionBC, result, size);
                cout << "Hieu A - (B ? C): ";
                for (int i = 0; i < size; i++) cout << result[i] << " ";
                cout << endl;
                break;
            }
            case 4:
                tichDescartes(A, n, B, m, C, p);
                break;
            case 0:
                cout << "Ket thuc chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 0);

    return 0;
}

