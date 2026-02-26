#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int s, m;
    cin >> s >> m;
    if (s % (m & -m) != 0) {
        cout << "-1\n";
        return;
    }
    auto f = [&](int val) -> bool {
        int ns = s;
        for (int i = 62; ~i; i--) {
            if (m >> i & 1) {
                int y = ns >> i;
                assert(y == ns / (int(1) << i));
                y = min(y, val);
                ns -= y << i;
            }
        }
        return ns == 0;
    };
    int l = 0, r = s + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (f(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
