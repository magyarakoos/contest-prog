#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> vis, done;
vector<int> order;

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (done[v]) continue;
        if (vis[v]) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        dfs(v);
    }
    done[u] = 1;
    order.push_back(u);
}

int main() {
    int N, M;
    cin >> N >> M;

    g.resize(N + 1);
    vis.resize(N + 1);
    done.resize(N + 1);

    while (M--) {
        int U, V;
        cin >> U >> V;
        g[V].push_back(U);
    }

    for (int u = 1; u <= N; u++) {
        if (!vis[u]) dfs(u);
    }

    for (int x : order) cout << x << "\n";
}
