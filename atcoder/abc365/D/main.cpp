#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

char beater(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    return 'R';
}

#define cases 0
void solve() {
    int N;
    string s;
    cin >> N >> s;

    vector<array<ll, 2>> dp(N, {0, 0});

    dp[0][1] = 1;
    for (int i = 1; i < N; i++) {
        if (s[i - 1] != s[i]) smax(dp[i][0], dp[i - 1][0]);
        if (beater(s[i - 1]) != s[i]) smax(dp[i][0], dp[i - 1][1]);

        if (s[i - 1] != beater(s[i])) smax(dp[i][1], dp[i - 1][0] + 1);
        if (beater(s[i - 1]) != beater(s[i])) smax(dp[i][1], dp[i - 1][1] + 1);
    }

    cout << max(dp[N - 1][0], dp[N - 1][1]) << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
