#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), h(n);
    for (int& x : a) {
        cin >> x;
        x--;
        h[x]++;
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] >= 2) {
            result += (h[i] * (h[i] - 1) / 2 * (n - h[i]));
        }
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
