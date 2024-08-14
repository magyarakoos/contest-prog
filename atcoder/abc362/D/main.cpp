#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    vector<vector<array<int, 2>>> g(N + 1);

    while (M--) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({V, W});
        g[V].push_back({U, W});
    }

    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>>
        pq;

    vector<ll> distS(N + 1, LLONG_MAX);

    distS[1] = A[1];
    pq.push({A[1], 1});

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (distS[u] != dist) continue;
        for (auto [v, w] : g[u]) {
            ll ndist = dist + w + A[v];
            if (ndist < distS[v]) {
                distS[v] = ndist;
                pq.push({ndist, v});
            }
        }
    }

    for (int u = 2; u <= N; u++) {
        cout << distS[u] << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
