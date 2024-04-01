#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<array<int, 2>> dp(N + 1, {INT_MAX, INT_MAX});
    dp[0] = {0, 0};
    dp[2] = {1, 0};
    dp[3] = {0, 1};
    for (int i = 4; i <= N; i++) {
        
    }
    cout << dp[N];
}
