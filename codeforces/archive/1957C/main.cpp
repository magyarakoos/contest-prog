#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int N, K;
    cin >> N >> K;

    while (K--) {
        int I, J;
        cin >> I >> J;
        M -= 2;
        if (I != J) M -= 2;
    }

    cerr << M << " ";

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