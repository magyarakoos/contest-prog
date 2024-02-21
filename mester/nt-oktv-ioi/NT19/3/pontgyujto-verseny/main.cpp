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

    vector<vector<int>> grid(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= M; i++) {
        dp[i][1] = grid[i][1];
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            
        }
    }
}