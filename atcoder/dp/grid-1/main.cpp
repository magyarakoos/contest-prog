#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

const int MOD = 1e9 + 7;

int main() {
    speed;

    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    vector<vector<int>> dp(H, vector<int>(W));

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
                dp[i][j] = (long)(dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[H - 1][W - 1];

}
