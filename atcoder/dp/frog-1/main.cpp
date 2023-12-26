#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> stones(N + 1), dp(N + 1);
    for (int i = 1; i <= N; i++) cin >> stones[i];
    
    dp[1] = 0;
    dp[2] = abs(stones[1] - stones[2]);

    for (int i = 3; i <= N; i++) {
        dp[i] = min(
            abs(stones[i-2] - stones[i]) + dp[i-2], 
            abs(stones[i-1] - stones[i]) + dp[i-1]
        );
    }

    cout << dp[N];
}
