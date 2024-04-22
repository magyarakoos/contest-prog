#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int N, K;
    cin >> N >> K;

    int M = N * N;
    while (K--) {
        int I, J;
        cin >> I >> J;
        M--;
        if (I != J) M--;
    }

    vector<ll> dp(M + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= M; i++) {
        dp[i] = (dp[i - 1] + 2 * (i - 1) * dp[i - 2]) % MOD;
    }

    cout << dp[M] << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}