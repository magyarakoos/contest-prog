#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

constexpr int MOD = 1e6;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<bool>> trapS(N + 1, vector<bool>(M + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char b;
            cin >> b;
            trapS[i][j] = b == '1';
        }
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1));

    dp[0][1] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!trapS[i][j]) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }

        }
    }

    cout << dp[N][M];
}
