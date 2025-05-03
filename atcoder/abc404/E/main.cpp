#include <bits/stdc++.h>
using namespace std;
#define int int64_t

#define cases 0
void solve() {
    int n;
    cin >> n;
    vector<int> c(n), a(n), dp(n, LLONG_MAX), prv(n);
    for (int i = 1; i < n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) cin >> a[i];
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i - c[i]; j < i; j++) {
            if (dp[j] + 1 < dp[i]) {
                dp[i] = dp[j] + 1;
                prv[i] = j;
            }
        }
        if (a[i]) dp[i] = 0;
    }
    int result = 0;
    for (int i = n - 1; i > 0; i--) {
        if (a[i]) {
            a[prv[i]] = 1;
            result++;
        }
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
