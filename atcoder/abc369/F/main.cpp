#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

vector<array<int, 2>> t;

array<int, 2> combine(array<int, 2> a, array<int, 2> b) {
    return a[0] < b[0] ? b : a;
}

void update(int curr, int tl, int tr, int p, array<int, 2> a) {
    if (tr < tl) return;
    if (tl == tr) {
        t[curr] = a;
        return;
    }
    int tm = (tl + tr) / 2;
    if (p <= tm) {
        update(curr * 2, tl, tm, p, a);
    } else {
        update(curr * 2 + 1, tm + 1, tr, p, a);
    }
    t[curr] = combine(t[curr * 2], t[curr * 2 + 1]);
}

array<int, 2> query(int curr, int tl, int tr, int l, int r) {
    if (tr < tl || r < l) { return {-1, -1}; }
    if (tl == l && tr == r) { return t[curr]; }
    int tm = (tl + tr) / 2;
    return combine(query(curr * 2, tl, tm, l, min(tm, r)),
                   query(curr * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}

#define cases 0
void solve() {
    int H, W, N;
    cin >> H >> W >> N;

    t.resize(4 * N + 4);

    vector<array<int, 2>> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i][0] >> a[i][1];
        b[i] = {a[i][1], a[i][0]};
    }

    sort(all(a));
    sort(all(b));

    map<array<int, 2>, int> m;
    for (int i = 0; i < N; i++) { m[{b[i][1], b[i][0]}] = i; }

    for (int i = 0; i < N; i++) {
        auto [mx, j] = query(1, 0, N - 1, 0, i - 1);
        if (j == -1) {
            cout << "0 0";
        } else {
            cout << a[j][0] << " " << a[j][1];
        }
        cout << " -> " << a[i][0] << " " << a[i][1] << "\n";
        for (int i = 0; i < N; i++) {
            cout << query(1, 0, N - 1, i, i)[0] << " ";
        }
        cout << "\n";
        cout << i << " " << m[a[i]] << "\n\n";
        update(1, 0, N - 1, m[a[i]], {mx + 1, i});
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
