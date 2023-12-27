#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define all(v) v.begin(), v.end()

using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<int> dp;

void dfs(int n) {
    vis[n] = 1;
    for (int nb : g[n]) {
        if (!vis[nb]) {
            dfs(nb);
        }
        dp[n] = max(dp[n], dp[nb] + 1);
    }
}

int main() {
    speed;

    int N, M;
    cin >> N >> M;

    g.resize(N + 1);
    vis.resize(N + 1);
    dp.resize(N + 1);

    while (M--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    cout << *max_element(all(dp));
}
