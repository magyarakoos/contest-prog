#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr array<int, 2> dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<int>> pyramid(N + 1, vector<int>(N + 1));

    vector<array<int, 3>> order((N + 1) * (N + 1)); // {height, y, x}
    int p = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> pyramid[i][j];
            order[p++] = {pyramid[i][j], i, j};
        }
    }

    sort(all(order), [](auto a, auto b){ return a[0] < b[0]; });

    vector<vector<int>> dp(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) {
        dp[i][1] = dp[i][N] = 1;
        dp[1][i] = dp[N][i] = 1;
    }

    for (auto [height, i, j] : order) {
        for (auto [dx, dy] : dirs) {
            int x = j + dx, y = i + dy;

            if (x < 1 || y < 1 || x > N || y > N) {
                continue;
            }

            if (dp[y][x] && pyramid[y][x] + 1 == height) {
                dp[i][j] = max(dp[i][j], dp[y][x] + 1);
            }
        }
    }

    int maxi = 0, maxj = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[maxi][maxj] < dp[i][j]) {
                maxi = i;
                maxj = j;
            }
        }
    }

    cout << dp[maxi][maxj] - 1 << '\n';

    while (dp[maxi - 1][maxj] || dp[maxi][maxj - 1]) {
        
        if (dp[maxi - 1][maxj] < dp[maxi][maxj - 1]) {
            maxj--;
        } else {
            maxi--;
        }
    }

    cout << maxi << ' ' << maxj;
}
