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
};

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
}
