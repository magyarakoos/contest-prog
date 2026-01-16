#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 2023;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    int ps = 0;
    for (int i = 1; i <= n; i++) {
        (dp[i] += 2 * dp[i - 1]) %= MOD;
        if (i >= 2) (dp[i] += 7 * dp[i - 2]) %= MOD;
        if (i >= 3) {
            (dp[i] += ((ps += 8 * dp[i - 3]) %= MOD)) %=
                MOD;
        }
    }
    cout << dp[n] << "\n";
}
