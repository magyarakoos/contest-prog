#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define smin(x, y) x = min(x, y)

const ll INF = 1e18;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector v(N, 0LL), ps(N + 1, 0LL);
    for (ll& x : v) cin >> x;
    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1] + v[i - 1];
    }

    vector dp(N, vector<ll>(N, INF));

    for (int l = N - 1; l >= 0; l--) {
        for (int r = l; r < N; r++) {
            if (l == r) {
                dp[l][r] = 0;
            }
            else {
                for (int m = l; m < r; m++) {
                    smin(dp[l][r], dp[l][m] + dp[m + 1][r] + ps[r + 1] - ps[l]);
                }
            }
        }
    }

    cout << dp[0][N - 1];
}
