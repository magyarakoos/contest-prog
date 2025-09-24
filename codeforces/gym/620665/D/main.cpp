#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using point = array<int, 2>;

void solve() {
    map<point, int> m;
    int n;
    cin >> n;
    while (n--) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        u -= x;
        v -= x;
        m[{u / gcd(u, v), v / gcd(u, v)}]++;
    }
    for (auto [p, x] : m)
        cout << p[0] << " " << p[1] << " = " << x << "\n";
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
}
