#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7,
          di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

#define cases 0
void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (string& s : grid) cin >> s;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    vector distS(h, vector<int>(w, INF));
    deque<array<int, 2>> q({{a, b}});
    distS[a][b] = 0;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop_front();
        for (int k = 0; k < 4; k++) {
            for (int l = 1; l <= 2; l++) {
                int ni = i + di[k] * l, nj = j + dj[k] * l;
                if (ni < 0 || ni >= h || nj < 0 ||
                    nj >= w) {
                    continue;
                }
                int wall = grid[ni][nj] == '#' || l == 2;
                int nd = distS[i][j] + wall;
                if (nd < distS[ni][nj]) {
                    distS[ni][nj] = nd;
                    (wall ? q.push_back({ni, nj})
                          : q.push_front({ni, nj}));
                }
            }
        }
    }
    cout << distS[c][d] << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
