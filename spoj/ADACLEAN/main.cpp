#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 999999999999999989, BMOD = 29;

void solve() {
    int n, k, pw = 1;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < k; i++) (pw *= BMOD) %= MOD;
    set<int> hS;
    int h = 0;
    for (int i = 0; i < n; i++) {
        (h *= BMOD) %= MOD;
        if (i - k >= 0) {
            h += MOD - pw * (s[i - k] - 'a' + 1);
            h %= MOD;
        }
        (h += s[i] - 'a' + 1) %= MOD;
        if (i >= k - 1) hS.insert(h);
    }
    cout << hS.size() << "\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
}
