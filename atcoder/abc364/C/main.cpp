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

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> a(N), b(N);
    for (ll& x : a) cin >> x;
    for (ll& x : b) cin >> x;

    sort(rall(a));
    sort(rall(b));

    int res = N;
    for (int i = 0; i < N; i++) {
        if (X < 0) {
            res = min(res, i);
            break;
        }
        X -= a[i];
    }

    for (int i = 0; i < N; i++) {
        if (Y < 0) {
            res = min(res, i);
            break;
        }
        Y -= b[i];
    }

    cout << res << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
