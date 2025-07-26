#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    int sum = 0;
    for (int& x : a) cin >> x, sum += x;
    for (int& x : b) cin >> x, sum += x;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int of = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (a[i] + b[j] >= m) {
            of++;
            j++;
        }
    }
    cout << sum - m * of << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
