#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

void dfs(int u, vector<bool>& vis, vector<vector<int>>& g) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, vis, g);
        }
    }
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    
    vector<array<int, 3>> edgeS(M);
    vector<vector<int>> g1(N + 1), g2(N + 1);
    vector<bool> vis1(N + 1), vis2(N + 1);

    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        edgeS[i] = {U, V, W};
        g1[U].push_back(V);
        g2[V].push_back(U);
    }

    dfs(1, vis1, g1);
    dfs(N, vis2, g2);


    vector<ll> distS(N + 1, -INF);

    distS[1] = 0;

    for (int i = 1; i <= N; i++) {
        for (auto [u, v, w] : edgeS) {
            distS[v] = max(distS[v], distS[u] + w);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (auto [u, v, w] : edgeS) {
            if (vis1[v] && vis2[v] && distS[u] + w > distS[v]) {
                cout << "-1\n";
                exit(0);
            }
        }
    }

    cout << distS[N];
}
