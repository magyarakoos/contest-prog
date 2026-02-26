#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    string s;
    cin >> s;

    sort(s.begin() + 1, s.end());
    int x = 0, i = 0;
    for (char c : s) {
        int y = c - '0';
        if (i == 0 || x + y < 10)
            x += y, i++;
        else
            break;
    }
    int resa = s.size() - i;

    s[0] = '1';
    x = 0;
    i = 0;
    for (char c : s) {
        int y = c - '0';
        if (i == 0 || x + y < 10)
            x += y, i++;
        else
            break;
    }
    cout << min<int>(resa, s.size() - i + 1) << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
