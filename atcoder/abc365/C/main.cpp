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

const ll INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    ll N, M;
    cin >> N >> M;

    vector<ll> a(N);
    for (ll& x : a) cin >> x;

    if (accumulate(all(a), 0LL) <= M) {
        cout << "infinite\n";
        return;
    }

    auto f = [&](ll x) -> bool {
        ll sum = 0;
        for (ll y : a) sum += min(x, y);
        return sum > M;
    };

    ll l = -1, r = INF;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (f(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << l << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
