#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> e(m);
    for (auto& [u, v] : e) {
        cin >> u >> v;
        u--, v--;
    }
    int result = INF;
    for (int i = 0; i < (1 << n); i++) {
        int curr = 0;
        for (auto [u, v] : e) {
            if ((i >> u & 1) == (i >> v & 1)) { curr++; }
        }
        result = min(result, curr);
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
