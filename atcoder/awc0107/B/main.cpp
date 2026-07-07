#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + m);
    for (int& x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    int result = 0;
    for (int i = 0; i < k; i++) result += a[i];
    cout << result << "\n";
}
