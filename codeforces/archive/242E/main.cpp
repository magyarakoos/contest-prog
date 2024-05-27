#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> t, lazy;

void build(const vector<int>& v, int curr, int tl, int tr, int bit) {
    if (tl == tr) {
        t[bit][curr] = (v[tl] >> bit) & 1;
    } else {
        int tm = (tl + tr) / 2;
        build(v, curr * 2, tl, tm , bit);
        build(v, curr * 2 + 1, tm + 1, tr, bit);
        t[bit][curr] = t[bit][curr * 2] + t[bit][curr * 2 + 1];
    }
}

void push(int curr, int bit, int tl, int tr) {
    if (lazy[bit][curr]) {
        lazy[bit][curr] = 0;
        lazy[bit][curr * 2] ^= 1;
        lazy[bit][curr * 2 + 1] ^= 1;

        int tm = (tl + tr) / 2;
        t[bit][curr * 2] = (tm - tl + 1) - t[bit][curr * 2];
        t[bit][curr * 2 + 1] = (tr - (tm + 1) + 1) - t[bit][curr * 2 + 1];
    }
}

void update(int curr, int tl, int tr, int l, int r, int bit, int x) {
    if (tl > tr || l > r) return;
    if (l == tl && r == tr) {
        if ((x >> bit) & 1) {
            t[bit][curr] = (tr - tl + 1) - t[bit][curr];
        }
        lazy[bit][curr] ^= (x >> bit) & 1;
    } else {
        push(curr, bit, tl, tr);
        int tm = (tl + tr) / 2;
        update(curr * 2, tl, tm, l, min(tm, r), bit, x);
        update(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r, bit, x);
        t[bit][curr] = t[bit][curr * 2] + t[bit][curr * 2 + 1];
    }
}

int query(int curr, int tl, int tr, int l, int r, int bit) {
    if (tl > tr || l > r) return 0;
    if (l == tl && r == tr) {
        return t[bit][curr];
    }
    push(curr, bit, tl, tr);
    int tm = (tl + tr) / 2;
    return
        query(curr * 2, tl, tm, l, min(tm, r), bit) +
        query(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r, bit);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> v(N);
    for (int& x : v) cin >> x;

    t.assign(20, vector<int>(4 * N + 1)); // ceil(log2(1e6)) = 20
    lazy.assign(20, vector<int>(4 * N + 1));

    for (int i = 0; i < 20; i++) {
        build(v, 1, 0, N - 1, i);
    }

    int M;
    cin >> M;

    while (M--) {
        int type;
        cin >> type;
        if (type == 1) {
            int L, R;
            cin >> L >> R;
            ll result = 0;
            for (int i = 0; i < 20; i++) {
                result += query(1, 0, N - 1, L - 1, R - 1, i) * (1LL << i);
            }
            cout << result << "\n";
        } else {
            int L, R, X;
            cin >> L >> R >> X;
            for (int i = 0; i < 20; i++) {
                update(1, 0, N - 1, L - 1, R - 1, i, X);
            }
        }
    }
}
