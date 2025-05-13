#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int h, w;
    cin >> h >> w;
    vector grid(h, string(w, 0));
    vector dist(h, vector<int>(w, 1e9));
    queue<array<int, 2>> q;
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'E') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni < 0 || ni < 0 || ni >= h || nj >= w ||
                grid[ni][nj] == '#' ||
                dist[ni][nj] <= dist[i][j] + 1) {
                continue;
            }
            dist[ni][nj] = dist[i][j] + 1;
            grid[ni][nj] = "^v<>"[k];
            q.push({ni, nj});
        }
    }
    for (const string& row : grid) cout << row << "\n";
}
