#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
#else
#define DB(...)
#endif
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
}

#define cases 0
void solve() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    cout << (dist(xa, ya, xb, yb) + dist(xa, ya, xc, yc) ==
                         dist(xb, yb, xc, yc) ||
                     dist(xa, ya, xb, yb) ==
                         dist(xa, ya, xc, yc) + dist(xb, yb, xc, yc) ||
                     dist(xa, ya, xb, yb) + dist(xb, yb, xc, yc) ==
                         dist(xa, ya, xc, yc)
                 ? "Yes"
                 : "No");
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
