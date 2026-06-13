#include <iostream>

using namespace std;

const int INF = 1e9;
const int V = 5;
const char NODES[V] = {'a', 'b', 'c', 'd', 'e'};

void taoMaTran(int a[V][V]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            a[i][j] = (i == j) ? 0 : INF;

    a[0][1] = a[1][0] = 12;
    a[0][3] = a[3][0] = 10;
    a[0][2] = a[2][0] = 4;
    a[1][3] = a[3][1] = 14;
    a[1][4] = a[4][1] = 3;
    a[2][3] = a[3][2] = 3;
    a[3][4] = a[4][3] = 11;
}

void timDuongDi(int a[V][V], int s, int d[V], int truoc[V]) {
    bool daXet[V] = {false};

    for (int i = 0; i < V; i++) {
        d[i] = INF;
        truoc[i] = -1;
    }

    d[s] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = -1;
        for (int j = 0; j < V; j++)
            if (!daXet[j] && (u == -1 || d[j] < d[u]))
                u = j;

        if (d[u] == INF) break;

        daXet[u] = true;

        for (int v = 0; v < V; v++)
            if (a[u][v] != INF && !daXet[v] && d[u] + a[u][v] < d[v]) {
                d[v] = d[u] + a[u][v];
                truoc[v] = u;
            }
    }
}

void inDuongDi(int truoc[V], int d) {
    if (truoc[d] == -1) {
        cout << NODES[d];
        return;
    }
    inDuongDi(truoc, truoc[d]);
    cout << " -> " << NODES[d];
}

int main() {
    int a[V][V], d[V], truoc[V];
    taoMaTran(a);
    timDuongDi(a, 0, d, truoc);

    cout << "Khoang cach tu dinh 'a' den cac dinh khac:\n";
    for (int i = 0; i < V; i++) {
        cout << "Dinh " << NODES[i] << ": " << d[i] << " | Duong di: ";
        inDuongDi(truoc, i);
        cout << endl;
    }

    return 0;
}

