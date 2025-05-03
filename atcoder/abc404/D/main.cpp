#include <bits/stdc++.h>
using namespace std;
#define int int64_t

vector<int> base3(int n) {
    vector<int> digits;
    while (n) {
        digits.push_back(n % 3);
        n /= 3;
    }
    return digits;
}

#define cases 0
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n), k(m);
    vector<vector<int>> g(n);
    for (int& x : c) cin >> x;
    for (int i = 0; i < m; i++) {
        cin >> k[i];
        for (int j = 0, x; j < k[i]; j++) {
            cin >> x;
            g[x - 1].push_back(i);
        }
    }
    int pw = 1;
    for (int i = 1; i <= n; i++) pw *= 3;
    int result = LLONG_MAX;
    for (int mask = 0; mask < pw; mask++) {
        auto d = base3(mask);
        int curr = 0;
        vector<int> vis(m);
        for (int i = 0; i < d.size(); i++) {
            for (int x : g[i]) vis[x] += d[i];
            curr += c[i] * d[i];
        }
        for (int x : vis) {
            if (x < 2) {
                curr = LLONG_MAX;
                break;
            }
        }
        result = min(result, curr);
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
