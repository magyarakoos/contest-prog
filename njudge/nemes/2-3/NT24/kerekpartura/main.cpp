#include <bits/stdc++.h>
#define speed cin.tie(0); ios::sync_with_stdio(0)
using namespace std;

int N, M, K;

vector<bool> bfs(const vector<vector<int>>& g) {
    vector<bool> vis(N + 1);
    queue<int> q;
    q.push(K);
    vis[K] = 1;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neigh : g[node]) {
            if (!vis[neigh]) {
                vis[neigh] = 1; 
                q.push(neigh);
            }
        }
    }
    return vis;
}

int main() {
    speed;

    cin >> N >> M >> K;

    vector<vector<int>> g(N + 1), g2(N + 1);

    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g2[V].push_back(U);
    }

    vector<bool> vis = bfs(g), vis2 = bfs(g2), both(N + 1);

    for (int i = 1; i <= N; i++) {
        both[i] = vis[i] && vis2[i];
    }

    vector<int> base;
    for (int i = 1; i <= N; i++) {
        if (both[i]) base.push_back(i);
    }

    unordered_set<int> result;
    for (int x : base) {
        result.insert(x);
        for (int neigh : g[x]) {
            result.insert(neigh);
        }
    }

    result.erase(K);

    if (result.empty()) {
        cout << 0;
        exit(0);
    }

    cout << result.size() << '\n';
    for (int x : result) cout << x << ' ';
    cout << '\n';
}
