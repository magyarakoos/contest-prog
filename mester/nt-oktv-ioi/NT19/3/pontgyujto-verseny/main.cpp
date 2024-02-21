#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N + 2, vector<int>(M + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(N + 2, vector<int>(M + 1));

    for (int i = 1; i <= N; i++) {
        dp[i][1] = grid[i][1];
    }

    for (int j = 2; j <= M; j++) {
        for (int i = 1; i <= N; i++) {

            dp[i][j] = max({dp[i][j - 1], dp[i - 1][j - 1], dp[i + 1][j - 1]}) + grid[i][j];

        }
    }

    int mxi = 0;

    for (int i = 1; i <= N; i++) {
        if (dp[mxi][M] < dp[i][M]) {
            mxi = i;
        }
    }

    cout << dp[mxi][M] << '\n';

    if (M == 1) {
        cout << mxi + 1;
        exit(0);
    }

    int j = M;

    while (j > 1) {
        int a = dp[mxi][j - 1];
        int b = dp[mxi - 1][j - 1];
        int c = dp[mxi + 1][j - 1];
        
        if (a == min({a, b, c})) {
            
        }
    }
}