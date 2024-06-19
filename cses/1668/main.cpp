#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> vis;

bool bfs(int s) {
    vis[s] = 1;

    queue<int> q({s});

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (vis[u] == vis[v]) return 0;
            if (!vis[v]) {
                vis[v] = -vis[u];
                q.push(v);
            }
        }
    }

    return 1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    g.resize(N + 1);
    vis.resize(N + 1);

    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }

    for (int u = 1; u <= N; u++) {
        if (!vis[u] && !bfs(u)) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    }

    for (int u = 1; u <= N; u++) {
        cout << (vis[u] == 1 ? 1 : 2) << " ";
    }

    cout << "\n";
}
