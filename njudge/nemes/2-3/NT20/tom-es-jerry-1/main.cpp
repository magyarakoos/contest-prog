#include <bits/stdc++.h>
using namespace std;

int N, M, T, P, E, INF = 1e9;
vector<vector<array<int, 2>>> g;

void bfs(int s, vector<int>& d, int w) {
    queue<int> q({s});
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (d[u] + 1 < d[v] && )
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N >> M >> T >> P >> E;

    g.resize(N + 1);
    vector<int> tom(N + 1, INF), jerry(N + 1, INF);
    while (M--) {
        int A, B, S;
        cin >> A >> B >> S;
    
        g[A].push_back({B, S});
        g[B].push_back({A, S});
    }


    while (P--) {
        int K;
        cin >> K;
        cout << (K & 1 ? "IGEN" : "NEM") << '\n';
    }
}