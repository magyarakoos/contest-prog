#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n >> n;
    vector<int> a(n), b;
    for (int& x : a) cin >> x;
    vector<bool> point(n);
    for (int i = 0; i < n; i++) {
        if (b.empty() || b.back() <= a[i]) {
            b.push_back(a[i]);
        } else {
            int j = upper_bound(b.begin(), b.end(), a[i]) -
                    b.begin();
            point[j] = 1;
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) result += point[i];
    cout << result << "\n";
}
