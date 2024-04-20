#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll N, A, X, Y;
map<ll, ld> m;

// b = Y + 1/6 * (b + dp(x / 2) + ... + dp(x / 6))
// 6b = 6Y + b + dp(x / 2) + ... dp(x / 6)
// 5b = 6Y + dp(x / 2) + ... dp(x / 6)
// b = (6Y + dp(x / 2) + ... dp(x / 6)) / 5
double dp(ll x) {
    if (x == 0) return 0;
    if (m.count(x)) {
        return m[x];
    }

    ld a = X + dp(x / A), b = Y * 6.0;

    for (int B = 2; B <= 6; B++) b += dp(x / B);
    b /= 5.0;

    m[x] = min(a, b);
    return min(a, b);
}

#define cases 0
void solve() {
    cin >> N >> A >> X >> Y;
    cout << dp(N) << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
    cout << sizeof(ld) << " " << sizeof(double) << "\n";
}