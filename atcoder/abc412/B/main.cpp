#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    string s, t;
    cin >> s >> t;
    for (int i = 1; i < s.size(); i++) {
        if (isupper(s[i])) {
            if (t.find(s[i - 1]) == t.npos) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
