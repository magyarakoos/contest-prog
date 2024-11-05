#include <bits/stdc++.h>
using namespace std;

const int MAXK = 20;

vector<vector<int>> sz, p;
vector<int> tin, tout;
int t;

void dfs(int cs) {
    tin[cs] = t++;
    for (int i = 1; i <= MAXK; i++) {
        p[cs][i] = p[p[cs][i - 1]][i - 1];
    }
    for (int x : sz[cs]) { dfs(x); }
    tout[cs] = t++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    sz.resize(n + 1);
    p.resize(n + 1, vector<int>(MAXK + 1, 1));
    tin.resize(n + 1);
    tout.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        cin >> p[i][0];
        sz[p[i][0]].push_back(i);
    }

    dfs(1);

    auto is_parent = [&](int u, int v) {
        return (tin[u] <= tin[v] && tout[v] <= tout[u]);
    };

    while (q--) {
        int a, b;
        cin >> a >> b;

        if (is_parent(a, b)) {
            cout << a << "\n";
            continue;
        }
        if (is_parent(b, a)) {
            cout << b << "\n";
            continue;
        }

        for (int i = MAXK; i >= 0; i--) {
            if (!is_parent(p[a][i], b)) { a = p[a][i]; }
        }

        cout << p[a][0] << "\n";
    }
}

