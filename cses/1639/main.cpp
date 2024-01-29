#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string s, t;

    cin >> s >> t;

    int N = size(s), M = size(t);

    vector<vector<int>> dp(N + 1, vector<int>(M + 1));

    /*
          M O V I E
        L 1 2 3 4 5
        O 2 1 2 3 4
        V 3 2 1 2 3
        E 4 3 2 2 2
    */

    for (int i = 1; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
    }

    for (int i = 1; i <= M; i++) {
        dp[0][i] = dp[0][i - 1] + 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int cost_insert, cost_delete, cost_modify;

            cost_insert = dp[i][j - 1] + 1;
            cost_delete = dp[i - 1][j] + 1;
            cost_modify = dp[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1);

            dp[i][j] = min({cost_insert, cost_delete, cost_modify});
        }
    }

    cout << dp[N][M];
}
