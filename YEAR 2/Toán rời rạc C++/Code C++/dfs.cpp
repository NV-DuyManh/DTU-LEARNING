#include <iostream>
#include <vector>

using namespace std;

#define MAX 50

int n, batdau, dich;
int MaTran[MAX][MAX];
bool daxet[MAX];
vector<int> duongdi;

void KhoiTao() {
    freopen("D:\\code toan\\duongdi_DFS.txt", "r", stdin);
    cin >> batdau >> dich >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> MaTran[i][j];
        }
    }
}

bool DFS(int u) {
    duongdi.push_back(u);
    daxet[u] = true;
    if (u == dich) return true;
    for (int v = 1; v <= n; v++) {
        if (MaTran[u][v] == 1 && !daxet[v]) {
            if (DFS(v)) return true;
        }
    }
    duongdi.pop_back();
    return false;
}

void DatLaiTrangThai() {
    for (int i = 1; i <= n; i++) {
        daxet[i] = false;
    }
    duongdi.clear();
}

int main() {
    KhoiTao();
    DatLaiTrangThai();
    
    if (DFS(batdau)) {
        cout << "Duong di DFS: ";
        for (int i = 0; i < duongdi.size(); i++) {
            cout << duongdi[i] << (i == duongdi.size() - 1 ? "\n" : " -> ");
        }
    } else {
        cout << "Khong tim thay duong di\n";
    }

    return 0;
}

