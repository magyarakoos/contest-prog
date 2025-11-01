#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    set<vector<string>> s;
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (string& line : a) cin >> line;
    for (int i = 0; i + m <= n; i++) {
        for (int j = 0; j + m <= n; j++) {
            vector<string> b;
            for (int k = 0; k < m; k++) {
                b.push_back(a[i + k].substr(j, m));
            }
            s.insert(b);
        }
    }
    cout << s.size() << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
