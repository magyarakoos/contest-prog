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
vector<int> prv;
vector<ll> prv_dist;

// which is the farthest node from s
int bfs(int s) {
    vector<bool> vis(N + 1);
    vector<ll> dist(N + 1, 1e18);
    queue<int> q;

    vis[s] = 1;
    dist[s] = dist[0] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, w] : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dist[v] = dist[u] + w;
                prv[v] = u;
                prv_dist[v] = w;
                q.push(v);
            }
        }
    }

    return max_element(all(dist)) - dist.begin();
}

int main() {
    speed;
    cin >> N;

    prv.resize(N + 1);
    prv_dist.resize(N + 1);
    g.resize(N + 1);

    for (int i = 1; i < N; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({V, W});
        g[V].push_back({U, W});
    }

    int start = bfs(1);
    int end = bfs(start);

    vector<ll> distS;

    int curr = end;
    do {
        distS.push_back(prv_dist[curr]);
        curr = prv[curr];
    } while (curr != start);

    for (ll x : distS) cout << x << " ";
    cout << "\n" << start << " " << end << "\n";
}