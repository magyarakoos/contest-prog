#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, A, X, Y;
map<int, double> m;

double dp(int u) {
    if (u == 0) return 0;
    if (m.count(u)) {
        return m[u];
    }

    double a = X + dp(u / A);
    double b = 6 * Y;

    for (int i = 2; i <= 6; i++) b += dp(u / i);
    b /= 5;
    
    m[u] = min(a, b);
    return min(a, b);
}

#define cases 0
void solve() {
    cin >> N >> A >> X >> Y;
    cout << dp(N);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}