#include <bits/stdc++.h>
#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;

int main() {
    speed;

    string s, t, lcs;
    short i, j;
    cin >> s >> t;
    
    vector<vector<short>> dp(s.size() + 1, vector<short>(t.size() + 1));

    for (i = s.size() - 1; i >= 0; i--) {
        for (j = t.size() - 1; j >= 0; j--) {
            if (s[i] == t[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    if (dp[0][0]) {
        i = j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                lcs += s[i];
                i++; j++;
            } else if (dp[i + 1][j] < dp[i][j + 1]) {
                j++;
            } else {
                i++;
            }
        }

        cout << lcs;
    }
}
