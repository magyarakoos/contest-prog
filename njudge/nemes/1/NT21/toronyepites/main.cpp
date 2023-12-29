#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;

int main() {
    speed;

    int N;
    cin >> N;
    vector<int> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] = (long)(dp[i - 1] * 3 + (i >= 2 ? dp[i - 2] : 0)) % 20210108;
    }
    cout << dp[N];
}
