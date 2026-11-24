#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    vector<int> distS(n + 1, INT_MAX);
    distS[1] = 0;
    queue<array<int, 2>> q;
    for (int i = 1; i <= m; i++) { q.push({1, i}); }
    while (!q.empty()) {
        auto [u, color] = q.front();
        cout << u << " " << color << "\n";
        q.pop();
        if (u == n) {
            cout << distS[u] << "\n";
            return 0;
        }
        for (auto [v, w] : g[u]) {
            if (w == color || distS[v] < INT_MAX) continue;
            distS[v] = distS[u] + 1;
            q.push({v, w});
        }
    }
    cout << "-1\n";
}
