#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N + 1, vector<int>(M + 1)), dp(N + 1, vector<int>(M + 1, INF));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int x;
            cin >> x;
            if (i == 1 && j == 1) {
                dp[i][j] = 0;
                continue;
            }
            if (x != 2) {
                int mn = min(dp[i - 1][j], dp[i][j - 1]);
                if (mn == INF) {
                    continue;
                }

                dp[i][j] = mn + x;
            }
        }
    }

    if (dp[N][M] == INF) {
        cout << -1;
        exit(0);
    }

    string path;
    int i = N, j = M;
    
    while (i != 1 && j != 1) {
        if (dp[i - 1][j] < dp[i][j - 1]) {
            path += 'L';
            i--;
        } else {
            path += 'J';
            j--;
        }
    }

    while (i != 1) {
        path += 'L';
        i--;
    }

    while (j != 1) {
        path += 'J';
        j--;
    }

    reverse(all(path));
    cout << dp[N][M] << '\n' << path;
}
