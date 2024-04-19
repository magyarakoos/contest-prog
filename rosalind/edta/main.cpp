#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string s, t, lcs;
    cin >> s >> t;
    int N = s.size(), M = t.size();

    vector<vector<int>> dp(N + 1, vector<int>(M + 1));

    for (int i = N - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    if (dp[0][0]) {

        int i = 0, j = 0;

        while (i < N && j < M) {
            if (s[i] == t[j]) {
                lcs += s[i];
                i++;
                j++;
            }
            else if (dp[i + 1][j] < dp[i][j + 1]) {
                lcs += "-";
                j++;
            } else {
                lcs += "-";
                i++;
            }
        }

        cout << lcs;
    }
}
