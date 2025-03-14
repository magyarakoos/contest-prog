#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    string s, t;
    cin >> s >> t;
    bool a = s == "fine", b = t == "fine";
    if (!a && !b) {
        cout << 1 << "\n";
    } else if (a && b) {
        cout << 4 << "\n";
    } else if (a && !b) {
        cout << 3 << "\n";
    } else {
        cout << 2 << "\n";
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
