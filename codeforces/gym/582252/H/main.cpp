#include <bits/stdc++.h>
using namespace std;

int n, a[1 << 19], b[1 << 19];

void solve(int ans) {
    int m = 1 << ans;
    vector<vector<array<int, 2>>> g(m);
    vector<int> deg(m);
    for (int i = 0; i < n; i++) {
        int u = a[i] & (m - 1), v = b[i] & (m - 1);
        deg[u]++, deg[v]++;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    int start = 0;
    for (int u = 0; u < m; u++) {
        if (deg[u] & 1) return;
        if (deg[u]) start = u;
    }

    vector<int> path;
    vector<bool> used(n);
    function<void(int)> euler = [&]
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    solve(3);
    // for (int i = 20; i >= 0; i--) solve(i);
}
