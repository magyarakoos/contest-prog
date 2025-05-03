#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    map<int, int> m;
    for (int i = 0, a; i < 7; i++) {
        cin >> a;
        m[a]++;
    }
    vector<int> a;
    for (auto [k, v] : m) { a.push_back(v); }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (i != j && a[i] >= 2 && a[j] >= 3) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
