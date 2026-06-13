#include <iostream>

using namespace std;

#define MAX 10

int n = 5;
int MaTran[MAX][MAX] = {0};
bool DaXet[MAX];
int SoChuTrinh = 0;

void ThemCanh(int u, int v) {
    MaTran[u][v] = 1;
    MaTran[v][u] = 1;
}

void TimChuTrinh(int u, int start, int doDai) {
    DaXet[u] = true;
    for (int v = 0; v < n; v++) {
        if (MaTran[u][v]) {
            if (v == start && doDai >= 3) {
                SoChuTrinh++;
            } else if (!DaXet[v]) {
                TimChuTrinh(v, start, doDai + 1);
            }
        }
    }
    DaXet[u] = false;
}

int main() {
    ThemCanh(0, 1); ThemCanh(0, 4); ThemCanh(0, 3);
    ThemCanh(1, 2); ThemCanh(2, 3); ThemCanh(3, 4);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) DaXet[j] = false;
        TimChuTrinh(i, i, 0);
    }

    cout << "So chu trinh don: " << SoChuTrinh / 2 << endl;

    return 0;
}

