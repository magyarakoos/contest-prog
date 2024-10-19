#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int N, M;

int findShortestCycle() {
    queue<int> q;
    vector<int> dist(N + 1, -1);

    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            } else if (v == 1) {
                return dist[u] + 1;
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;
    g.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
    }

    cout << findShortestCycle() << "\n";
}
