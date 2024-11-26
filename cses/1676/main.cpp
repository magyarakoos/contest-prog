#include <bits/stdc++.h>
using namespace std;

struct DSU {
    multiset<int> ms;
    std::vector<int> par, rank;
    DSU() = delete;
    DSU(int n) : par(n), rank(n, 1) {
        std::iota(par.begin(), par.end(), 0);
        for (int i = 1; i < n; i++) {
            ms.insert(1);
        }
    }
    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]);
        }
        return par[x];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (rank[y] < rank[x]) std::swap(x, y);
        ms.erase(ms.find(rank[y]));
        ms.erase(ms.find(rank[x]));
        rank[x] += rank[y];
        ms.insert(rank[x]);
        par[y] = x;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    DSU dsu(N + 1);
    while (M--) {
        int U, V;
        cin >> U >> V;
        if (!dsu.same(U, V)) dsu.unite(U, V);
        cout << dsu.ms.size() << " " << *dsu.ms.rbegin() << "\n";
    }
}

