#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = array<int, 3>; // weight, node, edge_index
using route = tuple<ll, int, int>; // dist, node, edge_index

const ll INF = 1e18;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<edge>> g(N + 1);

    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({W, V, i + 1});
        g[V].push_back({W, U, i + 1});
    }

    vector<ll> distS(N + 1, INF);
    priority_queue<route, vector<route>, greater<route>> pq;
    vector<int> res;

    distS[1] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [dist, u, i] = pq.top();
        pq.pop();
        if (dist != distS[u]) continue;
        if (i) res.push_back(i);

        for (auto [w, v, i] : g[u]) {
            if (dist + w < distS[v]) {
                distS[v] = dist + w;
                pq.push({dist + w, v, i});
            }
        }
    }

    int rem = min({K, M, (int)res.size()});

    cout << rem << "\n";
    for (int i = 0; i < rem; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}
