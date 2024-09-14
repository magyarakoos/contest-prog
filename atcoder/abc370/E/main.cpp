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

const ll INF = 2e9, MAXN = 2e5, MOD = 998244353;

#define cases 0
void solve() {
    ll N, K;
    cin >> N >> K;

    vector<ll> a(N), dp(N);
    for (ll& x : a) cin >> x;

    map<ll, ll> m;
    m[0] = 1;
    ll sum = 1, ps = 0;

    for (int i = 0; i < N; i++) {
        ps += a[i];
        dp[i] = (sum - m[ps - K] + MOD) % MOD;
        m[ps] = (m[ps] + dp[i]) % MOD;
        sum += dp[i];
    }

    cout << dp[N - 1];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
