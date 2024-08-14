#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    string s;
    cin >> s;
    int mx = 0;
    string result;
    for (int i = 0; i <= sz(s); i++) {
        for (int j = 0; j < 26; j++) {
            string t = s;
            t = t.substr(0, i) + char('a' + j) + t.substr(i);
            int curr = 2;
            for (int k = 1; k < sz(t); k++) {
                curr += 1 + (t[k - 1] != t[k]);
            }
            if (mx < curr) {
                mx = curr;
                result = t;
            }
        }
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
