#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s;
    cin >> s;
    vector<bool> safe(n + 1);
    for (int i = 0; i < n; i++) {
        safe[i + 1] = s[i] == 'S';
    }

    vector<set<int>> vis(n + 1);
    vector<int> result(n + 1);
    queue<array<int, 3>> q;
    for (int i = 1; i <= n; i++) {
        if (safe[i]) { q.push({i, i, 0}); }
    }
    while (!q.empty()) {
        auto [origin, u, d] = q.front();
        q.pop();
        for (int v : g[u]) {
            if (vis[v].size() == 2 ||
                vis[v].contains(origin)) {
                continue;
            }
            vis[v].insert(origin);
            result[v] += d + 1;
            q.push({origin, v, d + 1});
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!safe[i]) {
            assert(vis[i].size() == 2);
            cout << result[i] << "\n";
        }
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
