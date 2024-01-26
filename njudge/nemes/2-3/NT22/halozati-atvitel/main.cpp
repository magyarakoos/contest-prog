
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

struct Route {
    int node;
    int weight;
    int count;
    bool operator()(Route a, Route b) {
        return a.weight > b.weight;
    }
};

constexpr int INF = 1e9;

int main() {

    int N, M, K, H;
    cin >> N >> M >> K >> H;

    vector<vector<point>> g(N + 1);

    while (M--) {
        int U, V, B;
        cin >> U >> V >> B;
        g[U].push_back({V, 100'000 - B});
        g[V].push_back({U, 100'000 - B});
    }

    vector<int> distS(N + 1, INF);
    priority_queue<Route, vector<Route>, Route> pq;

    distS[K] = 0;
    for (auto [neigh, weight] : g[K]) {
        distS[neigh] = weight;
        pq.push({neigh, weight, 1});
    }

    while (!pq.empty()) {
        auto [node, weight, count] = pq.top(); pq.pop();

        if (count + 1 > H || distS[node] != weight) {
            continue;
        }

        for (auto [neigh, neigh_w] : g[node]) {
            int new_weight = min(weight, neigh_w);
            if (new_weight < distS[neigh]) {
                distS[neigh] = new_weight;
                pq.push({neigh, new_weight, count + 1});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << 100'000 - distS[i] << ' ';
    }
}