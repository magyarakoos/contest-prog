#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<int> order;

void dfs(int u, int p = 0) {
    vis[u] = 1;
    order.push_back(u);
    for (int v : g[u]) {
        if (v == p) continue;

        if (!vis[v]) {
            dfs(v, u);
        } else {
            vector<int> result({v});
            do {
                result.push_back(order.back());
                order.pop_back();
            } while (result[0] != result.back());

            cout << result.size() << "\n";
            for (int x : result) cout << x << " ";
            cout << "\n";
            exit(0);
        }
    }
    order.pop_back();
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    g.resize(N + 1);
    vis.resize(N + 1);

    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }

    for (int u = 1; u <= N; u++) {
        if (!vis[u]) dfs(u);
    }

    cout << "IMPOSSIBLE\n";
}
