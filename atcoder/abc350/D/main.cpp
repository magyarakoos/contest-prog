#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<bool> vis;
vector<int> sizeS, degS;

void dfs(int u) {
    vis[u] = 1;
    sizeS.back()++;
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
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }
    ll result = 0;
    for (int u = 1; u <= N; u++) {
        if (!vis[u]) {
            sizeS.push_back(0);
            dfs(u);
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}