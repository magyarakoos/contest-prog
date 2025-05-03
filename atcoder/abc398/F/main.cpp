#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;
#define cases 0

int lps(const string& s) {
    int n = s.size();
    vector<int> result(n, 0);

    for (int i = 1, len = 0; i < n;) {
        if (s[i] == s[len]) {
            result[i++] = ++len;
        } else {
            if (len > 0) {
                len = result[len - 1];
            } else {
                result[i++] = 0;
            }
        }
    }
    return result.back();
}

void solve() {
    string s;
    cin >> s;

    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());

    string t = s.substr(0, s.size() - lps(s_rev + "$" + s));
    reverse(t.begin(), t.end());

    cout << s + t << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
