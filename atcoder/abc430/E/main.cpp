#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) { z[i] = min(r - i, z[i - l]); }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

#define cases 1
void solve() {
    string a, b;
    cin >> a >> b;
    string s = b + '#' + a + a;
    auto z = z_function(s);
    for (int i = b.size() + 1; i < s.size(); i++) {
        if (z[i] >= a.size()) {
            cout << i - b.size() - 1 << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
