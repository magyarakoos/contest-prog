#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> t;

void update(int curr, int tl, int tr, int pos, int x) {
    if (tl > tr) return;
    if (tl == tr) {
        t[curr] = x;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(curr * 2, tl, tm, pos, x);
        } else {
            update(curr * 2 + 1, tm + 1, tr, pos, x);
        }
        t[curr] = t[curr * 2] + t[curr * 2 + 1];
    }
}

int query(int curr, int tl, int tr, int l, int r) {
    if (tl > tr || l > r) return 0;
    if (l == tl && r == tr) {
        return t[curr];
    }
    int tm = (tl + tr) / 2;
    return 
        query(curr * 2, tl, tm, l, min(tm, r)) + 
        query(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> v(N);
    for (int& x : v) cin >> x;

    vector<vector<array<int, 2>>> qS(N);
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        qS[L - 1].push_back({R - 1, i});
    }

    t.resize(4 * N + 1);

    map<int, int> posS;
    vector<int> result(Q);

    for (int l = N - 1; ~l; l--) {
        if (posS.count(v[l])) {
            update(1, 0, N - 1, posS[v[l]], 0);
        }
        posS[v[l]] = l;
        update(1, 0, N - 1, l, 1);
        for (auto [r, i] : qS[l]) {
            result[i] = query(1, 0, N - 1, l, r);
        }
    }

    for (int x : result) cout << x << "\n";
}
