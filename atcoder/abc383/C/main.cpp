#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

#define cases 0
void solve() {
    int H, W, D;
    cin >> H >> W >> D;
    vector a(H, vector<int>(W)), vis(H, vector<int>(W));
    queue<array<int, 2>> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c != '#') a[i][j] = 1;
            if (c == 'H') {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (vis[i][j] - 1 == D) continue;
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= H || nj >= W ||
                !a[ni][nj] || vis[ni][nj]) {
                continue;
            }
            q.push({ni, nj});
            vis[ni][nj] = vis[i][j] + 1;
        }
    }

    int result = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            result += vis[i][j] > 0;
        }
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
