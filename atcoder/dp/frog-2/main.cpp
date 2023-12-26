#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> stones(N + 1), dp(N + 1);
    for (int i = 1; i <= N; i++) cin >> stones[i];

    for (int i = 2; i <= N; i++) {
        int min_s = 1e9;

        for (int j = max(1, i - K); j < i; j++) {
            min_s = min(min_s, abs(stones[j] - stones[i]) + dp[j]);
        }

        dp[i] = min_s;
    }

    cout << dp[N];
}
