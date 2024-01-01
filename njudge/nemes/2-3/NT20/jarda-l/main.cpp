#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;
using ll = long long;

int main() {
    speed;

    int N;
    cin >> N;
    vector<ll> dp(N + 1);

    dp[0] = 1;

    for (int i = 1; i <= N; i++) {

        dp[i] += dp[i - 1];
        
        if (i > 1) dp[i] += dp[i - 2];

        for (int j = 3; j <= i; j += 2) {
            dp[i] += dp[i - j] * 2;
        }

        for (int j = 4; j <= i; j += 2) {
            dp[i] += dp[i - j] * 2;
        }
    }

    cout << dp[N];
}
