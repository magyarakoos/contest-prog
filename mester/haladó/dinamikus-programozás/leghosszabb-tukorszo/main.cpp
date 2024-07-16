#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string s, t;
    cin >> s;

    t = s;
    reverse(t.begin(), t.end());

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
