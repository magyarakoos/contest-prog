#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            int j = i;
            for (; j < n && s[j] == 'W'; j++);
            if (j < n && s[j] == 'A') {
                s[i] = 'A';
                for (int k = i + 1; k <= j; k++) {
                    s[k] = 'C';
                }
            }
            i = j;
        }
    }
    cout << s << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
