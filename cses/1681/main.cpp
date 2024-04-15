#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
stack<int> s;
vector<vector<int>> g;
vector<bool> vis;
vector<int> dp;

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
    }
    s.push(u);
}

int main() {
    int N, M;
    cin >> N >> M;
    g.resize(N + 1);
    vis.resize(N + 1);
    dp.resize(N + 1);
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
    }
    for (int u = 1; u <= N; u++) {
        if (!vis[u]) {
            dfs(u);
        }
    }
    
}
