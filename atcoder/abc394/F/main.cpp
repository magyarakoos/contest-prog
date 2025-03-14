#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<vector<int>> g(N + 1);
    vector<int> dp(N + 1, 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int result = 0;
    function<int(int, int)> dfs = [&](int u, int p) -> int {
        vector<int> a;
        for (int v : g[u]) {
            if (v != p) a.push_back(dfs(v, u));
        }
        sort(a.rbegin(), a.rend());
        if (!a.empty()) result = max(result, a[0] + 1);
        if (a.size() >= 4) {
            result =
                max(result, a[0] + a[1] + a[2] + a[3] + 1);
        }
        if (a.size() >= 3) dp[u] += a[0] + a[1] + a[2];
        return dp[u];
    };
    dfs(1, 0);
    cout << (result < 5 ? -1 : result) << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
