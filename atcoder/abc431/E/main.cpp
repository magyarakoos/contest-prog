#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

int req_mirror(int k, int nk) {
    const vector<vector<int>> table = {
        {0, 3, 1, 2},
        {3, 0, 2, 1},
        {1, 2, 0, 3},
        {2, 1, 3, 0},
    };
    return table[k][nk];
}

#define cases 1
void solve() {
    int h, w;
    cin >> h >> w;
    vector g(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            g[i][j] = c - 'A';
        }
    }
    vector dist(
        h, vector<vector<int>>(w, vector<int>(4, INF)));

    deque<array<int, 3>> q;
    q.push_back({0, 0, 2});
    dist[0][0][2] = 0;

    while (!q.empty()) {
        auto [i, j, k] = q.front();
        q.pop_front();
        for (int nk = 0; nk < 4; nk++) {
            int ni = i + di[nk], nj = j + dj[nk];
            if (ni < 0 || nj < 0 || ni >= h || nj >= w) {
                continue;
            }
            int l = req_mirror(k, nk);
            if (l == 3) continue;
            int d = dist[i][j][k];
            if (l == g[i][j]) {
                if (d < dist[ni][nj][nk]) {
                    dist[ni][nj][nk] = d;
                    q.push_front({ni, nj, nk});
                }
            } else {
                if (d + 1 < dist[ni][nj][nk]) {
                    dist[ni][nj][nk] = d + 1;
                    q.push_back({ni, nj, nk});
                }
            }
        }
    }

    cout << min(dist[h - 1][w - 1][2] +
                    (g[h - 1][w - 1] != 0),
                dist[h - 1][w - 1][0] +
                    (g[h - 1][w - 1] != 1))
         << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
