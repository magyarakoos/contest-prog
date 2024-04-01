#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<array<ll, 2>> dp(N + 1, {2e9, 2e9});
    dp[0] = {0, 0};
    dp[2] = {1, 0};
    for (int i = 3; i <= N; i++) {
        ll a = dp[i - 2][0] + dp[i - 2][1],
           b = dp[i - 3][0] + dp[i - 3][1];
        if (a < b) {
            dp[i][0] = dp[i - 2][0]
        }
    }
}
