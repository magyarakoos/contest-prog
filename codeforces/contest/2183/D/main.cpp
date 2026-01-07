#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> depth(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int result = 0;
    vector<bool> vis(n + 1);
    function<void(int, int)> dfs = [&](int u, int d) {
        depth[d]++;
        vis[u] = 1;
        result = max<int>(result, g[u].size() + (u == 1));
        for (int v : g[u]) {
            if (!vis[v]) dfs(v, d + 1);
        }
    };
    dfs(1, 0);

    cout << max(result,
                *max_element(depth.begin(), depth.end()))
         << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
