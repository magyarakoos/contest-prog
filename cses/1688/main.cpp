#include <bits/stdc++.h>
using namespace std;

const int MAXK = 20;

vector<vector<int>> g, p;
vector<int> tin, tout;
int t;

void dfs(int u) {
    tin[u] = t++;
    for (int i = 1; i <= MAXK; i++) {
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for (int x : g[u]) { dfs(x); }
    tout[u] = t++;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    g.resize(n + 1);
    p.resize(n + 1, vector<int>(MAXK + 1, 1));
    tin.resize(n + 1);
    tout.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        cin >> p[i][0];
        g[p[i][0]].push_back(i);
    }

    dfs(1);

    auto is_anc = [&](int u, int v) {
        return (tin[u] <= tin[v] && tout[v] <= tout[u]);
    };

    while (q--) {
        int a, b;
        cin >> a >> b;

        if (is_anc(a, b)) {
            cout << a << "\n";
            continue;
        }
        if (is_anc(b, a)) {
            cout << b << "\n";
            continue;
        }

        for (int i = MAXK; i >= 0; i--) {
            if (!is_anc(p[a][i], b)) { a = p[a][i]; }
        }

        cout << p[a][0] << "\n";
    }
}

