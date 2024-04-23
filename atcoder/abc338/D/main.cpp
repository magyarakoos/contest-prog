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

}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}