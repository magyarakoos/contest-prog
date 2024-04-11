#include <bits/stdc++.h>
using namespace std;
using point = array<int, 2>;

int N, M, T, P, E, INF = 1e9;
vector<vector<point>> g;
vector<int> tom;
vector<bool> jerry;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N >> M >> T >> P >> E;

    g.resize(N + 1);
    tom.assign(N + 1, INF);
    jerry.resize(N + 1);
    while (M--) {
        int A, B, S;
        cin >> A >> B >> S;
    
        g[A].push_back({B, S});
        g[B].push_back({A, S});
    }

    queue<int> q({T});
    tom[T] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, w] : g[u]) {
            if (tom[u] + 1 < tom[v] && w == 2) {
                tom[v] = tom[u] + 1;
                q.push(v);
            }
        }
    }
    
    priority_queue<point> pq;
    pq.push({tom[E], E});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (u < 0) continue;
        jerry[u] = 1;
        for (auto [v, w] : g[u]) {
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