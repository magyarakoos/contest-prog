#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n), b(m);
    for (int& x : h) cin >> x;
    for (int& x : b) cin >> x;
    sort(h.begin(), h.end());
    sort(b.begin(), b.end());
    int j = 0;
    for (int i = 0; i < k; i++) {
        while (j < m && b[j] < h[i]) j++;
        if (j == m) {
            cout << "No\n";
            return;
        }
        j++;
    }
    cout << "Yes\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
