
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
vector<vector<ll>> g;
vector<ll> countS;
vector<ll> totalS;
vector<int> result;
vector<bool> vis;
vector<bool> getThis;

void dp_dfs(int u) {
    if (size(g[u]) == 0) {
        totalS[u] = countS[u];
        getThis[u] = 1;
        return;
    }

    ll sum = 0;
    for (int neigh : g[u]) {
        if (!vis[neigh]) {
            vis[neigh] = 1;
            dp_dfs(neigh);
        }
        sum += totalS[neigh];
    }

    if (sum < countS[u]) {
        getThis[u] = 1;
    }

    totalS[u] = max(sum, countS[u]);
}

void collect_spots(int u) {
    if (getThis[u]) {
        result.push_back(u);
    } else {
        for (int neigh : g[u]) {
            collect_spots(neigh);
        }
    }
}

int main() {
    speed;

    cin >> N;

    countS .resize(N + 1);
    totalS .resize(N + 1);
    g      .resize(N + 1);
    vis    .resize(N + 1);
    getThis.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> countS[i];
    }

    for (int i = 2; i <= N; i++) {
        int u;
        cin >> u;
        g[u].push_back(i);
    }

    dp_dfs(1);
    collect_spots(1);

    cout << totalS[1] << '\n' << size(result) << '\n';
    for (int x : result) cout << x << ' ';
    cout << '\n';
}
