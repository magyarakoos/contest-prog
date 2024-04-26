#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

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

    vector<array<ll, 2>> dp(L + 1);

    dp[1] = {M, K};

    for (int i = 2; i <= L; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) * M;
        dp[i][0] %= MOD;

        dp[i][1] = dp[i - 1][0] * K;
        dp[i][1] %= MOD;
    }

    ll res = dp[L][0] + dp[L][1];
    res %= MOD;
    cout << res;
}
