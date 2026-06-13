#include <iostream>
#include <vector>
using namespace std;

void KhoiTaoCauHinhDauTien(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        arr.push_back(i + 1);
    }
}

void XuatCauHinh(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void HoanDoi(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void LietKeHoanVi(vector<int>& arr, int batDau, int ketThuc) {
    if (batDau == ketThuc) {
        XuatCauHinh(arr);
    } else {
        for (int i = batDau; i <= ketThuc; i++) {
            HoanDoi(arr[batDau], arr[i]);
            LietKeHoanVi(arr, batDau + 1, ketThuc);
            HoanDoi(arr[batDau], arr[i]);
        }
    }
}

int main() {
    int n;
    cout << "Nhap so n: ";
    cin >> n;

    vector<int> arr;
    KhoiTaoCauHinhDauTien(arr, n);

    cout << "Cac hoan vi cua " << n << " so tu nhien dau tien la:" << endl;
    LietKeHoanVi(arr, 0, n - 1);

    return 0;
}
