#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, start;
    cin >> n >> m >> start;
    vector<vector<int>> g(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<array<int, 2>> result;
    queue<int> q({start});
    vector<int> dist(n + 1, 1e9);
    vector<bool> vis(n + 1);
    vis[start] = 1;
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dist[u] + 1 < dist[v]) {
                result.push_back({u, v});
                dist[v] = dist[u] + 1;
                q.push(v);
            } else if (dist[u] + 1 == dist[v]) {
                result.push_back({u, v});
            }
        }
    }
    cout << result.size() << "\n";
    for (auto [u, v] : result)
        cout << u << " " << v << "\n";
}
