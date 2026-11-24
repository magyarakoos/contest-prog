#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<vector<array<int, 2>>> g(n + 1);

    for (int i = 2; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        g[v].push_back({i, w});
    }

    vector<int> subT(n + 1);
    function<void(int)> dfs = [&](int u) {
        if (!g[u].size()) {
            subT[u] = 1;
            return;
        }
        for (auto [v, w] : g[u]) {
            dfs(v);
            subT[u] += subT[v];
        }
    };

    vector<vector<int>> dp(n + 1);
}
