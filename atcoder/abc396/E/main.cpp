#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<array<int, 2>>> g(N + 1);
    for (int i = 0, x, y, z; i < M; i++) {
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    vector<bool> vis(N + 1);
    for (int i = 1; i <= N; i++) {}
    queue<int> q({1});
    vector<int> val(N + 1);
    vis[1] = 1;
    val[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : g[u]) {
            if (vis[v]) {
                if ((val[u] ^ val[v]) != w) {
                    cout << "-1\n";
                    return;
                }
            } else {
                val[v] = val[u] ^ w;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= N; i++) { cout << val[i] << " "; }
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}

