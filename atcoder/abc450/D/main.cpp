#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x, x %= k;
    sort(a.begin(), a.end());
    int result = 0;
    for (int i = 1; i < n; i++) {
        result =
            max(result, min(a[i] - a[0], a[0] + k - a[i]));
    }
    for (int i = 0; i < n - 1; i++) {
        cout << min(a[i] - a[n - 1], a[n - 1] + k - a[i]);
        result = max(result, min(a[i] - a[n - 1],
                                 a[n - 1] + k - a[i]));
    }
    cout << result << "\n";

    for (int x : a) cout << x << " ";
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
