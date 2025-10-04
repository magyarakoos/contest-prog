#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    string s;
    cin >> s;
    vector<int> h(26);
    for (char c : s) { h[c - 'a']++; }
    for (int i = 0; i < 26; i++) {
        if (h[i] == 1) {
            cout << char(i + 'a') << "\n";
            return;
        }
    }
    assert(0);
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
