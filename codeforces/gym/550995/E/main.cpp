#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    string s, t;
    cin >> N >> M >> s >> t;

    vector dp(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[N][M];
}
