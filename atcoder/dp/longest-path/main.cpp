#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> indegS, dp;
vector<bool> vis;

void dfs(int u) {
    for (int v : g[u]) {
        dp[v] = max(dp[v], dp[u] + 1);
        if (!--indegS[v]) dfs(v);
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    
    g.resize(N + 1);
    indegS.resize(N + 1);
    dp.assign(N + 1, 0);
    vis.resize(N + 1);
    
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        indegS[V]++;
    }

    // magic starting node
    for (int u = 1; u <= N; u++) {
        g[0].push_back(u);
    }

    dfs(0);
    cout << *max_element(dp.begin() + 1, dp.end());
}