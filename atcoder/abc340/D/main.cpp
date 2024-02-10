#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

constexpr ll INF = 1e9 * 2 * 1e5;

struct Route {
    int node;
    ll dist;
    bool operator()(const Route& a, const Route& b) {
        return a.dist > b.dist;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<array<int, 2>>> g(N + 1);

    for (int i = 1; i < N; i++) {
        int A, B, X;
        cin >> A >> B >> X;
        g[i].push_back({i + 1, A});
        g[i].push_back({X, B});
    }

    priority_queue<Route, vector<Route>, Route> pq;
    vector<ll> distS(N + 1, INF);

    pq.push({1, 0});
    distS[1] = 0;

    while (!pq.empty()) {
        auto [node, dist] = pq.top();
        pq.pop();

        if (distS[node] != dist) {
            continue;
        }

        for (auto [neigh_node, neigh_dist] : g[node]) {
            int new_dist = dist + neigh_dist;

            if (new_dist < distS[neigh_node]) {
                distS[neigh_node] = new_dist;
                pq.push()
            }
        }
    }
}