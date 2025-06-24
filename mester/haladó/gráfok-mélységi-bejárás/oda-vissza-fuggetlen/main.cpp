#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--, b--;
    vector<map<int, bool>> g(2 * n), gr(2 * n);
    for (int u = 0; u < n; u++) g[u][u * 2] = 1;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        g[u * 2][v] = 1;
        g[v * 2][u] = 1;
    }

    auto bfs = [&](int s, int t, vector<int>& par) {
        fill(par.begin(), par.end(), -1);
        par[s] = -2;
        queue<array<int, 2>> q({{s, 1}});
        while (!q.empty()) {
            auto [u, flow] = q.front();
            q.pop();
            for (auto [v, cap] : g[u]) {}
        }
    }
}
