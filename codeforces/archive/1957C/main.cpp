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
        N -= 1 + (I != J);
    }

    if (N == 0) {
        cout << "1\n";
        return;
    }

    vector<ll> dp(N + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = (dp[i - 1] + 2 * (i - 1) * dp[i - 2]) % MOD;
    }

    cout << dp[N] << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
