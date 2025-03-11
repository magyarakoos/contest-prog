#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<array<int, 2>>> g(N + 1);
    vector<array<int, 2>> distS(N + 1, {INF, INF});
    priority_queue<array<int, 3>, vector<array<int, 3>>,
                   greater<array<int, 3>>>
        pq;
    distS[1] = {0, INF};
    pq.push({0, 1, 0});

    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back({V, 0});
        g[V].push_back({U, 1});
    }

    while (!pq.empty()) {
        auto [d, u, flip] = pq.top();
        pq.pop();
        if (d != distS[u][flip]) continue;
        for (auto [v, w] : g[u]) {
            if (flip == w) {
                if (d + 1 < distS[v][flip]) {
                    distS[v][flip] = d + 1;
                    pq.push({d + 1, v, flip});
                }
            } else {
                if (d + X + 1 < distS[v][!flip]) {
                    distS[v][!flip] = d + X + 1;
                    pq.push({d + X + 1, v, !flip});
                }
            }
        }
    }

    cout << min(distS[N][0], distS[N][1]) << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
