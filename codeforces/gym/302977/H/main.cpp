#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

constexpr int INF = 2e9;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> v(N), costS(N);
    for (int& x : v) cin >> x;
    for (int& x : costS) cin >> x;
    vector<array<int, 3>> dp(N, {0, INF, INF});
    int res = INF;
    for (int i = 0; i < N; i++) {
        dp[i][0] = costS[i];
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                smin(dp[i][1], dp[j][0] + costS[i]);
                smin(dp[i][2], dp[j][1] + costS[i]);
            }
        }
        smin(res, dp[i][2]);
    }
    cout << (res == INF ? -1 : res);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
