#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(400'001);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[l - 1]++;
        a[r]--;
    }
    int result = a[0];
    for (int i = 1; i <= 400'000; i++) {
        a[i] += a[i - 1];
        result = max(result, a[i]);
    }
    cout << result << "\n";
}
