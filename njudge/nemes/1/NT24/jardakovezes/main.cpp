#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<array<ll, 2>> dp(N + 1, {INT_MAX, INT_MAX});
    dp[0] = {0, 0};
    dp[2] = {1, 0};
    if (N > 2) dp[3] = {0, 1};
    for (int i = 3; i <= N; i++) {
        ll a = dp[i - 2][0] + dp[i - 2][1],
           b = dp[i - 3][0] + dp[i - 3][1];
        if (a < b) {
            dp[i][0] = dp[i - 2][0] + 1;
            dp[i][1] = dp[i - 2][0];
        } else {
            dp[i][0] = dp[i - 3][0];
            dp[i][1] = dp[i - 3][0] + 1;
        }
    }
    cout << dp[N][0] << " " << dp[N][1];
}
