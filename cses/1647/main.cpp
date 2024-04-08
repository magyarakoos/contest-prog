#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;
constexpr ll MAXN = 2e5;

int N, a[MAXN + 1];

void build(const vector<int>& v, int curr, int tl, int tr) {
    if (tl == tr) {
        a[curr] = v[tl];
        return;
    }

    int tmid = (tl + tr) / 2;
    build(v, curr * 2, tl, tmid);
    build(v, curr * 2 + 1, tmid + 1, tr);
    a[curr] = min(a[curr * 2], a[curr * 2 + 1]);
}

int query(int curr, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return a[curr];
    }

    int tmid = (tl + tr) / 2;
    return min(
        query(curr * 2, tl, tmid, l, min(r, tmid)),
        query(curr * 2 + 1, tmid + 1, tr, max(l, tmid + 1), r)
    );
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int Q;
    cin >> N >> Q;

    vector<int> v(N);
    for (int& x : v) cin >> x;

    build(v, 1, 0, N - 1);

    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << query(1, 0, N - 1, L, R) << "\n";
    }
}