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
#define int long long

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> a(N + 1), ps(N + 1);
    for (int i = 1; i <= N; i++) { cin >> a[i]; }
    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1] + a[i];
    }

    vector<int> dp(N + 1);
    map<int, int> m;
    m[0] = 0;

    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];
        if (m.count(ps[i])) {
            dp[i] = max(dp[i], m[ps[i]] + 1);
        }
        m[ps[i]] = max(m[ps[i]], dp[i]);
    }

    cout << dp[N] << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
