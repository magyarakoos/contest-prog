#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector g(n, vector<int>(m));
    for (auto& row : g) {
        for (int& x : row) cin >> x;
    }
    vector<array<int, 3>> ptS;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!g[i][j]) continue;
            ptS.push_back({g[i][j], i, j});
        }
    }
    sort(ptS.begin(), ptS.end());

    vector vis(n, vector<bool>(m));
    auto bfs = [&](int si, int sj) {
        queue<array<int, 2>> q({{si, sj}});
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
        }
    };
}
