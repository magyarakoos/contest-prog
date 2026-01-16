#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e12;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<array<int, 2>>> g(n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    auto check = [&](int start, int cap) -> bool {
        using di = array<int, 2>;
        using state = pair<di, int>;
        auto calc = [&](di d, int w) -> array<int, 2> {
            if (w > cap) return {INF, INF};
            if (w <= d[1]) return {d[0], d[1] - w};
            return {d[0] + 1, cap};
        };
        priority_queue<state, vector<state>, greater<state>>
            pq;
        vector<array<int, 2>> dist(n + 1, {INF, INF});
        dist[start] = {0, cap};
        pq.push({dist[start], start});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dist[u] != d) { continue; }
            for (auto [v, w] : g[u]) {
                auto nd = calc(d, w);
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dist[i][0] > k) return 0;
        }
        return 1;
    };
    auto f = [&](int cap) -> bool {
        for (int start = 1; start <= n; start++) {
            if (!check(start, cap)) return 0;
        }
        return 1;
    };

    int l = 0, r = INF;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (f(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << "\n";
}
