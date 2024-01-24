
#include <bits/stdc++.h>

#pragma region Utility

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

#define max_index(v) max_element(all(v)) - v.begin()
#define min_index(v) min_element(all(v)) - v.begin()
#define smax(x, y) x = max(x, y)
#define smin(x, y) x = min(x, y)

#define sum(v) accumulate(all(v), 0)
#define product(v, T) accumulate(all(v), 1, multiplies<T>())

using namespace std;
using ll = long long;
using point = array<int, 2>;

int max(point p) { return max(p[0], p[1]); }
int min(point p) { return min(p[0], p[1]); }

template <typename T>
vector<T> prefix_sum(const vector<T>& v) {
    vector<T> result(size(v));
    partial_sum(all(v), result.begin());
    return result;
}

#pragma endregion

int main() {
    speed;

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> grid(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(M + 1, vector<int>(K + 1, 1e9)));

    dp[1][1][0] = grid[1][1];

    for (int dc = 1; dc <= K; dc++) {
        dp[1][1][dc] = dp[1][1][dc - 1] / 2;
    }

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            for (int dx = 0; dx <= K; dx++) {
                for (int dt = 0; dt <= dx; dt++) {

                    smin(
                        dp[y][x][dx],
                        (grid[y][x] >> dt) + // dt-szer elosztjuk kettővel a jelenlegi magasságot
                        min( // a legkisebb kellemetlenség eddig legfeljebb dx - dt felhasználásával
                            dp[y - 1][x][dx - dt],
                            dp[y][x - 1][dx - dt]
                        )
                    );
                }
            }
        }
    }

    cout << dp[N][M][K];
}