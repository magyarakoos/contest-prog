#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;
vector<vector<int>> g;
vector<bool> vis;
vector<int> dp;

void dfs(int u) {
    for (int v : g[u]) {
        if ()
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    g.resize(N + 1);
    dp.resize(N + 1);
    vis.resize(N + 1);
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
    }
}
