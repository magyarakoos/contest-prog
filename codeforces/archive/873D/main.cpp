#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(int n, int k) {
    for (int i = n / 2; i > 0; i--) cout << i << " ";
    if (n > 1) solve(n - n / 2, k - n / 2 * 2 + 1);
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    if (k % 2 == 0 || k >= 2 * n) {
        cout << "-1\n";
    } else {
        solve(n, k);
    }
}
