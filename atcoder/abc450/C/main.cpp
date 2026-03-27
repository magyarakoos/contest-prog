#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;
const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

#define cases 0
void solve() {
    int w, h;
    cin >> w >> h;
    vector a(h, vector<bool>(w)), vis(h, vector<bool>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            a[i][j] = c == '.';
        }
    }
    int result = 0;
    bool ok = 1;
    function<void(int, int)> dfs = [&](int i, int j) {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
                ok = 0;
                continue;
            }
            if (!vis[ni][nj] && a[ni][nj]) dfs(ni, nj);
        }
    };
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!vis[i][j]) {
                ok = 1;
                dfs(i, j);
                result += ok;
            }
        }
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
