#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x : a) cin >> x, sum += x;
    for (int x : a) {
        if (sum - x == m) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
