#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

struct DSU {
    std::vector<int> par, rank;
    vector<vector<int>> vnums;
    DSU() = delete;
    DSU(int n) : par(n), rank(n, 1), vnums(n) {
        std::iota(par.begin(), par.end(), 0);
        for (int i = 0; i < n; i++) { vnums[i].push_back(i); }
    }
    int find(int x) {
        if (x != par[x]) { par[x] = find(par[x]); }
        return par[x];
    }
    bool same(int x, int y) { return find(x) == find(y); }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (rank[y] < rank[x]) std::swap(x, y);
        rank[x] += rank[y];
        par[y] = x;

        vector<int> tmp = vnums[x];
        vnums[x].clear();
        for (int i = 0; i < 10 && i < tmp.size(); i++) {
            vnums[x].push_back(tmp[i]);
        }
        for (int i = 0; i < 10 && i < vnums[y].size(); i++) {
            vnums[x].push_back(vnums[y][i]);
        }

        sort(vnums[x].rbegin(), vnums[x].rend());
    }
};

#define cases 0
void solve() {
    int N, Q;
    cin >> N >> Q;

    DSU dsu{N + 1};

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int U, V;
            cin >> U >> V;
            if (!dsu.same(U, V)) dsu.unite(U, V);
        } else {
            int V, K;
            cin >> V >> K;
            K--;
            V = dsu.find(V);
            if (dsu.vnums[V].size() <= K) {
                cout << "-1\n";
            } else {
                cout << dsu.vnums[V][K] << "\n";
            }
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
