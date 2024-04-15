#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
stack<int> s;
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
        g[U].push_back(V);
    }
    queue<int> q({1});
    dp[1] = 1;
    vis[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (!vis[])
            dp[v] = (dp[u] + dp[v]) % MOD;
            q.push(v);
        }
    }
}
