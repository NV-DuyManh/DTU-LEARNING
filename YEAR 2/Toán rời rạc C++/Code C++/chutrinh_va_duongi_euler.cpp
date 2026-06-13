#include <iostream>

using namespace std;

#define MAX 10

int n = 6;
int MaTran[MAX][MAX] = {0};
int DuongDi[MAX * MAX];
int index = 0;

void ThemCanh(int u, int v) {
    MaTran[u][v] = 1;
    MaTran[v][u] = 1;
}

void XoaCanh(int u, int v) {
    MaTran[u][v] = 0;
    MaTran[v][u] = 0;
}

void TimChuTrinhEuler(int u) {
    for (int v = 0; v < n; v++) {
        if (MaTran[u][v]) {
            XoaCanh(u, v);
            TimChuTrinhEuler(v);
        }
    }
    DuongDi[index++] = u;
}

void TimDuongDiEuler(int u) {
    for (int v = 0; v < n; v++) {
        if (MaTran[u][v]) {
            XoaCanh(u, v);
            TimDuongDiEuler(v);
        }
    }
    DuongDi[index++] = u;
}

int main() {
    ThemCanh(0, 1); ThemCanh(0, 2);
    ThemCanh(0, 3); ThemCanh(1, 3);
    ThemCanh(1, 4); ThemCanh(1, 5);
    ThemCanh(2, 3); ThemCanh(2, 4);
    ThemCanh(3, 5); ThemCanh(4, 5);

    int start = 0;

    index = 0;
    TimChuTrinhEuler(start);
    cout << "Chu trinh Euler: ";
    for (int i = index - 1; i >= 0; i--) {
        cout << (char)(DuongDi[i] + 'a') << " -> ";
    }
    cout << "a" << endl;

    index = 0;
    ThemCanh(0, 1); ThemCanh(0, 2);
    ThemCanh(0, 3); ThemCanh(1, 3);
    ThemCanh(1, 4); ThemCanh(1, 5);
    ThemCanh(2, 3); ThemCanh(2, 4);
    ThemCanh(3, 5); ThemCanh(4, 5);

    TimDuongDiEuler(start);
    cout << "Duong di Euler: ";
    for (int i = index - 1; i >= 0; i--) {
        cout << (char)(DuongDi[i] + 'a') << " -> ";
    }
    cout << endl;

    return 0;
}

