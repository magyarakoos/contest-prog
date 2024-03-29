#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string s, t;
    cin >> s;

    t = s;
    reverse(all(t));

    int N = size(s), M = size(t);

    vector<vector<int>> dp(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[N][M];
}