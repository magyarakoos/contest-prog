#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0;
    for (char c : s) cnt += c == '1';
    if (cnt <= k || 2 * k >= n + 1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
