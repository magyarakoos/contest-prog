#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = '#' + s;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vector dp(n + 1, vector<int>(21, -1));
    auto dfs = [&](auto&& self, int u, int ck) -> bool {
        if (dp[u][ck] != -1) return dp[u][ck];
        if (ck == 0) return s[u] == 'B';
        for (int v : g[u]) {
            auto b = self(self, v, ck - 1);
            if (b == ck % 2) return dp[u][ck] = b;
        }
        return dp[u][ck] = !(ck % 2);
    };

    cout << (dfs(dfs, 1, k * 2) ? "Bob" : "Alice") << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
