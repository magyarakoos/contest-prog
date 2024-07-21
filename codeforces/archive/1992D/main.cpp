#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

const ll MAXN = 2e6, MOD = 1e9 + 7, INF = 1e18;

void solve() {
    int N, M, K;
    string s;
    cin >> N >> M >> K >> s;

    s = 'L' + s + 'L';
    N += 2;

    for (int i = N - 2; ~i; i--) {
        if (s[i + 1] == 'C' && s[i] == 'W') {
            s[i] = 'C';
        }
    }

    vector<int> dp(N, MAXN);
    dp[0] = 0;

    for (int i = 1; i < N; i++) {
        if (s[i] == 'C') continue;
        for (int j = max(0, i - M); j < i; j++) {
            if (s[j] == 'L' || j + 1 == i) {
                dp[i] = min(dp[i], dp[j]);
            }
        }
        if (s[i] == 'W') {
            dp[i]++;
        }
    }

    cout << (dp[N - 1] <= K ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
