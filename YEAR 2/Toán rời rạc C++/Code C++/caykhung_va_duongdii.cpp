#include <iostream>

using namespace std;

#define MAX 6
#define INF 9999

int graph[MAX][MAX] = {
    {0, 4, INF, INF, INF, 2},  // A
    {4, 0, 6, INF, INF, 3},    // B
    {INF, 6, 0, 5, INF, INF},  // C
    {INF, INF, 5, 0, 8, 7},    // D
    {INF, INF, INF, 8, 0, 9},  // E
    {2, 3, INF, 7, 9, 0}       // F
};

int getIndex(char c) {
    return c - 'A';
}

void dijkstra(int start, int end) {
    int dist[MAX], parent[MAX];
    bool visited[MAX] = {false};

    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;

    for (int count = 0; count < MAX - 1; count++) {
        int minDist = INF, u = -1;
        for (int i = 0; i < MAX; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < MAX; v++) {
            if (!visited[v] && graph[u][v] != INF && graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Duong di ngan nhat tu A den D: ";
    int temp = end;
    while (temp != -1) {
        cout << char(temp + 'A') << (temp == start ? "\n" : " <- ");
        temp = parent[temp];
    }
    cout << "Tong khoang cach: " << dist[end] << endl;
}

void prim() {
    int parent[MAX], key[MAX];
    bool mstSet[MAX] = {false};

    for (int i = 0; i < MAX; i++) {
        key[i] = INF;
        parent[i] = -1;
    }
    key[0] = 0;

    for (int count = 0; count < MAX - 1; count++) {
        int minKey = INF, u = -1;
        for (int i = 0; i < MAX; i++) {
            if (!mstSet[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        if (u == -1) break;
        mstSet[u] = true;

        for (int v = 0; v < MAX; v++) {
            if (!mstSet[v] && graph[u][v] != INF && graph[u][v] != 0 &&
                graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Cay khung nho nhat (Prim):\n";
    for (int i = 1; i < MAX; i++) {
        cout << char(parent[i] + 'A') << " - " << char(i + 'A') << " : " << graph[i][parent[i]] << endl;
    }
}

int main() {
    dijkstra(getIndex('A'), getIndex('D'));
    prim();
    return 0;
}

