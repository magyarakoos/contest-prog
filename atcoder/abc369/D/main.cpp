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

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    vector<array<ll, 4>> dp(N); // { xtakeodd, xtakeeven, takeodd, takeeven }

    dp[0] = {0, 0, a[0], 0};

    for (int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][3]) + a[i];
        dp[i][3] = max(dp[i - 1][0], dp[i - 1][2]) + 2 * a[i];
    }

    cout << *max_element(all(dp[N - 1]));
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
