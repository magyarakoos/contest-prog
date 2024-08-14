#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    ll R;
    cin >> R;

    ll res = 0, mxh = R;
    for (ll X = 0; X <= R; X++) {
        while (X * X + mxh * mxh >= (R + 1) * (R + 1)) mxh--;
        for (ll Y = mxh; Y > 0; Y--) {
            if (X * X + Y * Y < R * R) break;
            res++;
        }
    }

    cout << res * 4 << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
