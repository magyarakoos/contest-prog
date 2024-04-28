#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

constexpr ll INF = 1e18;

#define cases 0
void solve() {
    int U, V, T, D;
    cin >> U >> V >> T >> D;
    vector<int> a(T), b(T), c(T);
    a[0] = U;
    for (int i = 1; i < T; i++) {
        a[i] = a[i - 1] + D;
    }
    b[T - 1] = V;
    for (int i = T - 2; i >= 0; i--) {
        b[i] = b[i + 1] + D;
    }
    int res = 0;
    for (int i = 0; i < T; i++) {
        res += min(a[i], b[i]);
    }
    cout << res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
