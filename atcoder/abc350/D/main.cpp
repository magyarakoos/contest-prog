#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<bool> vis;
vector<int> degS;
ll group_size, group_edges;

void dfs(int u) {
    vis[u] = 1;
    group_size++;
    group_edges += degS[u];
    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

#define cases 0
void solve() {
    int N, M;
    cin >> N >> M;
    vis.resize(N + 1);
    g.resize(N + 1);
    degS.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        degS[U]++;
        g[U].push_back(V);
        g[V].push_back(U);
    }
    ll result = 0;
    for (int u = 1; u <= N; u++) {
        if (!vis[u]) {
            group_size = 0;
            group_edges = 0;
            dfs(u);
            result += group_size * (group_size - 1) / 2 - group_edges;
        }
    }
    cout << result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
