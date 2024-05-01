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
        vector ps(K + 2, 0LL);
        for (int k = K; k >= 0; k--) {
            int tmp = dp[k];
            int L = k + 1;
            int R = min(A, K - k);
            ps[L] += tmp;
            ps[L] %= MOD;
            ps[R] -= tmp;
            ps[R] %= MOD;
        }
        for (int i = 1; i <= K; i++) {
            ps[i] += ps[i - 1];
            ps[i] %= MOD;
            dp[i] += ps[i];
            dp[i] %= MOD;
        }
    }

    for (int i = 1; i <= K; i++) {
        dp[i] += dp[i - 1];
    }
    cout << dp[K];
}
