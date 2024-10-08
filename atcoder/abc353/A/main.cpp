#include <bits/stdc++.h>
#ifdef LOCAL
#include "magyarakoos-debug.h"
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, x;
    cin >> N >> x;
    for (int i = 1; i < N; i++) {
        int y;
        cin >> y;
        if (x < y) {
            cout << i + 1;
            return;
        }
    }
    cout << -1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
