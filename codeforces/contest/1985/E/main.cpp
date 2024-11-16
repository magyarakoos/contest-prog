#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    ll res = 0;
    for (ll x = 1; x <= X; x++) {
        for (ll y = 1; y <= Y; y++) {
            if (K % (x * y)) continue;
            ll z = K / (x * y);
            if (z > Z) continue;
            smax(res,
                 (X - x + 1) * (Y - y + 1) * (Z - z + 1));
        }
    }
    cout << res << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
