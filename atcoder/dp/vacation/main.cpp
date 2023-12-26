#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<array<int, 3>> dp(N + 1);
    cin >> dp[1][0] >> dp[1][1] >> dp[1][2];

    for (int i = 2, a, b, c; i <= N; i++) {
        cin >> a >> b >> c;

        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a;
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b;
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c;
    }

    cout << max({dp[N][0], dp[N][1], dp[N][2]});
}
