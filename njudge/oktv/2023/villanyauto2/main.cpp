#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<array<int, 2>>> g(n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    auto check = [&](int start, int cap) -> bool {

    };
    auto f = [&](int cap) -> bool {
        for (int start = 1; start <= n; start++) {
            if (!check(start, cap)) return 0;
        }
        return 1;
    };

    int l = 0, r = 1e12;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (f(mid)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << "\n";
}
