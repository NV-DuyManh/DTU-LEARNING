#include <iostream>

using namespace std;

#define MAX 5
#define INF 9999

int graph[MAX][MAX] = {
    {0, 12, 4, 10, INF}, // a
    {12, 0, INF, 14, 3}, // b
    {4, INF, 0, 3, INF}, // c
    {10, 14, 3, 0, 11}, // d
    {INF, 3, INF, 11, 0}  // e
};

int getIndex(char c) {
    return c - 'a';
}

void findAnyPath(int u, int v, bool visited[], int path[], int &pathIndex) {
    visited[u] = true;
    path[pathIndex++] = u;

    if (u == v) {
        cout << "Duong di bat ky tu a den e: ";
        for (int i = 0; i < pathIndex; i++) {
            cout << char(path[i] + 'a') << (i == pathIndex - 1 ? "\n" : " -> ");
        }
        return;
    }

    for (int i = 0; i < MAX; i++) {
        if (graph[u][i] != INF && graph[u][i] != 0 && !visited[i]) {
            findAnyPath(i, v, visited, path, pathIndex);
            return;
        }
    }
    pathIndex--;
}

void dijkstra(int start) {
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

    cout << "Duong di ngan nhat tu a den cac dinh khac:\n";
    for (int i = 0; i < MAX; i++) {
        cout << "a -> " << char(i + 'a') << " (khoang cach: " << dist[i] << "): ";
        int temp = i;
        while (temp != -1) {
            cout << char(temp + 'a') << (temp == start ? "\n" : " <- ");
            temp = parent[temp];
        }
    }
}

int main() {
    bool visited[MAX] = {false};
    int path[MAX], pathIndex = 0;
    
    findAnyPath(getIndex('a'), getIndex('e'), visited, path, pathIndex);
    dijkstra(getIndex('a'));

    return 0;
}

