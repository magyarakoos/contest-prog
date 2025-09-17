#include <bits/stdc++.h>
using namespace std;
#define int int64_t

struct DSU {
    vector<int> par, rank;
    DSU(int n) : par(n), rank(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (x < y) swap(x, y);
        par[y] = x;
        rank[x] += rank[y];
    }
};

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    auto b = a;
    sort(b.begin(), b.end());

    map<int, int> pos;
    for (int i = 0; i < n; i++) pos[b[i]] = i;

    DSU dsu(n);
    for (int i = 0; i < n; i++) { dsu.unite(i, pos[a[i]]); }

    vector<vector<int>> groupS(n);

    for (int i = 0; i < n; i++) {
        groupS[dsu.find(i)].push_back(a[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) { k += !groupS[i].empty(); }
    cout << k << "\n";
    for (int i = 0; i < n; i++) {
        if (!groupS[i].empty()) {
            cout << groupS[i].size();
            for (int x : groupS[i]) cout << " " << x + 1;
            cout << "\n";
        }
    }
}
