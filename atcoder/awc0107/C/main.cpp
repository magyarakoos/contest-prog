#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<pair<array<int, 2>, string>> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        a[i] = {{x, -i}, s};
    }
    sort(a.begin(), a.end());
    while (q--) {
        int x;
        cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
    }
}
