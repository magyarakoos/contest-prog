#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    string s, t;
    cin >> N >> M >> s >> t;

    vector dp(N + 1, vector<int>(M + 1));

    int result = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 2;
            }
            dp[i][j] =
                max({dp[i][j], dp[i - 1][j] - 1, dp[i][j - 1] - 1});

            result = max(result, dp[i][j]);
        }
    }

    cout << result;
}
