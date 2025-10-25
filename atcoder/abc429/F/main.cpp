#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e9;

struct Vertex {
    int d[3][3];
};

int n, q;
vector<array<bool, 3>> g;
vector<Vertex> t;

Vertex merge(const Vertex& l, const Vertex& r, int m) {
    Vertex v{.d = {{INF, INF, INF},
                   {INF, INF, INF},
                   {INF, INF, INF}}};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) {
                if (g[m][k] || g[m + 1][k]) continue;
                v.d[i][j] = min(v.d[i][j],
                                l.d[i][k] + 1 + r.d[k][j]);
            }
    return v;
}

Vertex gen(int col) {
    Vertex v{.d = {{INF, INF, INF},
                   {INF, INF, INF},
                   {INF, INF, INF}}};
    for (int i = 0; i < 3; i++) {
        if (g[col][i]) continue;
        for (int j = 0; j < 3; j++) {
            bool ok = 1;
            for (int r = min(i, j); r <= max(i, j); r++) {
                if (g[col][r]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) v.d[i][j] = abs(i - j);
        }
    }
    return v;
}

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = gen(l);
        return;
    }
    int m = (l + r) / 2;
    build(v * 2, l, m);
    build(v * 2 + 1, m + 1, r);
    t[v] = merge(t[v * 2], t[v * 2 + 1], m);
}

void update(int v, int l, int r, int i) {
    if (l == r) {
        t[v] = gen(l);
        return;
    }
    int m = (l + r) / 2;
    if (i <= m) {
        update(v * 2, l, m, i);
    } else {
        update(v * 2 + 1, m + 1, r, i);
    }
    t[v] = merge(t[v * 2], t[v * 2 + 1], m);
}

int32_t main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    vector<string> s(3);
    for (int i = 0; i < 3; i++) cin >> s[i];

    g.resize(n + 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            g[j][i] = s[i][j - 1] == '#';
        }
    }

    t.resize(4 * (n + 2));
    build(1, 1, n);

    cin >> q;
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--;
        g[c][r] = !g[c][r];
        update(1, 1, n, c);
        int ans = t[1].d[0][2];
        cout << (ans >= INF ? -1 : ans) << "\n";
    }
}
