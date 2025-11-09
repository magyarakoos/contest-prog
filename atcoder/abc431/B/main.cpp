#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int x, n;
    cin >> x >> n;
    vector<int> a(n);
    for (int& y : a) cin >> y;
    int q;
    cin >> q;
    vector<bool> on(n);
    while (q--) {
        int i;
        cin >> i;
        i--;
        if (on[i]) {
            x -= a[i];
            on[i] = 0;
        } else {
            x += a[i];
            on[i] = 1;
        }
        cout << x << "\n";
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
