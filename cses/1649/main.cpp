#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MAXN = 2e5, INF = 1e18;

ll t[4 * MAXN + 1];

void build(const vector<int>& v, int curr, int tl, int tr) {
    if (tl == tr) {
        t[curr] = v[tl];
    } else {
        int tmid = (tl + tr) / 2;
        build(v, curr * 2, tl, tmid);
        build(v, curr * 2 + 1, tmid + 1, tr);
        t[curr] = min(t[curr * 2], t[curr * 2 + 1]);
    }
}

ll query(int curr, int tl, int tr, int l, int r) {
    if (l > r) {
        return INF;
    }
    if (l == tl && r == tr) {
        return t[curr];
    }
    int tmid = (tl + tr) / 2;
    return min(
        query(curr * 2, tl, tmid, l, min(r, tmid)),
        query(curr * 2, tmid + 1, tr, max(l, tmid + 1), r)
    );
}

void update(int curr, int tl, int tr, int pos, ll x) {
    if (tl == tr) {
        t[curr] = x;
    } else {
        int tmid = (tl + tr) / 2;
        if (pos <= tmid) {
            update(curr * 2, tl, tmid, pos, x);
        } else {
            update(curr * 2 + 1, tmid + 1, tr, pos, x);
        }
        t[curr] = min(t[curr * 2], t[curr * 2 + 1]);
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    while (Q--) {
        int T;
        cin >> T;
        if (T == 1) {
            int K, U;
            cin >> K >> U;
            update(1, 0, N - 1, K - 1, U);
        } else {
            int L, R;
            cin >> L >> R;
            cout << query(1, 0, N - 1, L - 1, R - 1) << "\n";
        }
    }
}