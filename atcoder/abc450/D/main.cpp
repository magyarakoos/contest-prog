#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> s;
    for (int& x : a) {
        cin >> x;
        s.insert(x % k);
    }
    vector<int> b, mid, edge;
    for (int x : s) b.push_back(x);
    int m = b.size();
    if (m % 2) {
        mid.push_back(b[m / 2]);
    } else {
        mid.push_back(b[m / 2 - 1]);
        mid.push_back(b[m / 2]);
    }
    edge.push_back(b[0]);
    edge.push_back(b[m - 1]);
    int result = 0;
    for (int x : mid) {
        for (int y : edge) {
            result =
                max(result, min(abs(x - y),
                                min(x, y) + k - max(x, y)));
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
