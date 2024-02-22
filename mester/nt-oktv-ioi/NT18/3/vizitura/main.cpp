#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;
using edge = struct { int node; int w; };

vector<vector<edge>> g;
vector<bool> vis;
vector<int> dp, from;

void dfs(int u) {
    vis[u] = 1;

    for (edge neigh : g[u]) {

        if (!vis[neigh.node]) {
            dfs(neigh.node);
        }

        dp[u] = max(dp[u], dp[neigh.node] + neigh.w);
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    g.resize(N + 1);
    vis.resize(N + 1);
    dp.resize(N + 1);
    from.resize(N + 1);

    for (int i = 1; i < N; i++) {
        int U, V, W;
        cin >> U >> V >> W;

        g[U].push_back({V, W});
        g[V].push_back({U, W});
    }

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

}