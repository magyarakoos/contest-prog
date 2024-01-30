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

    vector<vector<int>> dp(N + 1, vector<int>(M + 2));

    int lasti = 0;

    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        if (v[i]) {
            dp[i][v[i]] = 1;
            lasti = i;
        }
    }

    if (lasti == 0) {
        ll result = 1;
        for (int i = 0; i < N; i++) {
            result *= 100;
            result %= MOD;
        }
        cout << result;
        exit(0);
    }

    for (int i = 1; i <= lasti; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = (int)(
                (long long)(
                    dp[i - 1][j - 1] + 
                    dp[i - 1][j] + 
                    dp[i - 1][j + 1]
                ) % MOD
            );
        }
    }

    if (v[N]) {
        cout << dp[N][v[N]];
    } else {
        int diff = N - lasti;
        ll result = 0;

        for (int i = 0; i < 2 * diff + 1; i++) {
            result += dp[lasti][v[lasti]];
            result %= MOD;
        }

        cout << result;
    }
}