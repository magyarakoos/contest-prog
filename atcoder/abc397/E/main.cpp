#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, K;
    cin >> N >> K;
    int M = N * K;
    vector<vector<int>> g(M + 1);
    for (int i = 1, u, v; i < M; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp(M + 1, 1);
    function<void(int, int)> dfs = [&](int u, int p) {
        int c = 0;
        for (int v : g[u]) {
            if (v == p) continue;
            dfs(v, u);
            dp[u] += dp[v];
            if (dp[v]) c++;
        }
        if (c >= 3 || dp[u] > K || (dp[u] < K && c >= 2)) {
            cout << "No\n";
            exit(0);
        }
        dp[u] *= dp[u] != K;
    };
    dfs(1, 0);
    cout << "Yes\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
