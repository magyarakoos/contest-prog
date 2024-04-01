#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    int N;
    cin >> N;
    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;
    dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i - 2], dp[i - 3])
    }
}
