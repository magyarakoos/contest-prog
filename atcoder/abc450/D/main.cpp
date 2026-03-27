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
    while (1) {
        for (int x : s) cout << x << " ";
        cout << endl;
        sleep(1);
        int l = *s.begin();
        int r = *s.rbegin();
        if (r - l > l + k - r) {
            cout << l << " " << l + k << endl;
            s.erase(l);
            s.insert(l + k);
        } else {
            break;
        }
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
