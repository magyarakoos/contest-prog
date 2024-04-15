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
}

int main() {
    int N, M;
    cin >> N >> M;
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
    }
    queue<int> q({1});
    vis[1] = dp[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << "\n";
        for (int v : g[u]) {
            dp[v] = (dp[u] + dp[v]) % MOD;
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    cout << dp[N];
}
