#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

int isqrt(int n) {
    int x = sqrt(n);
    return x - (x * x > n);
}

#define cases 0
void solve() {
    int n;
    cin >> n;
    cout << isqrt(n / 2) + isqrt(n / 4) << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
