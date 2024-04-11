#include <bits/stdc++.h>
using namespace std;

int N, M, T, P, E, INF = 1e9;
vector<vector<array<int, 2>>> g;
vector<int> tom, jerry;

void bfs(int s, vector<int>& d, int min_w, int goal) {
    queue<int> q({s});
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == goal) return;
        for (auto [v, w] : g[u]) {
            if (d[u] + 1 < d[v] && min_w <= w) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N >> M >> T >> P >> E;

    g.resize(N + 1);
    while (M--) {
        int A, B, S;
        cin >> A >> B >> S;
    
        g[A].push_back({B, S});
        g[B].push_back({A, S});
    }

    bfs(T, tom, 2, 0);

    while (P--) {
        int K;
        cin >> K;
        jerry.assign(N + 1, INF);
        bfs(K, jerry, 1, E);
    }
}