#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5, INF = 1e9;

int t[4 * MAXN + 1], lazy[4 * MAXN + 1];

void push(int curr) {
    t[curr * 2] += lazy[curr];
    t[curr * 2 + 1] += lazy[curr];
    lazy[curr * 2] += lazy[curr];
    lazy[curr * 2 + 1] += lazy[curr];
    lazy[curr] = 0;
}

void update(int curr, int tl, int tr, int l, int r) {
    if (tr < tl || r < l) {
        return;
    }
    if (tr == tl) {
        t[curr]++;
        lazy[curr]++;
    } else {
        push(curr);
        int tmid = (tl + tr) / 2;
        update(curr * 2, tl, tmid, l, min(tmid, r));
        update(curr * 2 + 1, tmid + 1, tr, max(tmid + 1, l), r);
        t[curr] = max(t[curr * 2], t[curr * 2 + 1]);
    }
}

int query(int curr, int tl, int tr, int l, int r) {
    if (tr < tl || r < l) {
        return -INF;
    }
    
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
    }
}