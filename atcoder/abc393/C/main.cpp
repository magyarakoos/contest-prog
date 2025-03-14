#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    set<array<int, 2>> edgeS;
    int N, M, result = 0;
    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        if (u == v)
            result++;
        else {
            if (u > v) swap(u, v);
            if (edgeS.count({u, v})) {
                result++;
            } else {
                edgeS.insert({u, v});
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
