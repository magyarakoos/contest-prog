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

int N;
vector<vector<array<ll, 2>>> g;
vector<ll> distS;
vector<int> parS;

void dfs(int u, int par) {
    for (auto [v, w] : g[u]) {
        if (v == par) continue;
        if (u == 3) continue;
        dfs(v, u);
        if (distS[v] < distS[u] + w) {
            distS[v] = distS[u] + w;
            parS[v] = u;
        }
    }
}

int main() {
    speed;
    cin >> N;

    g.resize(N + 1);
    distS.resize(N + 1);
    parS.resize(N + 1);
    for (int i = 1; i < N; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({V, W});
        g[V].push_back({U, W});
    }

    dfs(1, 0);
    int start = max_index(distS);

    distS.assign(N + 1, 0);
    parS .assign(N + 1, 0);

    dfs(start, 0);
    int end = max_index(distS);

    cout << start << " " << end << "\n";
    for (int i = 1; i <= N; i++) cout << distS[i] << " ";
    cout << "\n";
}
