#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

int n;

set<vector<vector<int>>> all;

vector<vector<int>> edges;
vector<int> deg;

void dfs(int u) {
    if (deg[u] == 2) {
        bool done = 1;
        for (int i = 1; i <= n; i++) {
            if (deg[i] < 2) {
                done = 0;
                dfs(i);
                break;
            }
        }
        if (done) { all.insert(edges); }
    } else if (deg[u] == 1) {
        for (int i = 1; i <= n; i++) {
            if (i != u && deg[i] < 2 && !edges[u][i]) {
                deg[i]++;
                deg[u]++;
                edges[u][i] = 1;
                edges[i][u] = 1;
                dfs(i);
                edges[u][i] = 0;
                edges[i][u] = 0;
                deg[u]--;
                deg[i]--;
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (i != u && j != u) {
                    if (deg[i] < 2 && deg[j] < 2) {
                        if (!edges[u][i] && !edges[u][j]) {
                            deg[i]++;
                            deg[j]++;
                            deg[u] = 2;
                            edges[u][i] = 1;
                            edges[u][j] = 1;
                            edges[i][u] = 1;
                            edges[j][u] = 1;
                            dfs(i);
                            edges[u][i] = 0;
                            edges[u][j] = 0;
                            edges[i][u] = 0;
                            edges[j][u] = 0;
                            deg[u] = 0;
                            deg[i]--;
                            deg[j]--;
                        }
                    }
                }
            }
        }
    }
}

#define cases 0
void solve() {
    cin >> n;
    edges.assign(n + 1, vector<int>(n + 1));
    deg.assign(n + 1, 0);
    dfs(1);
    vector<vector<int>> actual(n + 1, vector<int>(n + 1));
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        actual[u][v] = 1;
        actual[v][u] = 1;
    }
    int result = LLONG_MAX;
    for (auto edges : all) {
        int curr = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (edges[i][j] != actual[i][j]) { curr++; }
            }
        }
        result = min(result, curr);
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
