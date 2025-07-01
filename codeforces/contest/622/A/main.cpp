#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n;
    cin >> n;
    int l = -1, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (m * (m + 1) / 2 >= n) {
            r = m;
        } else {
            l = m;
        }
    }
    n -= l * (l + 1) / 2;
    cout << n << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
