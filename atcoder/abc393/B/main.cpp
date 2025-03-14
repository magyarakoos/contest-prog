#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    string s;
    cin >> s;
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            for (int k = j + 1; k < s.size(); k++) {
                if (j - i == k - j && s[i] == 'A' &&
                    s[j] == 'B' && s[k] == 'C') {
                    result++;
                }
            }
        }
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
