#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--, b--;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        g[u * 2][v] = 1;
        g[v * 2][u] = 1;
    }
}
