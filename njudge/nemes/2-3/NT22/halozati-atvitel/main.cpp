#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, K, H;
    cin >> N >> M >> K >> H;

    vector<vector<array<int, 2>>> g(N + 1);

    while (M--) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({V, W});
        g[V].push_back({U, W});
    }

    vector<int> speedS(N + 1, -1);
    queue<array<int, 2>> q;

    q.push({K, 0});
    speedS[K] = 100'001;

    while (!q.empty()) {
        auto [u, h] = q.front();
        q.pop();

        if (h > H) continue;

        for (auto [v, w] : g[u]) {
            speedS[v] = max(speedS[v], min(speedS[u], w));
            q.push({v, h + 1});
        }
    }

    for (int i = 1; i <= N; i++) {
        if (i == K) cout << 0 << "\n";
        else cout << speedS[i] << "\n";
    }
}