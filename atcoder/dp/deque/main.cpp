#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector v(N, 0);
    for (int& x : v) cin >> x;

    vector dp(N, vector<ll>(N));

    for (int l = N - 1; l >= 0; l--) {
        for (int r = l + 1; r < N; r++) {
            dp[l][r] = max(
                v[l] - dp[l + 1][r],
                v[r] - dp[l][r - 1]
            );
        }
    }

    cout << dp[0][N - 1];
}
