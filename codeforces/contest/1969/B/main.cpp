#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 1
void solve() {
    string s;
    cin >> s;
    int l = 0, n = sz(s) - 1;
    while (l < sz(s) && s[l] == '0') l++;
    while (n >= 0 && s[n] == '1') n--;
    if (l >= n) {
        cout << "0\n";
        return;
    }
    ll res = 0;
    int r = l + 1;
    while (r <= n) {
        if (s[r] == '0') {
            res += r - l + 1;
            l++;
        }
        r++;
    }
    cout << res << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
