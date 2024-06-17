#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<array<int, 2>> t;  // {min, gcd}

array<int, 2> combine(array<int, 2> a, array<int, 2> b) {
    return {min(a[0], b[0]), gcd(a[1], b[1])};
}

void build(int curr, const vector<int>& a, int tl, int tr) {
    if (tl == tr) {
        t[curr] = {a[tl], a[tl]};
    } else {
        int tm = (tl + tr) / 2;
        build(curr * 2, a, tl, tm);
        build(curr * 2 + 1, a, tm + 1, tr);
        t[curr] = combine(t[curr * 2], t[curr * 2 + 1]);
    }
}

array<int, 2> query(int curr, int tl, int tr, int l, int r) {
    if (l > r || tl > tr) return {INT_MAX, 0};
    if (l == tl && r == tr) {
        return t[curr];
    }
    int tm = (tl + tr) / 2;
    return combine(query(curr * 2, tl, tm, l, min(tm, r)),
                   query(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> v(N);

    for (int& x : v) cin >> x;

    vector<array<int, 2>> posS(N);
    for (int i = 0; i < N; i++) {
        posS[i] = {v[i], i};
    }

    sort(posS.begin(), posS.end());

    t.resize(4 * N + 1);
    build(1, v, 0, N - 1);

    int Q;
    cin >> Q;

    while (Q--) {
        int L, R;
        cin >> L >> R;
        L--, R--;
        auto res = query(1, 0, N - 1, L, R);
        if (res[0] == res[1]) {
            int a = res[0];
            int sl = lower_bound(posS.begin(), posS.end(),
                                 array<int, 2>{a, INT_MIN}) -
                     posS.begin();
            int sr = upper_bound(posS.begin(), posS.end(),
                                 array<int, 2>{a, INT_MAX}) -
                     posS.begin();

            int il = lower_bound(posS.begin() + sl, posS.begin() + sr,
                                 array<int, 2>{a, L}) -
                     posS.begin();

            int ir = lower_bound(posS.begin() + sl, posS.begin() + sr,
                                 array<int, 2>{a, R + 1}) -
                     posS.begin();

            cout << (R - L + 1) - (ir - il) << "\n";
        } else {
            cout << R - L + 1 << "\n";
        }
    }
}
