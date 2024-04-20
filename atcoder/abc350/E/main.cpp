#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll N, A, X, Y;
map<ll, ld> m;

double dp(ll u) {
    if (u == 0) return 0;
    if (m.count(u)) {
        return m[u];
    }

    ld a = X + dp(u / A);
    ld b = 6.0 * Y;

    for (ll i = 2; i <= 6; i++) b += dp(u / i);
    b /= 5.0;
    
    m[u] = min(a, b);
    return min(a, b);
}

#define cases 0
void solve() {
    cin >> N >> A >> X >> Y;
    cout << setprecision(10) << dp(N);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}