#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> s(n);
    for (int& x : s) cin >> x;
    sort(s.begin(), s.end());

    vector dp(n, vector<int>(n));
    for (int l = n - 2; l >= 0; l--) {
        for (int r = l + 1; r < n; r++) {
            dp[l][r] = (s[r] - s[l]) +
                       min(dp[l + 1][r], dp[l][r - 1]);
        }
    }
    cout << dp[0][n - 1];
}
