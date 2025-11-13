#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    int l = 0, r = 0, sum = 0, result = 0;
    while (r < n) {
        while (r < n && sum + a[r] <= p) sum += a[r++];
        result = max(result, r - l);
        sum -= a[l++];
    }
    cout << result << "\n";
}
