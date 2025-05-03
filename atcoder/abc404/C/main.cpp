#include <bits/stdc++.h>
using namespace std;
#define int int64_t

#define cases 0
void solve() {
    int n, m;
    cin >> n >> m;
    if (m != n) {
        cout << "No\n";
        return;
    }
    vector<int> deg(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[v]++;
        deg[u]++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] != 2) {
            cout << "No\n";
            return;
        }
    }
    vector<bool> vis(n + 1);
    function<void(int)> dfs = [&](int u) -> void {
        vis[u] = 1;
        for (int v : g[u]) {
            if (!vis[v]) dfs(v);
        }
    };
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
