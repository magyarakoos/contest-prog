#include <bits/stdc++.h>
using namespace std;
#define over(b) cout << (b ? "YES" : "NO"), exit(0)
vector<vector<int>> g;
vector<bool> vis;

void dfs(int u, int p) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        if (vis[v]) over(0);
        dfs(v, u);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    if (M != N - 1) over(0);

    g.resize(N + 1);
    vis.resize(N + 1);
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }
    dfs(1, 0);
    over((count(vis.begin() + 1, vis.end(), 1) == N));
}
