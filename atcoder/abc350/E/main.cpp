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

    // b = Y + 1/6 * (b + dp(u / 2) + ... + dp(u / 6))
    // 6b = 6Y + b + dp(u / 2) + ... dp(u / 6)
    // 5b = 6Y + dp(u / 2) + ... dp(u / 6)
    // b = (6Y + dp(u / 2) + ... dp(u / 6)) / 5
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