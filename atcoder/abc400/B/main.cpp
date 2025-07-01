#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int sum = 0, cur = 1;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= m; i++) {
        sum += cur;
        if (sum > INF) {
            cout << "inf\n";
            return;
        }
        cur *= n;
    }
    cout << sum << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
