#include <bits/stdc++.h>
using namespace std;
#define int int64_t

#define cases 0
void solve() {
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    for (string& r : s) cin >> r;
    for (string& r : t) cin >> r;
    int result = INT_MAX;
    for (int k = 0; k < 4; k++) {
        int curr = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                curr += s[i][j] != t[i][j];
            }
        }
        result = min(result, curr + k);
        auto res = s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[j][n - i - 1] = s[i][j];
            }
        }
        s = res;
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
