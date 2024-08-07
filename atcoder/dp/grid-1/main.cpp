#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int H, W;
    cin >> H >> W;

    vector grid(H, vector<char>(W));
    vector dp(H, vector<int>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < H && grid[i][0] == '.'; i++) dp[i][0] = 1;
    for (int i = 1; i < W && grid[0][i] == '.'; i++) dp[0][i] = 1;

    for (int i = 1; i < H; i++) {
        for (int j = 1; j < W; j++) {
            if (grid[i][j] == '.') {
                dp[i][j] =(dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[H - 1][W - 1];
}

