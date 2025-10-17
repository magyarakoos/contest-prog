#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    map<int, int> m;
    int l = 0, result = 1e9;
    for (int r = 0; r < n; r++) {
        m[a[r]]++;
        while (l < r && m.size() == c) {
            if (m[a[l]] == 1) break;
            m[a[l]]--;
            l++;
        }
        if (m.size() == c) {
            result = min(result, r - l + 1);
        }
    }
    cout << result << "\n";
}
