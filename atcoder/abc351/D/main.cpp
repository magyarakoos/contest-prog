#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

vector<vector<int>> grid, vis;
constexpr int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int cnt, H, W, run, INF = 1e9;

void dfs(int i, int j) {
    vis[i][j] = (grid[i][j] == 2 ? INF : run);
    cnt++;
    if (grid[i][j] == 1) return;
    for (int k = 0; k < 4; k++) {
        int ni = i + dy[k], nj = j + dx[k];
        if (ni < 0 || nj < 0 || ni >= H || nj >= W || !grid[ni][nj] || vis[ni][nj] >= run)
            continue;
        dfs(ni, nj);
    }
}

#define cases 0
void solve() {
    cin >> H >> W;
    grid.assign(H, vector<int>(W, 2));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                grid[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dy[k], nj = j + dx[k];
                    if (ni < 0 || nj < 0 || ni >= H || nj >= W)
                        continue;
                    grid[ni][nj] = 1;
                }
            }
        }
    }
    vis.assign(H, vector<int>(W));
    int res = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 2 && !vis[i][j]) {
                cnt = 0;
                run++;
                dfs(i, j);
                res = max(res, cnt);
            }
        }
    }
    cout << res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
