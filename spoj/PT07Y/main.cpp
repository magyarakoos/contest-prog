#include <bits/stdc++.h>
using namespace std;
#define end(b) cout << (b ? "YES" : "NO"); exit(0)
vector<vector<int>> g;
vector<bool> vis;

void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        if (vis[v]) end(0);
        vis[v] = 1;
        dfs(v, u);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    if (M != N - 1) end(0);

    g.resize(N + 1);
    vis.resize(N + 1);
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }
    end()
}