#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int N;
int t = 1;

vector<int> g, vis, path;
int cyc_start, cyc_end;

void dfs(int u) {
    if (vis[u]) {
        int new_cyc_start = vis[u];
        int new_cyc_end = t;
        if (new_cyc_end - new_cyc_start > cyc_end - cyc_start) {
            cyc_start = new_cyc_start;
            cyc_end = new_cyc_end;
        }
        return;
    }

    t++;
    dfs(g[u]);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;

    g.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        int u;
        cin >> u;
        g[i] = u;
    }

    vis.resize(N + 1);
    path.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            vis[i] = t;
            path[t] = i;
            dfs(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        cerr << path[i] << ' ';
    }
    cerr << '\n';
}