#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, M;
    cin >> N >> M;

    vector<vector<array<ll, 2>>> g(N + 1);

    while (M--) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({V, W});
        g[V].push_back({U, -W});
    }

    vector<ll> x(N + 1);
    vector<bool> vis(N + 1);

    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (auto [v, w] : g[u]) {
            if (!vis[v]) {
                x[v] = x[u] + w;
                dfs(v);
            }
        }
    };

    for (int u = 1; u <= N; u++) {
        if (!vis[u]) dfs(u);
    }

    for (int u = 1; u <= N; u++) cout << x[u] << " ";
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
