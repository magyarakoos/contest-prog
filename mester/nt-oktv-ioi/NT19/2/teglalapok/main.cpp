#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6;

int t[4 * MAXN + 2];

void update(int curr, int tl, int tr, int l, int r, int val) {
    if (l > r || tl > tr) {
        return;
    }
    if (l == tl && r == tr) {
        t[curr] = max(t[curr], val);
    } else {
        int tmid = (tl + tr) / 2;
        update(curr * 2, tl, tmid, l, min(tmid, r), val);
        update(curr * 2 + 1, tmid + 1, tr, max(l, tmid + 1), r, val);
    }
}

int query(int curr, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[curr];
    }
    int tmid = (tl + tr) / 2;
    if (pos <= tmid) {
        return max(t[curr], query(curr * 2, tl, tmid, pos));
    } else {
        return max(t[curr], query(curr * 2 + 1, tmid + 1, tr, pos));
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int H, N, K;
    cin >> H >> N >> K;
    while (N--) {
        int P, D;
        cin >> P >> D;
        update(1, 0, H, P + 1, P + K, D);
    }
    int mn = INT_MAX;
    for (int i = 1; i <= H; i++) {
        mn = min(mn, query(1, 0, H, i));
    }
    cout << mn << "\n";
}
