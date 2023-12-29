#include <iostream>
#include <vector>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)
const int MOD = 20210108;

int main() {
    speed;

    int N;
    cin >> N;
    vector<int> dp(N + 1);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        dp[i] = (long)((dp[i - 1] * 2) + (i >= 3 ? dp[i - 3] * 2 : 0)) % MOD;
    }

    cout << dp[N];
}
