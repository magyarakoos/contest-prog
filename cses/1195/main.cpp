#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using route = tuple<ll, bool, int>; // dist, used, node

const ll INF = 1e18;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<array<int, 2>>> g(N + 1);

    while (M--) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({V, W});
    }

    vector<ll> distS_unused(N + 1, INF), distS_used(N + 1, INF);
    vector<array<int, 2>> prv(N + 1);
    priority_queue<route, vector<route>, greater<route>> pq;

    distS_used[1] = 0;
    distS_unused[1] = 0;
    pq.push({0, 0, 1});

    while (!pq.empty()) {
        auto [dist, used, u] = pq.top();
        pq.pop();

        if ((used && dist != distS_used[u]) || 
            (!used && dist != distS_unused[u])
        ) continue;

        for (auto [v, w] : g[u]) {
            if (used) {
                if (dist + w < distS_used[v]) {
                    distS_used[v] = dist + w;
                    pq.push({dist + w, 1, v});
                }
            } else {
                if (dist + w / 2 < distS_used[v]) {
                    distS_used[v] = dist + w / 2;
                    pq.push({dist + w / 2, 1, v});
                }
                if (dist + w < distS_unused[v]) {
                    distS_unused[v] = dist + w;
                    pq.push({dist + w, 0, v});
                }
            }
        }
    }

	cout << distS_used[N];
}
