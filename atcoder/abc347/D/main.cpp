#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    ll a, b, c, C;
    cin >> a >> b >> C;
    c = __popcount(C);
    for (int ca = 0; ca <= c; ca++) {
        int cb = c - ca;

        if (a - ca >= 0 )
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
