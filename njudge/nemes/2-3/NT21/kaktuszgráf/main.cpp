
#include <bits/stdc++.h>

#pragma region Utility

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

#define max_index(v) max_element(all(v)) - v.begin()
#define min_index(v) min_element(all(v)) - v.begin()
#define smax(x, y) x = max(x, y)
#define smin(x, y) x = min(x, y)

#define sum(v) accumulate(all(v), 0)
#define product(v, T) accumulate(all(v), 1, multiplies<T>())

using namespace std;
using ll = long long;
using point = array<int, 2>;

int max(point p) { return max(p[0], p[1]); }
int min(point p) { return min(p[0], p[1]); }

template <typename T>
vector<T> prefix_sum(const vector<T>& v) {
    vector<T> result(size(v));
    partial_sum(all(v), result.begin());
    return result;
}

#pragma endregion

int N, M;
vector<int> vis;
vector<vector<int>> g;
int result;

void dfs(int u, int t) {
    if (vis[u]) {
        smax(result, t - vis[u]);
        return;
    }

    vis[u] = t;

    for (int neigh : g[u]) {
        dfs(neigh, t + 1);
    }
}

int main() {
    speed;

    cin >> N >> M;

    g.resize(N + 1);
    vis.resize(N + 1);

    while (M--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    cout << result;
}
