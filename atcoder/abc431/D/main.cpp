#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n;
    cin >> n;
    int w_sum = 0, b_sum = 0;
    vector<int> w(n), h(n), b(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i] >> b[i];
        d[i] = h[i] - b[i];
        b_sum += b[i];
        w_sum += w[i];
    }
    vector<int> dp(w_sum + 1, -INF);
    dp[0] = b_sum;
    for (int i = 0; i < n; i++) {
        for (int j = w_sum - w[i]; j >= 0; j--) {
            int curr_h = j + w[i];
            int curr_b = w_sum - curr_h;
            if (curr_b < curr_h) continue;
            dp[j + w[i]] = max(dp[j + w[i]], dp[j] + d[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
