#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;
    dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i - 2], dp[i - 3]) + 1;
    }
    cout << dp[N];
}
