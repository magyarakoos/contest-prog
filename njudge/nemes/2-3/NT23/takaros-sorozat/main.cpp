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
    int p1a = 0, p1b = 0;
    bool z_found = 0, o_found = 0;
    for (int i = n - 1; i >= 0; i--) {
        z_found |= !a[i];
        p1a += z_found & a[i];
    }
    for (int i = 0; i < n; i++) {
        o_found |= a[i];
        p1b += o_found & !a[i];
    }
    cout << min(p1a, p1b) << "\n0\n";
}
