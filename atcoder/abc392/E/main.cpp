#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

struct DSU {
    vector<int> par, rnk;
    set<int> ps;
    DSU(int n) : par(n), rnk(n, 1) {
        iota(par.begin(), par.end(), 0);
        for (int i = 1; i < n; i++) ps.insert(i);
    }
    int find(int u) {
        if (u == par[u]) { return u; }
        return par[u] = find(par[u]);
    }
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return 0;
        if (rnk[u] < rnk[v]) swap(u, v);
        ps.erase(par[v]);
        par[v] = u;
        rnk[u] += rnk[v];
        return 1;
    }
};

vector<vector<int>> g;

#define cases 0
void solve() {
    int N, M;
    cin >> N >> M;
    g.resize(N + 1);
    vector<array<int, 2>> edgeS(M);
    for (auto& [U, V] : edgeS) cin >> U >> V;
    DSU dsu(N + 1);
    vector<int> extraS;
    for (int i = 0; i < M; i++) {
        if (!dsu.unite(edgeS[i][0], edgeS[i][1])) {
            extraS.push_back(i);
        }
    }
    int sz = dsu.ps.size() - 1;
    vector<array<int, 3>> result;
    for (int e : extraS) {
        if (dsu.ps.size() == 1) break;
        dsu.ps.erase(dsu.find(edgeS[e][0]));
        int v = *dsu.ps.begin();
        dsu.ps.insert(dsu.find(edgeS[e][0]));
        dsu.unite(edgeS[e][0], v);
        result.push_back({e, edgeS[e][0], v});
    }
    assert(result.size() == sz);
    cout << result.size() << "\n";
    for (auto [e, ea, eb] : result)
        cout << e + 1 << " " << ea << " " << eb << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
