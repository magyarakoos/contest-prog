#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    multiset<int> ms;
    std::vector<int> par, rank;
    DSU() = delete;
    DSU(int n) : par(n), rank(n, 1) {
        std::iota(par.begin(), par.end(), 0);
        for (int i = 0; i < n; i++) {
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
        ms.erase(ms.find(rank[x]));
        ms.erase(ms.find(rank[y]));
        rank[x] += rank[y];
        ms.insert(rank[x]);
        par[y] = x;
    }
};

void solve() {
    ll N, Q;
    cin >> N;

    vector<array<int, 2>> edgeS(N - 1);
    for (auto& [u, v] : edgeS) {
        cin >> u >> v;
        u--, v--;
    }

    cin >> Q;
    vector<int> queryS(Q, -1);
    set<int> qS;
    for (int i = 0; i < Q; i++) {
        char c;
        cin >> c;
        if (c == 'R') {
            cin >> queryS[i];
            qS.insert(--queryS[i]);
        }
    }

    DSU dsu(N);
    for (int i = 0; i < N - 1; i++) {
        if (!qS.count(i)) {
            dsu.unite(edgeS[i][0], edgeS[i][1]);
        }
    }
        
    ll curr = 0;
    for (int x : dsu.ms) {
        curr += (N - x) * x;
    }

    deque<ll> result;
    for (int i = Q - 1; i >= 0; i--) {
        if (queryS[i] == -1) {
            result.push_front(curr);
            continue;
        }

        int u = edgeS[queryS[i]][0];
        int v = edgeS[queryS[i]][1];
        ll szu = dsu.rank[dsu.find(u)];
        ll szv = dsu.rank[dsu.find(v)];

        curr -= (N - szu) * szu;
        curr -= (N - szv) * szv;
        curr += (N - (szu + szv)) * (szu + szv);

        dsu.unite(u, v);
    }

    for (ll x : result) cout << x / 2 << "\n";
    cout << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
