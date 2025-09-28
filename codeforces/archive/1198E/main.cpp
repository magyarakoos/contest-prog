#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e10;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> row({1, n}), col({1, n});
    for (int x : row) cout << x << "\n";
    vector<array<int, 4>> rectS(m);
    for (auto& [x1, y1, x2, y2] : rectS) {
        cin >> x1 >> y1 >> x2 >> y2;
        x2++, y2++;
        row.push_back(y1);
        row.push_back(y2);
        col.push_back(x1);
        col.push_back(x2);
    }

    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    row.erase(unique(row.begin(), row.end()), row.end());
    col.erase(unique(col.begin(), col.end()), col.end());

    map<int, int> row_pos, col_pos;
    int k = row.size() - 1, l = col.size() - 1;
    for (int i = 0; i <= k; i++) {
        row_pos[row[i]] = i;
        if (i) row[i - 1] = row[i] - row[i - 1];
    }
    for (int i = 0; i <= l; i++) {
        col_pos[col[i]] = i;
        if (i) col[i - 1] = col[i] - col[i - 1];
    }

    vector grid(k, vector<bool>(l));
    for (auto [x1, y1, x2, y2] : rectS) {
        for (int i = col_pos[y1]; i < col_pos[y2]; i++) {
            for (int j = row_pos[x1]; j < row_pos[x2];
                 j++) {
                grid[i][j] = 1;
            }
        }
    }

    int s = k + l, t = k + l + 1;

    vector<vector<int>> g(k + l + 2),
        cap(k + l + 2, vector<int>(k + l + 2));
    for (int i = 0; i < k; i++) {
        g[s].push_back(i);
        cap[s][i] = row[i];
    }
    for (int i = 0; i < l; i++) {
        g[k + i].push_back(t);
        cap[k + i][t] = col[i];
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            if (grid[i][j]) {
                g[i].push_back(k + j);
                g[k + j].push_back(i);
                cap[i][k + j] = INF;
            }
        }
    }

    auto bfs = [&](vector<int>& par) -> int {
        fill(par.begin(), par.end(), -1);
        par[s] = -2;
        queue<array<int, 2>> q({{s, INF}});

        while (!q.empty()) {
            auto [u, flow] = q.front();
            q.pop();
            for (int v : g[u]) {
                if (par[v] == -1 && cap[u][v]) {
                    par[v] = u;
                    int nflow = min(flow, cap[u][v]);
                    if (v == t) return nflow;
                    q.push({v, nflow});
                }
            }
        }

        return 0;
    };

    int flow = 0, nflow;
    vector<int> par(k + l + 2);
    while ((nflow = bfs(par))) {
        flow += nflow;
        int u = t;
        while (u != s) {
            int v = par[u];
            cap[v][u] -= nflow;
            cap[u][v] += nflow;
            u = v;
        }
    }

    cout << flow << "\n";
}
