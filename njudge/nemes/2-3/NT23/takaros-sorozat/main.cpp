#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<bool> a(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = c == '1';
    }
    int p1 = 0;
    bool z_found = 0;
    for (int i = n - 1; i >= 0; i--) {
        z_found |= !a[i];
        p1 += z_found & a[i];
    }
    cout << p1 << "\n0\n";
}
