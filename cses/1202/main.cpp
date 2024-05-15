#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using route = pair<ll, int>;

const ll INF = 1e18, MOD = 1e9 + 7;

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

    vector<ll>
        distS(N + 1, INF),
        min_routeS(N + 1),
        min_count(N + 1),
        max_count(N + 1);

    priority_queue<route, vector<route>, greater<route>> pq;

    distS[1] = 0;
    min_routeS[1] = 1;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist != distS[u]) continue;

        for (auto [v, w] : g[u]) {
            if (dist + w < distS[v]) {

                min_count[v] = min_count[u] + 1;
                max_count[v] = max_count[u] + 1;
                min_routeS[v] = min_routeS[u];

                distS[v] = dist + w;
                pq.push({dist + w, v});
            }
            else if (dist + w == distS[v]) {
                
                max_count[v] = max(max_count[v], max_count[u] + 1);
                min_count[v] = min(min_count[v], min_count[u] + 1);

                min_routeS[v] += min_routeS[u];
                min_routeS[v] %= MOD;
            }
        }
    }

    cout << distS[N] << " "
         << min_routeS[N] << " "
         << min_count[N] << " "
         << max_count[N] << "\n";
}
