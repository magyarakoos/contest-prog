#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N, K;
    cin >> N >> K;

    vector dp(K + 2, 0LL);
    dp[0] = 1;

    while (N--) {
        int A;
        cin >> A;
        for (int k = K; k >= 0; k--) {
            int tmp = dp[k];
            int L = k + 1;
            int R = min(A, K - k);
            dp[L] += tmp * (R - L + 1);
            dp[R] -= tmp * (R - L + 1);
            dp[L] %= MOD;
            dp[R] %= MOD;
        }
    }
}
