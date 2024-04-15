#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
vector<vector<int>> g;
vector<bool> vis;
vector<int> dp;

int main() {
    int N, M;
    cin >> N >> M;
    g.resize(N + 1);
    vis.resize(N + 1);
    dp.resize(N + 1);
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[V].push_back(U);
    }
    dp[N] = 1;
    queue<int> q({N});
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            } else {
                dp[u] = (dp[u] + dp[v]) % MOD;
            }
        }
    }
    
}
