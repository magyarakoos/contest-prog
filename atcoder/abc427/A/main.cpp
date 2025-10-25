#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size() / 2; i++) cout << s[i];
    for (int i = s.size() / 2 + 1; i < s.size(); i++)
        cout << s[i];
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
