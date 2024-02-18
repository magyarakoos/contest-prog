#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int N, M;
vector<vector<int>> g;
vector<int> color, parentS;
vector<bool> cycle;

void dfs(int u, int par) {

    if (color[u] == 2) {
        return;
    }

    if (color[u] == 1) {
        int curr = par;
        cycle[par] = 1;

        while (curr != u) {
            curr = parentS[curr];
            cycle[curr] = 1;
        }

        return;
    }

    parentS[u] = par;
    color[u] = 1;

    for (int neigh : g[u]) {
        if (neigh != parentS[u]) {
            dfs(neigh, u);
        }
    }

    color[u] = 2;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N >> M;

    g.resize(N + 1);
    color.resize(N + 1);
    cycle.resize(N + 1);
    parentS.resize(N + 1);

    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }

    dfs(1, 0);

    vector<int> result;

    for (int i = 1; i <= N; i++) {
        if (!cycle[i]) {
            result.push_back(i);
        }
    }

    cout << size(result) << '\n';
    for (int e : result) cout << e << ' ';
    cout << '\n';
}