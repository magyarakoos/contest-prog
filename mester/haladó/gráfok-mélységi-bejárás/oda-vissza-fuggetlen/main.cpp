#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--, b--;
    vector<map<int, int>> g(2 * n), gr(2 * n);
    for (int u = 0; u < n; u++) g[u][u * 2] = 1;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        g[u * 2][v] = 1;
        g[v * 2][u] = 1;
    }

    auto bfs = [&](int s, int t, vector<int>& par) {
        fill(par.begin(), par.end(), -1);
        par[s] = -2;
        queue<array<int, 2>> q({{s, 1}});
        while (!q.empty()) {
            auto [u, flow] = q.front();
            q.pop();
            if (u == t) return flow;
            for (auto [v, cap] : gr[u]) {
                if (par[v] == -1 && cap) {
                    par[v] = u;
                    q.push({v, min(flow, cap)});
                }
            }
        }
        return 0;
    };

    int flow = 0, new_flow;
    vector<int> par(2 * n);
    while ((new_flow = bfs(a, b, par))) {
        flow += new_flow;
        int cur = b;
        while (cur != a) {
            gr[par[cur]][cur] -= new_flow;
            gr[cur][par[cur]] += new_flow;
            cur = par[cur];
        }
    }

    cout << flow << "\n";
}
