#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i < j) continue;
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[N];
}
