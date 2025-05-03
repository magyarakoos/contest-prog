#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    map<int, vector<int>> m;
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        m[a[i]].push_back(i);
    }
    int mx = 0, result = -1;
    for (auto [k, v] : m) {
        if (v.size() == 1) {
            if (mx < a[v[0]]) {
                mx = a[v[0]];
                result = v[0] + 1;
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
