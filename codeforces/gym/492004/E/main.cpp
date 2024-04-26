#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N, K, L;
    cin >> N >> K >> L;
    int M = N - K;

    if (M == 0) {
        ll result = K;
        for (int i = 2; i <= L; i++) {
            result *= K - 1;
            result %= MOD;
        }
        cout << result;
        exit(0);
    }

    vector<array<int, 2>> dp(L + 1);

    dp[1] = {M, K};

    for (int i = 2; i <= L; i++) {
        dp[i] = {
            (int)(((ll)(dp[i - 1][0] + dp[i - 1][1]) * M) % MOD), // sum(dp[i - 1]) * M
            (int)(((ll)(dp[i - 1][0] + dp[i - 1][1] - 1) * K) % MOD) // dp[i - 1][0] * (N - 1)
        };
    }

    cout << (dp[L][0] + dp[L][1]) % MOD;
}
