#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    for (int i = 3; i <= n; i++) {
        if (n % i || (i % 2 == 0 && i != 4)) continue;
        for (int j = 0; j < n / i; j++) {
            bool ok = 1;
            for (int k = 0; k < i; k++) {
                if (!a[k * (n / i) + j]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}
