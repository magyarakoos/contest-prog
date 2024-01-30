#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 2));

    if (v[1]) {
        dp[1][v[1]] = 1;
    } else {
        fill(all(dp[1]), 1);
    }

    for (int i = 2; i <= N; i++) {
        if (v[i]) {
            dp[i][v[i]] = (ll)(
                dp[i - 1][v[i] - 1] +
                dp[i - 1][v[i] + 1] +
                dp[i - 1][v[i]]
            ) % MOD;
        } else {
            for (int j = 1; j <= M; j++) {
                dp[i][j] = (ll)(
                    dp[i - 1][j - 1] + 
                    dp[i - 1][j + 1] +
                    dp[i - 1][j]
                ) % MOD;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    int result = 0;

    for (int i = 1; i <= M; i++) {
        result += dp[N][i];
        result %= MOD;
    }

    cout << result;
}
