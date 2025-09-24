#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve() {
    map<array<int, 2>, int> m;
    int n;
    cin >> n;
    while (n--) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        u -= x;
        v -= y;
        m[{u / gcd(u, v), v / gcd(u, v)}]++;
    }
    int result = 0;
    for (auto [p, x] : m) {
        result += x * m[{-p[0], -p[1]}];
    }
    cout << result / 2 << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
}
