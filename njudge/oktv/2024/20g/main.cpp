#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        t[i] = max(t[i], t[i - 1]);
    }
    t.push_back(2e9);
    while (q--) {
        int m;
        cin >> m;
        int i =
            upper_bound(t.begin(), t.end(), m) - t.begin();
        cout << i << "\n";
    }
}
