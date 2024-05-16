// most valamiért nem működik az IDE-n belüli leadás, 
// majd megpróbálom később
// -- accepted, submission ID: 33054309
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using route = pair<ll, int>; // dist, node

const ll INF = 1e18;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<array<int, 2>>> g(N + 1);

    while (M--) {
        int U, V, W;
        cin >> U >> V >> W;
        if (U == V) continue;
        U++, V++;
        g[U].push_back({V, W});
        g[V].push_back({U, W});
    }

    vector<ll> distS(N + 1, INF);
    priority_queue<route, vector<route>, greater<route>> pq;

    while (Q--) {
        int S;
        cin >> S;
        S++;
        distS.assign(N + 1, INF);
        distS[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();
            if (dist != distS[u]) continue;
            for (auto [v, w] : g[u]) {
                if (dist + w < distS[v]) {
                    distS[v] = dist + w;
                    pq.push({dist + w, v});
                }
            }
        }

        int mx = 0, cnt = 0;
        for (int u = 1; u <= N; u++) {
            if (distS[u] == INF) continue;
            if (mx < distS[u]) {
                mx = distS[u];
                cnt = 1;
            }
            else if (mx == distS[u]) {
                cnt++;
            }
        }

        cout << mx << " " << cnt << "\n";
    }
}
