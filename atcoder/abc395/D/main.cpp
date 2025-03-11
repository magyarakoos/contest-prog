#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> p(N), q, r;
    iota(p.begin(), p.end(), 0);
    q = r = p;
    while (Q--) {
        int type, a, b;
        cin >> type;
        if (type == 1) {
            cin >> a >> b;
            p[a - 1] = q[b - 1];
        } else if (type == 2) {
            cin >> a >> b;
            swap(q[a - 1], q[b - 1]);
            swap(r[q[a - 1]], r[q[b - 1]]);
        } else {
            cin >> a;
            cout << r[p[a - 1]] + 1 << "\n";
        }
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
