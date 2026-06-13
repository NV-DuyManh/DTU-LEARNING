#include <iostream>
using namespace std;

void timMinMax(int A[], int n, int& min, int& max) {
    min = A[0];
    max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
        }
        if (A[i] > max) {
            max = A[i];
        }
    }
}

int main() {
    int n;

    cout << "Nhap so phan tu cua tap A: ";
    cin >> n;
    int A[n];

    cout << "Nhap cac phan tu cua tap A:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int min, max;
    timMinMax(A, n, min, max);

    cout << "Phan tu be nhat trong tap A: " << min << endl;
    cout << "Phan tu lon nhat trong tap A: " << max << endl;

    return 0;
}

