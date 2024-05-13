#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

struct Vertex {
    int mx, smx;
    Vertex() : mx(-1), smx(-1) {}
    Vertex(int a) : mx(a), smx(-1) {}
    Vertex(int a, int b) : mx(a), smx(b) {}
    Vertex operator +(Vertex v) {
        array<int, 4> a {mx, smx, v.mx, v.smx};
        sort(a.rbegin(), a.rend());
        return {a[0], a[1]};
    }
    int val() const { return mx + smx; }
};

Vertex t[4 * MAXN + 1];

void build(const vector<int>& v, int curr, int tl, int tr) {
    if (tl == tr) {
        t[curr] = {v[tl]};
    } else {
        int tm = (tl + tr) / 2;
        build(v, curr * 2, tl, tm);
        build(v, curr * 2 + 1, tm + 1, tr);
        t[curr] = t[curr * 2] + t[curr * 2 + 1];
    }
}

void update(int curr, int tl, int tr, int pos, int x) {
    if (tl == tr) {
        t[curr] = {x};
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

Vertex query(int curr, int tl, int tr, int l, int r) {
    if (l > r || tl > tr) {
        return {};
    }
    if (tl == l && tr == r) {
        return t[curr];
    }
    int tm = (tl + tr) / 2;
    return
        query(curr * 2, tl, tm, l, min(tm, r)) + 
        query(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    build(v, 1, 0, N - 1);

    int Q;
    cin >> Q;
    while (Q--) {
        char type;
        cin >> type;
        if (type == 'U') {
            int i, x;
            cin >> i >> x;
            update(1, 0, N - 1, i - 1, x);
        } else {
            int x, y;
            cin >> x >> y;
            cout << query(1, 0, N - 1, x - 1, y - 1).val() << "\n";
        }
    }
}
