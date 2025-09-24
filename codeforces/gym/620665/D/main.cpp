#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using point = array<int, 2>;

void solve() {
    map<point, int> s;
    int n;
    cin >> n;
    while (n--) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        u -= x;
        v -= x;
        s[{u / gcd(u, v), v / gcd(u, v)}]++;
    }
    for (point p : s) cout << p[0] << " " << p[1] << "\n";
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
}
