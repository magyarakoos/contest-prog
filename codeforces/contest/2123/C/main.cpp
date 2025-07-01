#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), ps(n), ss(n);
    for (int& x : a) cin >> x;
    ps[0] = a[0];
    ss[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
        ps[i] = min(ps[i - 1], a[i]);
    for (int i = n - 2; i >= 0; i--)
        ss[i] = max(ss[i + 1], a[i]);
    cout << (min(a[0], ss[1]) == a[0] || ss[0] == a[0]);
    for (int i = 1; i < n - 1; i++) {
        cout << (max({ps[i - 1], ss[i + 1], a[i]}) ==
                     a[i] ||
                 min({ps[i - 1], ss[i + 1], a[i]}) ==
                     a[i] ||
                 max(ps[i], ss[i + 1]) == a[i] ||
                 min(ps[i - 1], ss[i]) == a[i]);
    }
    cout << (max(ps[n - 2], a[n - 1]) == a[n - 1] ||
             ps[n - 1] == a[n - 1])
         << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
