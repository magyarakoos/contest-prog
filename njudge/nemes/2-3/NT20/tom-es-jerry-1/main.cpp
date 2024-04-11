#include <bits/stdc++.h>
using namespace std;

int N, M, T, P, E, INF = INT_MAX;
vector<vector<int>> tg, jg;
vector<int> tom;
vector<bool> jerry;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N >> M >> T >> P >> E;

    tg.resize(N + 1);
    jg.resize(N + 1);
    tom.assign(N + 1, INF);
    jerry.resize(N + 1);
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
        for (int v : tg[u]) {
            if (tom[v] == INF) {
                tom[v] = tom[u] + 1;
                q.push(v);
            }
        }
    }

    priority_queue<array<int, 2>> pq;
    pq.push({tom[E], E});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (u < 0) continue;
        jerry[u] = 1;
        for (int v : g[u]) {
            if (jerry[v]) continue;
            pq.push({min(tom[u] - 1, dist - 1), v});
        }
    }

    while (P--) {
        int K;
        cin >> K;
        cout << (jerry[K] ? "IGEN" : "NEM") << '\n';
    }
}