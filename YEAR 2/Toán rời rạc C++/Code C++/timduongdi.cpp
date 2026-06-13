#include <iostream>
#include <fstream>

using namespace std;

#define MAX 50

int n, u, v;
int MaTran[MAX][MAX];
bool DaXet[MAX];
int DuongDi[MAX], index = 0;

void DocFile() {
    ifstream file("D:\\code toan\\duongdi_DFS.txt");
    if (!file) {
        cout << "Khong the mo file!\n";
        exit(1);
    }
    file >> u >> v >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> MaTran[i][j];
        }
    }
    file.close();
}

bool TimDuong(int x) {
    DuongDi[index++] = x;
    DaXet[x] = true;
    if (x == v) return true;

    for (int i = 0; i < n; i++) {
        if (MaTran[x][i] == 1 && !DaXet[i]) {
            if (TimDuong(i)) return true;
        }
    }

    index--;
    return false;
}

void KhoiTao() {
    for (int i = 0; i < n; i++) {
        DaXet[i] = false;
    }
    index = 0;
}

int main() {
    DocFile();
    KhoiTao();

    if (TimDuong(u - 1)) {
        cout << "Duong di DFS: ";
        for (int i = 0; i < index; i++) {
            cout << DuongDi[i] + 1 << (i == index - 1 ? "\n" : " -> ");
        }
    } else {
        cout << "Khong tim thay duong di\n";
    }

    return 0;
}

