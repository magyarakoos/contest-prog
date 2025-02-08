#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    vector<int> a(3);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    do {
        if (a[0] * a[1] == a[2]) {
            cout << "Yes\n";
            return;
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << "No\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
