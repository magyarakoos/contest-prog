#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<bool> vis;
vector<int> group_degS, degS;
int curr;

void dfs(int u) {
    vis[u] = 1;
    curr++;
    group_degS.back() += degS[u];
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
            curr = 0;
            group_degS.push_back(0);
            dfs(u);
            cout << curr << " " << group_degS.back() << "\n";
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}