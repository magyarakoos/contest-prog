#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e8;

#define cases 0
void solve() {
    ll N;
    cin >> N;
    vector<ll> v(N), ps(N + 1);
    for (ll& e : v) cin >> e;

    ll rem = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < N - 1; i++) {
        auto it = lower_bound(v.begin() + i + 1, v.end(), MOD - v[i]);
        ll idx = v.end() - it;
        rem += idx;
    }

    ll res = -rem * MOD;
    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1] + v[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        res += (ps[N] - ps[i] + (N - i) * v[i - 1]);
    }
    cout << res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
