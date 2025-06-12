#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n;
    cin >> n;
    cout << 2 * n - 1 << "\n";
    cout << "1 1 " << n << "\n";
    for (int i = 2; i <= n; i++) {
        cout << i << " 1 " << n - i + 1 << "\n";
        cout << i << " " << n - i + 2 << " " << n << "\n";
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
