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
    for (int u = 1; u <= N; u++) {
        if (!vis[u]) {
            dfs(u);
        }
    }
    vis.assign(N + 1, 0);
    vector<int> order;
    while (!s.empty()) {
        order.push_back(s.top());
        s.pop();
    }
    for (int x : order) cout << x << " ";
    cout << "\n";
}
