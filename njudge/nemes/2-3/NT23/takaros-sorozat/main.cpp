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
    for (int i = 1; i < n; i++) { p1 += a[i - 1] && !a[i]; }
    cout << p1 << "\n0\n";
}
