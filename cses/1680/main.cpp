#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> dp, result;
vector<bool> vis;

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

string path(int u) {
    if (u == 1) return to_string(u);
    for (int v : g[u]) {
        if (dp[u] == dp[v] + 1) {
            return path(v) + " " + to_string(u);
        }
    }
    return 0;
}

int main() {
    int N, M;
    cin >> N >> M;

    g.resize(N + 1);
    dp.assign(N + 1, -2e9);
    vis.resize(N + 1);

    while (M--) {
        int U, V;
        cin >> U >> V;
        g[V].push_back(U);
    }

    dp[1] = 1;
    dfs(N);
    if (dp[N] < 0) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }

    cout << dp[N] << "\n" << path(N) << "\n";
}
