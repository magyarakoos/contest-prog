#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector v(N, 0LL);
    for (ll& x : v) cin >> x;

    vector dp(N, vector<ll>(N, INF));

    for (int l = N - 1; l >= 0; l--) {
        for (int r = l; r < N; r++) {

            if (l == r) {
                dp[l][r] = 0;
            }
            else if (l + 1 == r) {
                dp[l][r] = v[l] + v[r];
            }
        }
    }

    cout << dp[0][N - 1];
}
