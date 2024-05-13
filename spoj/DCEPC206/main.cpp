#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6;

ll t[4 * MAXN + 1];

void update(int curr, int tl, int tr, int pos) {
    if (tl == tr) {
        t[curr] += pos;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(curr * 2, tl, tm, pos);
        } else {
            update(curr * 2 + 1, tm + 1, tr, pos);
        }
        t[curr] = t[curr * 2] + t[curr * 2 + 1];
    }
}

ll query(int curr, int tl, int tr, int l, int r) {
    if (l > r || tl > tr) return 0;
    if (l == tl && r == tr) {
        return t[curr];
    }
    int tm = (tl + tr) / 2;
    return
        query(curr * 2, tl, tm, l, min(tm, r)) +
        query(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

void solve() {
    memset(t, 0, sizeof(t));
    int N;
    cin >> N;
    ll res = 0;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        res += query(1, 0, MAXN - 1, 1, X - 1);
        update(1, 0, MAXN - 1, X);
    }
    cout << res << "\n";
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
