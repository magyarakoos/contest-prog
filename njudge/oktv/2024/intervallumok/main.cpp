#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    vector<int> d(n - 1);
    for (int i = 1; i < n; i++) {
        d[i - 1] = a[i] - a[i - 1];
    }
    for (int x : d) cout << x << " ";
    cout << "\n";
}
