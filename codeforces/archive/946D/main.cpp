#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> table(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char b;
            cin >> b;
            if (b == '1') {
                table[i].push_back(j);
            }
        }
    }

    // hourS[i][j] = az i. napon j óra kihagyásával legalább hány órát kell bent lenni
    vector<vector<int>> hourS(N, vector<int>(K + 1, INF));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {

            int left = 0, right = size(table[i]) - j - 1;
            
            if (right < left) {
                hourS[i][j] = 0;
                continue;
            }

            while (right < size(table[i])) {
                hourS[i][j] = min(hourS[i][j], table[i][right] - table[i][left] + 1);
                left++;
                right++;
            }
        }
    }

    // dp[i][j] = az i. napig bezárólag, legfeljebb j óra kihagyásával
    // legalább hány órát kell bent lenni
    vector<vector<int>> dp(N, vector<int>(K + 1, INF));

    for (int i = 0; i <= K; i++) {
        dp[0][i] = hourS[0][i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            // a j kihagyásból hányat használjunk el ma
            for (int dj = 0; dj <= j; dj++) {
                dp[i][j] = min(
                    dp[i][j],
                    hourS[i][dj] +
                    dp[i - 1][j - dj]
                );
            }
        }
    }

    cout << dp[N - 1][K];
}
