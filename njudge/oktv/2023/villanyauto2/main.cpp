#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18;

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
        auto calc = [&](int ch, int cp,
                        int w) -> array<int, 2> {
            if (w > cap) return {INF, INF};
            if (cp + w <= cap) return {ch, cp + w};
            return {ch + 1, 0};
        };
        using state = array<int, 3>;
        priority_queue<state, vector<state>, greater<state>>
            pq;
        vector<array<int, 2>> dist(n + 1, {INF, INF});
        dist[start] = {0, 0};
        pq.push({0, 0, start});
        while (!pq.empty()) {
            auto [ch, cp, u] = pq.top();
            pq.pop();
            if (dist[u][0] != ch || dist[u][1] != cp) {
                continue;
            }
            for (auto [v, w] : g[u]) {
                auto nc = calc(ch, cp, w);
                if (nc < dist[v]) {
                    dist[v] = nc;
                    pq.push({nc[0], nc[1], v});
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

    int l = 0, r = 1e12;
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
