#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector v(N, 0);
    for (int& x : v) cin >> x;

    vector dp(N, vector<ll>(N, INF));

    // cost of combining a 1-length segment: it's free
    for (int l = 0; l < N; l++) {
        dp[l][l] = 0;
    }

    for (int l = N - 1; l >= 0; l--) {
        for (int r = l + 1; r < N; r++) {

            if (l + 1 == r) {
                dp[l][r] = v[l] + v[r];
            } else {
                for (int m = l; m <= r; m++) {
                    dp[l][r] = min(dp[l][r], dp[l][m] + (m < r ? dp[m + 1][r] : 0));
                }
            }
        }
    }

    cout << dp[0][N - 1];
}
