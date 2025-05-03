#include <bits/stdc++.h>
using namespace std;
#define int int64_t

#define cases 0
void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++) {
        if (s.find(i + 'a') == s.npos) {
            cout << char(i + 'a') << "\n";
            return;
        }
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
