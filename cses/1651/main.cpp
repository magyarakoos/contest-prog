#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5;

ll t[4 * MAXN + 1];

void build(const vector<int>& v, int curr, int tl, int tr) {
    if (tl == tr) {
        t[curr] = v[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v, curr * 2, tl, tm);
        build(v, curr * 2 + 1, tm + 1, tr);
        t[curr] = 0;
    }
}

void update(int curr, int tl, int tr, int l, int r, int x) {
    if (l > r || tl > tr) {
        return;
    }
    if (l == tl && r == tr) {
        t[curr] += x;
    } else {
        int tm = (tl + tr) / 2;
        update(curr * 2, tl, tm, l, min(tm, r), x);
        update(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r, x);
    }
}

ll query(int curr, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[curr];
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        return t[curr] + query(curr * 2, tl, tm, pos);
    } else {
        return t[curr] + query(curr * 2 + 1, tm + 1, tr, pos);
    }
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> v(N);
    for (int& x : v) cin >> x;
    
    build(v, 1, 0, N - 1);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int A, B, U;
            cin >> A >> B >> U;
            update(1, 0, N - 1, A - 1, B - 1, U);
        } else {
            int K;
            cin >> K;
            cout << query(1, 0, N - 1, K - 1) << "\n";
        }
    }
}
