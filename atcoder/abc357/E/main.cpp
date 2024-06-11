#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
#else
#define DB(...)
#endif
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

set<int> s;
vector<bool> vis;
vector<vector<int>> g;
vector<ll> dp;
ll result;

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
        dp[u] += dp[v]; // Update dp[u] after processing children
    }
    result += dp[u]; // Add dp[u] to result after processing children
    dp[u]++; // Increment dp[u] after adding it to result
}


#define cases 0
void solve() {
    int N;
    cin >> N;
    vis.resize(N + 1);
    g.resize(N + 1);
    dp.resize(N + 1);
    for (int u = 1; u <= N; u++) {
        int V;
        cin >> V;
        g[V].push_back(u);
        result += u == V;
    }
    for (int u = 1; u <= N; u++) {
        if (!vis[u]) dfs(u);
    }
    cout << result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}