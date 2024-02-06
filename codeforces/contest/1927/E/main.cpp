// gave up :skull:
#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int result;
vector<vector<array<int, 2>>> g;
vector<bool> vis;

void dfs(int u, int minw) {
    if (vis.at(u)) {
        result = min(result, minw);
        return;
    }

    vis.at(u) = 1;

    for (auto [neigh, weight] : g.at(u)) {
        dfs(neigh, min(minw, weight));
    }
}

void solve() {
    int N, M;
    cin >> N >> M;

    g.assign(N + 1, vector<array<int, 2>>());
    vis.assign(N + 1, 0);

    while (M--) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({V, W});
        g[V].push_back({U, W});
    }

    result = INT_MAX;
    dfs(1, INT_MAX);

    cout << result << '\n';
}

int main() {
    #ifndef LOCAL
    cin.tie(0), ios::sync_with_stdio(0);
    #else
    ifstream fin("../input");
    #define cin fin
    #endif
    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}