#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N, W;
    cin >> N >> W;

    vector<int> w(N + 1), v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, -1));

    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = (
                j >= w[i] && dp[i - 1][j - w[i]] != -1 && dp[i - 1][j] < dp[i - 1][j - w[i]] + v[i] ?
                dp[i - 1][j - w[i]] + v[i] :
                dp[i - 1][j]
            );
        }
    }

    cout << *max_element(all(dp[N]));
}
