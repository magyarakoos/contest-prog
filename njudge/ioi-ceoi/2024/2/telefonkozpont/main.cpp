#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5, INF = 1e9;

int t[4 * MAXN + 1], lazy[4 * MAXN + 1];

void build(const vector<int>& v, int curr, int tl, int tr) {
    if (tl == tr) {
        t[curr] = v[tl];
    } else {
        int tmid = (tl + tr) / 2;
        build(v, )
    }
}

void push(int curr) {
    t[curr * 2] += lazy[curr];
    t[curr * 2 + 1] += lazy[curr];
    lazy[curr * 2] += lazy[curr];
    lazy[curr * 2 + 1] += lazy[curr];
    lazy[curr] = 0;
}

int query(int curr, int tl, int tr, int l, int r) {
    if (tr < tl || r < l) {
        return -INF;
    }
    if (tl == l && tr == r) {
        return t[curr];
    }
    push(curr);
    int tmid = (tl + tr) / 2;
    return max(
        query(curr * 2, tl, tmid, l, min(tmid, r)),
        query(curr * 2 + 1, tmid + 1, tr, max(l, tmid + 1), r)
    );
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int M, N, Q;
    cin >> M >> N >> Q;

    while (N--) {
        int B, E;
        cin >> B >> E;
        update(1, 0, M - 1, B - 1, E - 1);
    }

    while (Q--) {
        int B, E;
        cin >> B >> E;
        cout << query(1, 0, M - 1, B - 1, E - 1) << "\n";
    }
}