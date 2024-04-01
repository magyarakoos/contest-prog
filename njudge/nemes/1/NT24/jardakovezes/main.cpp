#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<array<ll, 2>> dp(N + 1, {INT_MAX, INT_MAX});
    dp[0] = 0;
    dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        int a = dp[i - 2][0] + dp[i - 2][1];
        dp[i] = min(dp[i - 2], dp[i - 3]) + 1;
    }
    cout << dp[N];
}
