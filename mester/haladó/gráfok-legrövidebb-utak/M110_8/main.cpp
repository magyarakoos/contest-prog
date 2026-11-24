#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    vector<vector<array<int, 2>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    auto bfs = [&](int min_w, vector<int>& prv) -> bool {
        fill(prv.begin(), prv.end(), -1);
        vector<bool> vis(n + 1);
        vis[p] = 1;
        queue<int> qu({q});
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            if (u == q) return true;
            for (auto [v, w] : g[u]) {
                if (w < min_w || vis[v]) continue;
                vis[v] = 1;
                prv[v] = u;
                qu.push(v);
            }
        }
        return false;
    };

    int l = 0, r = 1001;
    vector<int> prv(n + 1);
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (bfs(mid, prv)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    bfs(r, prv);
    cout << r << "\n";
}
