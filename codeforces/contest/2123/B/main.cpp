#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n, j, k;
    cin >> n >> j >> k;
    j--;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    if (k >= 2) {
        cout << "YES\n";
        return;
    }
    cout << (a[j] == *max_element(a.begin(), a.end())
                 ? "YES\n"
                 : "NO\n");
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
