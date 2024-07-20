#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

const ll MAXN = 2e5, MOD = 1e9 + 7, INF = 1e18;

int N, M;
vector<array<int, 3>> edgeS;

struct DSU {
    vector<int> par, rank;
    DSU(int n) : par(n), rank(n, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]);
        }
        return par[x];
    }
    bool same(int x, int y) { return find(x) == find(y); }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (rank[y] < rank[x]) swap(x, y);
        rank[x] += rank[y];
        par[y] = x;
    }
};

void solve() {
    DSU dsu{N + 1};
    int X;
    cin >> X;
    auto cedgeS = edgeS;
    for (auto& [W, U, V] : cedgeS) {
        W = abs(W - X);
    }
    sort(cedgeS.begin(), cedgeS.end());
    ll result = 0;
    for (auto [W, U, V] : cedgeS) {
        if (!dsu.same(U, V)) {
            dsu.unite(U, V);
            result += W;
        }
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N >> M;
    edgeS.resize(M);
    for (auto& [W, U, V] : edgeS) cin >> U >> V >> W;
    int Q;
    cin >> Q;
    while (Q--) solve();
}
