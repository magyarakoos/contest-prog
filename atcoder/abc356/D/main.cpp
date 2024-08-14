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

const ll INF = 2e9, MAXN = 2e5, MOD = 998244353;

#define cases 0
void solve() {
    ll N, M, res = 0;
    cin >> N >> M;
    for (int i = 0; i < 60; i++) {
        ll pw = 1LL << i;
        if (M & pw) {
            ll fullS = (N + 1) / (pw * 2);
            ll rem = (N + 1) - fullS * pw * 2;
            ll usable = max(0LL, rem - pw);
            res += (fullS * pw + usable) % MOD;
            res %= MOD;
        }
    }
    cout << res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
