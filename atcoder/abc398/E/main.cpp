#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<vector<int>> g(N + 1);
    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(N + 1);
    int even_cnt = 0, odd_cnt = 0;
    function<void(int, int)> dfs = [&](int u,
                                       int p) -> void {
        for (int v : g[u]) {
            if (v != p) {
                d[v] = d[u] + 1;
                dfs(v, u);
            }
        }
        (d[u] % 2 ? odd_cnt : even_cnt)++;
    };
    dfs(1, 0);

    vector<vector<int>> distS(N + 1,
                              vector<int>(N + 1, -1));

    for (int start = 1; start <= N; start++) {
        queue<int> q;
        q.push(start);
        distS[start][start] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (distS[start][v] == -1) {
                    distS[start][v] = distS[start][u] + 1;
                    q.push(v);
                }
            }
        }
    }

    set<array<int, 2>> valid_edgeS;
    for (int u = 1; u <= N; u++) {
        for (int v = u + 1; v <= N; v++) {
            if (distS[u][v] % 2 == 1) {
                if (find(g[u].begin(), g[u].end(), v) ==
                    g[u].end()) {
                    valid_edgeS.insert({u, v});
                }
            }
        }
    }
    assert(valid_edgeS.size() ==
           even_cnt * odd_cnt - (N - 1));

    if (valid_edgeS.size() % 2) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
        int u, v;
        cin >> u >> v;
        assert(valid_edgeS.count({u, v}));
        valid_edgeS.erase({u, v});
    }

    while (1) {
        assert(!valid_edgeS.empty());

        auto [u, v] = *valid_edgeS.begin();
        valid_edgeS.erase({u, v});

        cout << u << " " << v << endl;
        cin >> u >> v;
        if (u > v) swap(u, v);

        if (u == -1) return;

        assert(valid_edgeS.count({u, v}));
        valid_edgeS.erase({u, v});
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
