#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int left = k - 1;
    int right = n - k;
    if (right < left) swap(left, right);

    int mx_exp = (m + 1) / 3;
    if (mx_exp < left) {
        cout << 2 * mx_exp + ((m + 1) - 3 * mx_exp >= 2) + 1
             << "\n";
    } else {
        cout << left + min((m + 1 - left) / 2, right) + 1
             << "\n";
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
