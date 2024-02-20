#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

vector<vector<int>> g;

int dfs(int u, int par = 0, int dist = 0) {
    if (size(g[u]) > 2 || (par && size(g[u]) == 1)) {
        return dist;
    }

    cout << u << ' ' << par << ' ' << dist << '\n';

    for (int neigh : g[u]) {
        if (neigh != par) {
            dfs(neigh, u, dist + 1);
        }
    }

    return 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    g.resize(N + 1);

    while (M--) {
        int U, V;
        cin >> U >> V;

        g[U].push_back(V);
        g[V].push_back(U);
    }

    vector<int> lengthS(N + 1);

    int mx = 0;

    for (int i = 1; i <= N; i++) {
        if (size(g[i]) == 1) {
            mx = max(mx, (lengthS[i] = dfs(i)));
        }
    }

    cout << mx << '\n';
}