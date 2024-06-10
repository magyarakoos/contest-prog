#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (int i = 0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> v(N);
    for (int& x : v) cin >> x;
    FenwickTree bit {v};

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int K, U;
            cin >> K >> U;
            bit.add(K - 1, U - v[K - 1]);
            v[K - 1] = U;
        } else {
            int L, R;
            cin >> L >> R;
            cout << bit.sum(L - 1, R - 1) << "\n";
        }
    }
}
