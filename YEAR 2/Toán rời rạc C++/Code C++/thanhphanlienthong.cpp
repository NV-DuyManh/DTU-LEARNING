#include <iostream>
#include <fstream>

using namespace std;

#define MAX 50

int n;
int MaTran[MAX][MAX];
bool DaXet[MAX];

void DocFile() {
    ifstream file("D:\\code toan\\do_thi_lien_thong.txt");
    if (!file) {
        cout << "Khong the mo file!\n";
        exit(1);
    }
    file >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> MaTran[i][j];
        }
    }
    file.close();
}

void DFS(int u) {
    DaXet[u] = true;
    for (int v = 0; v < n; v++) {
        if (MaTran[u][v] == 1 && !DaXet[v]) {
            DFS(v);
        }
    }
}

int DemThanhPhanLienThong() {
    int soThanhPhan = 0;
    for (int i = 0; i < n; i++) {
        if (!DaXet[i]) {
            DFS(i);
            soThanhPhan++;
        }
    }
    return soThanhPhan;
}

int main() {
    DocFile();

    for (int i = 0; i < n; i++) DaXet[i] = false;

    cout << "So thanh phan lien thong: " << DemThanhPhanLienThong() << endl;

    return 0;
}

