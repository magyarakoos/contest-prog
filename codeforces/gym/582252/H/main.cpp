#include <bits/stdc++.h>
using namespace std;

int n, a[1 << 19], b[1 << 19];

void solve(int ans) {
    int m = 1 << ans;
    vector<vector<array<int, 2>>> g(m);
    vector<int> deg(m);
    map<array<int, 2>, vector<int>> ms;
    for (int i = 0; i < n; i++) {
        int u = a[i] & (m - 1), v = b[i] & (m - 1);
        ms[{u, v}].push_back(i);
        deg[u]++, deg[v]++;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    int start = 0;
    for (int u = 0; u < m; u++) {
        if (deg[u] & 1) return;
        if (deg[u]) start = u;
    }

    vector<array<int, 2>> path;
    vector<bool> used(n);
    function<void(int)> euler = [&](int u) {
        while (!g[u].empty()) {
            auto v = g[u].back();
            g[u].pop_back();
            if (!used[v[1]]) {
                used[v[1]] = 1;
                path.push_back({u, v[0]});
                euler(v[0]);
            }
        }
    };
    euler(start);

    if (path.size() != n) return;
    cout << ans << "\n";
    for (auto [u, v] : path) {
        int i;
        bool rev = ms[{u, v}].empty();
        if (!rev) {
            i = ms[{u, v}].back();
            ms[{u, v}].pop_back();
        } else {
            i = ms[{v, u}].back();
            ms[{v, u}].pop_back();
        }
        if (rev) {
            cout << i * 2 + 2 << " " << i * 2 + 1 << " ";
        } else {
            cout << i * 2 + 1 << " " << i * 2 + 2 << " ";
        }
    }
    cout << "\n";
    exit(0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 20; i >= 0; i--) solve(i);
}
