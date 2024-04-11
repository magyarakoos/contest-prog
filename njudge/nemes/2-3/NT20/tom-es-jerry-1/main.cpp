#include <bits/stdc++.h>
using namespace std;
int N, M, T, P, E, INF = 1e9;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> N >> M >> T >> P >> E;

    vector<vector<int>> jg(N + 1), tg(N + 1);
    vector<int> tom(N + 1, INF);
    vector<bool> jerry(N + 1);

    while (M--) {
        int U, V, W;
        cin >> U >> V >> W;
        jg[U].push_back(V);
        jg[V].push_back(U);
        if (W == 2) {
            tg[U].push_back(V);
            tg[V].push_back(U);
        }
    }

    queue<int> q({T});
    tom[T] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : tg[u]) {
            if (tom[v] == INF) {
                tom[v] = tom[u] + 1;
                q.push(v);
            }
        }
    }

    jerry[E] = 1;
    priority_queue<array<int, 2>> pq;
    pq.push({tom[E], E});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (dist < 0) continue;
        jerry[u] = 1;
        for (int v : jg[u]) {
            if (!jerry[v]) {
                pq.push({min(tom[v] - 1, dist - 1), v});
            }
        }
    }

    while (P--) {
        int K;
        cin >> K;
        cout << (jerry[K] ? "IGEN" : "NEM") << '\n';
    }
}
