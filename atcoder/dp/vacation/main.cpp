#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<array<int, 3>> in(N + 1), dp(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> in[i][0] >> in[i][1] >> in[i][2];
    }
    
    dp[1][0] = in[1][0];
    dp[1][1] = in[1][1];
    dp[1][2] = in[1][2];

    for (int i = 2; i <= N; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + in[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + in[i][1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + in[i][2];
    }

    cout << max({dp[N][0], dp[N][1], dp[N][2]});
}
