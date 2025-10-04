#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> m(n + 1);
    for (int i = 1; i <= n; i++) m[i] = 1;
    int i = 1;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int res = 0;
        for (; i <= x; i++) {
            m[y] += m[i];
            res += m[i];
            m[i] = 0;
        }
        cout << res << "\n";
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
