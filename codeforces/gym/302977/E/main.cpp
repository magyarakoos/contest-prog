#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

constexpr ll INF = 1e18;

#define cases 0
void solve() {
    ll N, K, P;
    cin >> N >> K >> P;

    vector<ll> A(N), B(K);
    for (ll& x : A) cin >> x;
    for (ll& x : B) cin >> x;
    sort(all(A));
    sort(all(B));

    vector<vector<ll>> dp(K + 1, vector<ll>(N + 1, INF));

    dp[0][0] = 0;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j <= N; j++) {
            
            smin(dp[i + 1][j], dp[i][j]);
            
            if (j < N) {
                smin(dp[i + 1][j + 1], max(
                    dp[i][j], 
                    abs(B[i] - A[j]) + abs(P - B[i])
                ));
            }
        }
    }

    cout << dp[K][N];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
