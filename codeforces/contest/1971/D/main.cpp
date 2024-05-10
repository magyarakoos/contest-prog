#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;
string s;

int part(int i, int j) {
    if (i > j) return 0;
    int flips = 1;
    char curr = s[i];
    for (i++; i <= j; i++) {
        if (s[i] != curr) {
            curr = s[i];
            flips++;
        }
    }
    return flips;
}

#define cases 1
void solve() {
    cin >> s;
    for (int i = 1; i < sz(s); i++) {
        if (s[i - 1] == '0' && s[i] == '1') {
            int ci = i;
            while (ci > 0 && s[ci - 1] == '0') {
                ci--;
            }
            int res = part(0, ci - 1) + 1;
            while (i + 1 < sz(s) && s[i + 1] == '1') {
                i++;
            }
            cout << res + part(i + 1, sz(s) - 1) << "\n";
            return;
        }
    }
    cout << part(0, sz(s) - 1) << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}