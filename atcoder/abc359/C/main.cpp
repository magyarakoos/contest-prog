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
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    ll Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;
    Sx -= (Sy - Sx) & 1;
    Tx -= (Ty - Tx) & 1;
    Tx = abs(Tx - Sx);
    Ty = abs(Ty - Sy);
    cout << Ty + max(0LL, Tx - Ty) / 2 << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
