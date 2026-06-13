#include <iostream>
#include <algorithm>
using namespace std;

bool areSetsEqual(int A[], int n, int B[], int m) {
    if (n != m) return false;

    sort(A, A + n);
    sort(B, B + m);

    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) return false;
    }
    return true;
}

int main() {
    int n, m;
    cout<<"Nhap so phan tu tap hop A: ";
    cin >> n;
    cout<<"Nhap cac phan tu tap hop A: ";
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    cout<<"Nhap so phan tu tap hop B: ";
    cin >> m;
    cout<<"Nhap cac phan tu tap hop B: ";
    int B[m];
    for (int i = 0; i < m; i++) cin >> B[i];

    if (areSetsEqual(A, n, B, m)) {
        cout << "Hai tap hop A va B bang nhau.\n";
    } else {
        cout << "Hai tap hop A va B khong bang nhau.\n";

    return 0;
}
}
