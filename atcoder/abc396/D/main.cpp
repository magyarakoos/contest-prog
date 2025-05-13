#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<array<int, 2>>> g(N + 1);
    while (M--) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({V, W});
        g[V].push_back({U, W});
    }
    queue<array<int, 3>> q;
    q.push({1, 0, 2});
    int result = LLONG_MAX;
    while (!q.empty()) {
        auto [u, xr, vis] = q.front();
        q.pop();
        if (u == N) {
            result = min(result, xr);
            continue;
        }
        for (auto [v, w] : g[u]) {
            if (vis >> v & 1) continue;
            q.push({v, xr ^ w, vis | ((int)1 << v)});
        }
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
