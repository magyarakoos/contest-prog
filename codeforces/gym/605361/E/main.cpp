#include <bits/stdc++.h>
using namespace std;
#define int int64_t

struct ID {
    map<int, int> m;
    int curr = 0;
    int id(int x) {
        return m.count(x) ? m[x] : m[x] = ++curr;
    }
};

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    ID row, col;

    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> vis(n + 1), mt(n + 1);
    for (int i = 0, u, v; i < n; i++) {
        cin >> u >> v;
        g[row.id(u)].push_back(col.id(v));
    }

    function<bool(int)> dfs = [&](int u) -> bool {
        if (vis[u]) return 0;
        vis[u] = 1;
        for (int v : g[u]) {
            if (!mt[v] || dfs(mt[v])) {
                mt[v] = u;
                return 1;
            }
        }
        return 0;
    };

    int result = 0;
    for (auto [x, i] : row.m) {
        fill(vis.begin(), vis.end(), 0);
        result += dfs(i);
    }
    cout << result << "\n";
}
