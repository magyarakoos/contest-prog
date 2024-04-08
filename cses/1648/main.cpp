#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;
constexpr int MAXN = 2e5;

int N;
ll a[4 * MAXN + 1];

void build(const vector<int>& v, int curr, int tl, int tr) {
    if (tl == tr) {
        a[curr] = v[tl];
        return;
    }

    int tmid = (tl + tr) / 2;
    build(v, curr * 2, tl, tmid);
    build(v, curr * 2 + 1, tmid + 1, tr);
    a[curr] = a[curr * 2] + a[curr * 2 + 1];
}

ll query(int curr, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return a[curr];
    }
    
    int tmid = (tl + tr) / 2;
    return 
        query(curr * 2, tl, tmid, l, min(tmid, r)) +
        query(curr * 2 + 1, tmid + 1, tr, max(tmid + 1, l), r)
    ;
}

void update(int curr, int tl, int tr, int pos, int x) {
    if (tl == tr) {
        a[curr] = x;
    }

    int tmid = (tl + tr) / 2;
    
    if (pos <= tmid) {
        update(curr * 2, tl, tmid, pos, x);
    } else {
        update(curr * 2 + 1, tmid + 1, tr, pos, x);
    }
    a[curr] = a[curr * 2] + a[curr * 2 + 1];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int Q;
    cin >> N >> Q;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    build(v, 1, 0, N - 1);

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int K, U;
            cin >> K >> U;
            update()
        } else {
            int L, R;
            cin >> L >> R;
            cout << query(1, 0, N - 1, L - 1, R - 1) << "\n";
        }
    }
}