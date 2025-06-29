#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin() + 1, a.end() - 1);
    int cnt = 1;
    int l = 0, r = 0;
    while (1) {
        if (a[r] * 2 >= a[n - 1]) {
            cnt++;
            break;
        }
        while (r + 1 < n && a[l] * 2 >= a[r + 1]) { r++; }
        if (l == r) {
            cout << "-1\n";
            return;
        }
        cnt++;
        if (r == n - 1) break;

        l = r;
    }
    cout << cnt << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
