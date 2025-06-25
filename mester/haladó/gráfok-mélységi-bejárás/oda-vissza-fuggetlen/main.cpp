#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--, b--;
    vector<map<int, int>> g(2 * n);
    for (int u = 0; u < n; u++) g[u][u + n] = 1;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        g[u + n][v] = 1;
        g[v + n][u] = 1;
    }

    auto bfs = [&](int s, int t, vector<int>& par) {
        fill(par.begin(), par.end(), -1);
        par[s] = -2;
        queue<array<int, 2>> q({{s, 1}});
        while (!q.empty()) {
            auto [u, flow] = q.front();
            q.pop();
            if (u == t) { return flow; }
            for (auto [v, cap] : g[u]) {
                if (par[v] == -1 && cap) {
                    par[v] = u;
                    q.push({v, min(flow, cap)});
                }
            }
        }
        return 0;
    };

    function<vector<int>(int, int)> path =
        [&](int u, int t) -> vector<int> {
        cout << u << endl;
        sleep(1);
        vector<int> result({u});
        if (u != t) {
            for (auto [v, cap] : g[u]) {
                if (cap) {
                    for (int w : path(v, t)) {
                        result.push_back(w);
                    }
                    break;
                }
            }
        }
        return result;
    };

    int flow = 0, new_flow;
    vector<int> par(2 * n);
    while ((new_flow = bfs(a + n, b, par))) {
        flow += new_flow;
        int cur = b;
        while (cur != a + n) {
            g[par[cur]][cur] -= new_flow;
            g[cur][par[cur]] += new_flow;
            cur = par[cur];
        }

        if (flow == 2) break;
    }
}
